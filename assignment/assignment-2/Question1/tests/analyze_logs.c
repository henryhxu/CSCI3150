#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LOG_READER_PREFERENCE "logs/reader_preference.log"

typedef enum
{
    EVENT_READER_BEGIN,
    EVENT_READER_READ,
    EVENT_READER_END,
    EVENT_WRITER_BEGIN,
    EVENT_WRITER_INCREMENT,
    EVENT_WRITER_END,
    EVENT_HEADER,
    EVENT_UNKNOWN
} EventType;

typedef struct
{
    bool valid;
    char message[1024];
} TestResult;

// Function to trim newline and carriage return characters
void trim_newline(char *str)
{
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r'))
    {
        str[len - 1] = '\0';
        len--;
    }
}

// Function to parse a single line and return event type
EventType parse_event(char *line)
{
    if (strstr(line, "Reader") && strstr(line, "begins reading"))
    {
        return EVENT_READER_BEGIN;
    }
    else if (strstr(line, "reads counter as"))
    {
        return EVENT_READER_READ;
    }
    else if (strstr(line, "finished reading"))
    {
        return EVENT_READER_END;
    }
    else if (strstr(line, "Writer") && strstr(line, "is writing"))
    {
        return EVENT_WRITER_BEGIN;
    }
    else if (strstr(line, "increments counter to"))
    {
        return EVENT_WRITER_INCREMENT;
    }
    else if (strstr(line, "finished writing"))
    {
        return EVENT_WRITER_END;
    }
    else if (strstr(line, "=== Test Case"))
    {
        return EVENT_HEADER;
    }
    else
    {
        return EVENT_UNKNOWN;
    }
}

// Function to analyze a single log file
TestResult analyze_log(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        TestResult result;
        result.valid = false;
        snprintf(result.message, sizeof(result.message), "Cannot open log file: %s", filepath);
        return result;
    }

    TestResult result;
    result.valid = true;
    strcpy(result.message, "The log meets the expectations.");

    char line[512];

    // State variables
    int active_readers = 0;
    bool writer_active = false;

    while (fgets(line, sizeof(line), fp))
    {
        trim_newline(line);
        EventType event = parse_event(line);

        if (event == EVENT_HEADER)
        {
            // Keep log robust if multiple headers appear.
            active_readers = 0;
            writer_active = false;
            continue;
        }

        switch (event)
        {
        case EVENT_READER_BEGIN:
            if (writer_active)
            {
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
            if (active_readers <= 0)
            {
                result.valid = false;
                snprintf(result.message, sizeof(result.message),
                         "Violation: Reader ends reading with no active readers. Line: %s", line);
                fclose(fp);
                return result;
            }
            active_readers--;
            break;
        case EVENT_WRITER_BEGIN:
            if (active_readers > 0 || writer_active)
            {
                // Writer begins writing while there are active readers or another writer, violating mutual exclusion
                result.valid = false;
                snprintf(result.message, sizeof(result.message),
                         "Violation: Writer begins writing while there are active readers or a writer. Line: %s", line);
                fclose(fp);
                return result;
            }
            writer_active = true;
            break;
        case EVENT_WRITER_END:
            if (!writer_active)
            {
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
    }

    // Final state checks
    if (active_readers != 0)
    {
        result.valid = false;
        snprintf(result.message, sizeof(result.message),
                 "Violation: Remaining active readers at the end. Active readers count: %d", active_readers);
    }

    if (writer_active)
    {
        result.valid = false;
        snprintf(result.message, sizeof(result.message),
                 "Violation: Remaining active writer at the end.");
    }

    fclose(fp);
    return result;
}

int main()
{
    TestResult reader_pref = analyze_log(LOG_READER_PREFERENCE);

    printf("\n=== Analysis Results ===\n\n");

    printf("Test Case 1: All readers are high priority, all writers are low priority\n");
    printf("Result: %s\n", reader_pref.valid ? "Pass" : "Fail");
    if (!reader_pref.valid)
    {
        printf("Reason: %s\n", reader_pref.message);
    }
    printf("\n");

    if (reader_pref.valid)
    {
        printf("The log conforms to the expected locking rules.\n");
        return 0;
    }
    else
    {
        printf("The log does not conform to the expected locking rules, please check the log file.\n");
        return 1;
    }
}