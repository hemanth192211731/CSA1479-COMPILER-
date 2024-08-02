#include <stdio.h>
#include <ctype.h>
void countCharactersWordsLines(FILE *file, int *charCount, int *wordCount, int *lineCount);

int main() {
    char filename[100];
    FILE *file;
    int charCount = 0, wordCount = 0, lineCount = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }
    countCharactersWordsLines(file, &charCount, &wordCount, &lineCount);
    printf("\nFile: %s\n", filename);
    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);
    fclose(file);

    return 0;
}
void countCharactersWordsLines(FILE *file, int *charCount, int *wordCount, int *lineCount) {
    char c;
    int inWord = 0;

    while ((c = fgetc(file)) != EOF) {
        (*charCount)++;
        if (c == '\n') {
            (*lineCount)++;
        }
        if (isspace(c)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            (*wordCount)++;
        }
    }
}
