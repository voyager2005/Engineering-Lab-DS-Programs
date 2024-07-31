#include <stdio.h>
#include <string.h>
#define MAX_LEN 500

// Function prototype
void copyString(char *source, char *destination);

void main() {
    // declaration and initializatoin
    char source[MAX_LEN];
    char destination[MAX_LEN]; // Make sure this is large enough to hold the source string

    // reading the source string from the user
    printf("Please enter the sentence: ");
    gets(source);


    copyString(source, destination);
    printf("Copied String: %s\n", destination);
}

// Recursive function to copy string
void copyString(char *source, char *destination) {
    *destination = *source;
    if (*source) {
        copyString(source + 1, destination + 1);
    }
}