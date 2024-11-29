#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function declarations
int validateFloatingPoint(const char *text);
void filterNumericData(const char *sourceFile, const char *destinationFile);

int main() {
    const char *sourceFile = "raw_numbers.txt";
    const char *destinationFile = "filtered_numbers.txt";

    filterNumericData(sourceFile, destinationFile);

    return 0;
}

// This function examines a string to determine if it represents a valid floating-point number
int validateFloatingPoint(const char *text) {
    char *remainingText;
    strtod(text, &remainingText); // The function attempts to convert the string to a double
    return (*text != '\0' && *remainingText == '\0'); // It checks if the entire string was successfully parsed
}

// This function processes the input file, extracting valid floating-point numbers
void filterNumericData(const char *sourceFile, const char *destinationFile) {
    FILE *source = fopen(sourceFile, "r");
    FILE *destination = fopen(destinationFile, "w");
    char textBuffer[100];
    int errorCount = 0;

    // The function verifies successful file opening
    if (source == NULL || destination == NULL) {
        perror("File access error");
        exit(EXIT_FAILURE);
    }

    // It processes the file content
    while (fscanf(source, "%s", textBuffer) != EOF) {
        if (validateFloatingPoint(textBuffer)) {
            fprintf(destination, "%s\n", textBuffer); // Valid numbers are written to the output
        } else {
            errorCount++; // The count of invalid entries is incremented
        }
    }

    // It checks for any read errors
    if (ferror(source)) {
        perror("File read error");
        fclose(source);
        fclose(destination);
        exit(EXIT_FAILURE);
    }

