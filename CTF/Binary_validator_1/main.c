#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_NOT_ALLOWED 1000

// Function to trim newline and carriage return characters
void trim_newline(char *str) {
    size_t len = strlen(str);
    while(len > 0 && (str[len-1] == '\n' || str[len-1] == '\r')) {
        str[len-1] = '\0';
        len--;
    }
}

// Function to check if file name is in not_allowed list
int is_not_allowed(char *filename, char not_allowed[][MAX_FILENAME_LEN], int not_allowed_count) {
    for(int i = 0; i < not_allowed_count; i++) {
        if(strcmp(filename, not_allowed[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *f_allowed = fopen("allowed", "rb");
    FILE *f_not_allowed = fopen("not_allowed", "rb");
    if(!f_allowed || !f_not_allowed) {
        fprintf(stderr, "Error opening allowed or not_allowed file.\n");
        return 1;
    }

    // Read not_allowed file names into array
    char not_allowed[MAX_NOT_ALLOWED][MAX_FILENAME_LEN];
    int not_allowed_count = 0;
    char line[MAX_FILENAME_LEN];
    int line_num = 0;
    while(fgets(line, sizeof(line), f_not_allowed)) {
        line_num++;
        if(line_num <= 5) continue; // Skip first 5 lines
        trim_newline(line);
        if(strlen(line) == 0) continue;
        strncpy(not_allowed[not_allowed_count], line, MAX_FILENAME_LEN);
        not_allowed_count++;
    }
    fclose(f_not_allowed);

    // Read allowed file names and process first 4
    int allowed_count = 0;
    line_num = 0;
    while(fgets(line, sizeof(line), f_allowed) && line_num < 6) {
        line_num++;
        if(line_num <= 3) continue; // Skip first 3 lines
        trim_newline(line);
        if(strlen(line) == 0) continue;

        if(is_not_allowed(line, not_allowed, not_allowed_count)) {
            printf("Skipping %s (not allowed)\n", line);
            continue;
        }

        // Open and print file contents
        FILE *f = fopen(line, "rb");
        if(!f) {
            printf("Could not open file: %s\n", line);
            continue;
        }
        printf("Contents of %s:\n", line);
        int c;
        while((c = fgetc(f)) != EOF) {
            putchar(c);
        }
        printf("\n--- End of %s ---\n", line);
        fclose(f);
    }
    fclose(f_allowed);

    return 0;
}
