#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LOG_READER_PREFERENCE "logs/reader_preference.log"
#define LOG_WRITER_PREFERENCE "logs/writer_preference.log"

typedef enum {
    TEST_CASE_1,
    TEST_CASE_2
} TestCase;

typedef enum {
    EVENT_READER_BEGIN,
    EVENT_READER_READ,
    EVENT_READER_END,
    EVENT_WRITER_BEGIN,
    EVENT_WRITER_INCREMENT,
    EVENT_WRITER_END,
    EVENT_HEADER,
    EVENT_UNKNOWN
} EventType;

typedef struct {
    TestCase test_case;
    bool valid;
    char message[1024];
} TestResult;

// Function to trim newline and carriage return characters
void trim_newline(char* str) {
    size_t len = strlen(str);
    while(len > 0 && (str[len-1] == '\n' || str[len-1] == '\r')) {
        str[len-1] = '\0';
        len--;
    }
}

// Function to parse test case from header line
TestCase parse_test_case(char* line) {
    if (strstr(line, "Test Case 1")) {
        return TEST_CASE_1;
    } else if (strstr(line, "Test Case 2")) {
        return TEST_CASE_2;
    } else {
        // Default to unknown, though in this context it's either Test1 or Test2
        return TEST_CASE_1; // Default
    }
}

// Function to parse a single line and return event type
EventType parse_event(char* line) {
    if (strstr(line, "Reader") && strstr(line, "begins reading")) {
        return EVENT_READER_BEGIN;
    } else if (strstr(line, "reads counter as")) {
        return EVENT_READER_READ;
    } else if (strstr(line, "finished reading")) {
        return EVENT_READER_END;
    } else if (strstr(line, "Writer") && strstr(line, "is writing")) {
        return EVENT_WRITER_BEGIN;
    } else if (strstr(line, "increments counter to")) {
        return EVENT_WRITER_INCREMENT;
    } else if (strstr(line, "finished writing")) {
        return EVENT_WRITER_END;
    } else if (strstr(line, "=== Test Case")) {
        return EVENT_HEADER;
    } else {
        return EVENT_UNKNOWN;
    }
}

// Function to analyze a single log file
TestResult analyze_log(const char* filepath) {
    FILE* fp = fopen(filepath, "r");
    if (fp == NULL) {
        TestResult result;
        result.valid = false;
        snprintf(result.message, sizeof(result.message), "Cannot open log file: %s", filepath);
        return result;
    }

    TestResult result;
    result.valid = true;
    strcpy(result.message, "The log meets the expectations.");

    char line[512];
    TestCase current_test_case = TEST_CASE_1;
    
    // State variables
    int active_readers = 0;
    bool writer_active = false;
    bool writer_waiting = false; // Only relevant for Test Case 2

    while (fgets(line, sizeof(line), fp)) {
        trim_newline(line);
        EventType event = parse_event(line);

        if (event == EVENT_HEADER) {
            current_test_case = parse_test_case(line);
            // Reset state for new test case
            active_readers = 0;
            writer_active = false;
            writer_waiting = false;
            continue;
        }

        switch(event) {
            case EVENT_READER_BEGIN:
                if (current_test_case == TEST_CASE_2 && writer_waiting) {
                    // Low-priority reader begins reading while a high-priority writer is waiting, which is a violation
                    result.valid = false;
                    snprintf(result.message, sizeof(result.message),
                        "Violation: Low-priority reader begins reading while a high-priority writer is waiting. Line: %s", line);
                    fclose(fp);
                    return result;
                }
                if (writer_active) {
                    // Reader begins reading while a writer is active, which violates mutual exclusion
                    result.valid = false;
                    snprintf(result.message, sizeof(result.message),
                        "Violation: Reader begins reading while a writer is active. Line: %s", line);
                    fclose(fp);
                    return result;
                }
                active_readers++;
                break;
            case EVENT_READER_END:
                if (active_readers <= 0) {
                    result.valid = false;
                    snprintf(result.message, sizeof(result.message),
                        "Violation: Reader ends reading with no active readers. Line: %s", line);
                    fclose(fp);
                    return result;
                }
                active_readers--;
                break;
            case EVENT_WRITER_BEGIN:
                if (active_readers > 0 || writer_active) {
                    // Writer begins writing while there are active readers or another writer, violating mutual exclusion
                    result.valid = false;
                    snprintf(result.message, sizeof(result.message),
                        "Violation: Writer begins writing while there are active readers or a writer. Line: %s", line);
                    fclose(fp);
                    return result;
                }
                writer_active = true;
                if (current_test_case == TEST_CASE_2) {
                    writer_waiting = false; // Writer is no longer waiting, as it has started writing
                }
                break;
            case EVENT_WRITER_END:
                if (!writer_active) {
                    result.valid = false;
                    snprintf(result.message, sizeof(result.message),
                        "Violation: Writer ends writing with no active writer. Line: %s", line);
                    fclose(fp);
                    return result;
                }
                writer_active = false;
                break;
            case EVENT_WRITER_INCREMENT:
                // No state check
                break;
            case EVENT_READER_READ:
                // No state check
                break;
            case EVENT_UNKNOWN:
            default:
                // Ignore unknown events
                break;
        }

        // Additional checks for Test Case 2
        if (current_test_case == TEST_CASE_2) {
            if (event == EVENT_WRITER_BEGIN) {
                // Mark high-priority writer as active
                writer_active = true;
            }
            if (event == EVENT_WRITER_END) {
                writer_active = false;
            }
            // If a high-priority writer is waiting, mark it
            if (event == EVENT_WRITER_BEGIN) {
                // In Test Case 2, all writers are high priority
                // So when a writer begins, it implies that any subsequent low-priority readers should wait
                // This is handled in the EVENT_READER_BEGIN case above
            }
        }
    }

    // Final state checks
    if (active_readers != 0) {
        result.valid = false;
        snprintf(result.message, sizeof(result.message),
            "Violation: Remaining active readers at the end. Active readers count: %d", active_readers);
    }

    if (writer_active) {
        result.valid = false;
        snprintf(result.message, sizeof(result.message),
            "Violation: Remaining active writer at the end.");
    }

    fclose(fp);
    return result;
}

int main() {
    TestResult reader_pref = analyze_log(LOG_READER_PREFERENCE);
    TestResult writer_pref = analyze_log(LOG_WRITER_PREFERENCE);

    printf("\n=== Analysis Results ===\n\n");

    printf("Test Case 1: All readers are high priority, all writers are low priority\n");
    printf("Result: %s\n", reader_pref.valid ? "Pass" : "Fail");
    if (!reader_pref.valid) {
        printf("Reason: %s\n", reader_pref.message);
    }
    printf("\n");

    printf("Test Case 2: All writers are high priority, all readers are low priority\n");
    printf("Result: %s\n", writer_pref.valid ? "Pass" : "Fail");
    if (!writer_pref.valid) {
        printf("Reason: %s\n", writer_pref.message);
    }
    printf("\n");

    if (reader_pref.valid && writer_pref.valid) {
        printf("All logs conform to the expected priority scheduling rules.\n");
        return 0;
    } else {
        printf("Some logs do not conform to the expected priority scheduling rules, please check the log files.\n");
        return 1;
    }
}