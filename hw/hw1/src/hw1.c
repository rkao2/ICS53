// Rachel Kao
// rkao4

#include "../include/hw1.h"
#include "../include/helpers1.h"
// You may define any helper functions you want. Place them in helpers.c/.h

// Main program
int main(int argc, char *argv[]) {
    // Insert your hw1 code here
    // formattxt reformats ASCII characters : 
        // total # of characters
        // total # lines
        // total # words, (defined as any non-zero length sequence of characters delimited by one of more whitespace characters )
        // length of longest line (in characters)

    if (argc < 2) {
        printf("Error: missing arguments.\n");
        titlePrompt();
        return 1;
    }

    const char *option = argv[1];
    FILE *fptr = NULL;

    // Check if a filename was provided
    if (argc >= 3) {
        fptr = fopen(argv[2], "r");
        if (!fptr) {
            perror("Error opening input file");
            return 1;
        }
    } else {
        // No filename, use stdin (input redirection)
        fptr = stdin;
    }

    // Call your formattxt function, passing the FILE* instead of filename
    formattxt(fptr, option);

    return 0;
}
