#include "hw0.h"
#include "helpers0.h"
#include <string.h>

int main (int argc, char *argv[])
{
    
	// printf("Hello ICS53 student!\n"); 
    // printArg("sample", 0); // supposed to print argv[0]: sample
    size_t length = 0; // is this initialized?
    
    printf("argv[0]: %s\n", argv[0]); // printing the first one always
    
    // printArg(argv[1], 1);
    // argc = ./bin/hw0 a b c d 
    // index = [0]     [1][2]{3][4]
    for(int i = 1; i < argc; i++){
        length += printArg(argv[i], i);
    }
    
    printf("Total characters: %zu\n", length);
	return 0;
}
