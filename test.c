#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  

int main(int argc, char* argv[]) {
    char* filename;
    char ch;
    int count_chars = 0;
    int count_words = 0;
    int is_word = 0;

    if (argc != 3) {
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        // Character count  
        filename = argv[2];
        FILE* file = fopen(filename, "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        while ((ch = fgetc(file)) != EOF) {
            count_chars++;
        }
        fclose(file);
        printf("Character count: %d\n", count_chars);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        // Word count  
        filename = argv[2];
        FILE* file = fopen(filename, "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        while ((ch = fgetc(file)) != EOF) {
            if (isspace(ch) || strchr(", ", ch)) {
                if (is_word) {
                    count_words++;
                    is_word = 0;
                }
            }
            else {
                is_word = 1;
            }
        }
        // Check for the last word  
        if (is_word) {
            count_words++;
        }
        fclose(file);
        printf("Word count: %d\n", count_words);
    }
    else {
        printf("Invalid parameter. Use -c for character count or -w for word count.\n");
        return 1;
    }

    return 0;
}