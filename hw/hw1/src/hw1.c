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
        titlePromptError();
        return 1;
    }

    const char *option = argv[1];
    const char *symbol_to_remove = argv[2];
    FILE *fptr = stdin;


    if (strcmp(option, "-R") == 0) {
        if (argc < 3) {
            titlePromptError();
            return 1;
        }
        symbol_to_remove = argv[2];
    }

    if(argc >= 3 && strcmp(option, "-R") != 0){
        fptr = fopen(argv[2], "r");
        if (!fptr) {
            fprintf(stderr, "Error opening file\n");
            return 1;
        }
        setvbuf(fptr, NULL, _IONBF, 0);
    }

    // Call your formattxt function, passing the FILE* instead of filename
    formattxt(fptr, option, symbol_to_remove);

    return 0;
}
