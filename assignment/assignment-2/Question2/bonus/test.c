#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int is_punctuation(char c) {
    return (c == ':' || c == ',' || c == '-' || c == '.' || c == ';' || c == '!' || c == '?');
}

void normalize_line(const char *input, char *output) {
    int i = 0, j = 0;
    char prev_char = '\0';
    
    while (input[i] != '\0' && input[i] != '\n') {
        if (isspace((unsigned char)input[i])) {
            while (isspace((unsigned char)input[i])) {
                i++;
            }
            if (is_punctuation(input[i])) {
                continue;
            }
            if (j > 0 && output[j-1] != ' ') {
                output[j++] = ' ';
            }
        }
        else {
            if (is_punctuation(input[i])) {
                if (j > 0 && output[j-1] == ' ') {
                    j--; 
                }
                output[j++] = input[i];
                i++;
                while (isspace((unsigned char)input[i])) {
                    i++;
                }
                if (input[i] != '\0' && input[i] != '\n' && !is_punctuation(input[i])) {
                    output[j++] = ' ';
                }
            }
            else {
                output[j++] = input[i++];
            }
        }
        prev_char = input[i-1];
    }
    if (j > 0 && output[j-1] == ' ') {
        j--;
    }
    output[j] = '\0';
}

int main(int argc, char *argv[]) {

    FILE *file1 = fopen("output.log", "r");
    if (!file1) {
        perror("Error opening first file");
        return EXIT_FAILURE;
    }

    FILE *file2 = fopen("expected-result.log", "r");
    if (!file2) {
        perror("Error opening second file");
        fclose(file1);
        return EXIT_FAILURE;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    char norm1[MAX_LINE_LENGTH];
    char norm2[MAX_LINE_LENGTH];
    int line_num = 1;
    int consistent = 1;


    int has_content1 = 0, has_content2 = 0;

    if (fgets(line1, sizeof(line1), file1) != NULL) {
        has_content1 = 1;
        rewind(file1);
    }

    if (fgets(line2, sizeof(line2), file2) != NULL) {
        has_content2 = 1;
        rewind(file2);
    }

    if (!has_content1 && !has_content2) {
        printf("Both files are empty.\n");
        fclose(file1);
        fclose(file2);
        return EXIT_SUCCESS;
    }

    if (!has_content1 || !has_content2) {
        printf("Error. One of the files is empty while the other is not.\n");
        fclose(file1);
        fclose(file2);
        return EXIT_FAILURE;
    }


    while (fgets(line1, sizeof(line1), file1) != NULL &&
           fgets(line2, sizeof(line2), file2) != NULL) {

        normalize_line(line1, norm1);
        normalize_line(line2, norm2);

        if (strcmp(norm1, norm2) != 0) {
            printf("Mismatch at line %d:\n", line_num);
            printf("output.log: %s\n", norm1);
            printf("expected-result.log: %s\n", norm2);
            consistent = 0;
            break;
        }

        line_num++;
    }

    if (consistent) {
        if ((fgets(line1, sizeof(line1), file1) != NULL) ||
            (fgets(line2, sizeof(line2), file2) != NULL)) {
            printf("Error. The output.log is not consistent with expected-result.log\n");
            consistent = 0;
        }
    }

    if (consistent) {
        printf("The output.log is consistent with expected-result.log\n");
    } else {
        printf("Error. The output.log is not consistent with expected-result.log\n");
    }

    fclose(file1);
    fclose(file2);
    return EXIT_SUCCESS;
}
