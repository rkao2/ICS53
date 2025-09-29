#include "hw0.h"
#include "helpers0.h"
#include <string.h>

int main (int argc, char *argv[])
{
    
	// printf("Hello ICS53 student!\n"); 
    // printArg("sample", 0); // supposed to print argv[0]: sample
    size_t length = 0; // is this initialized?
    
    // printArg(argv[0], 0);
    // printArg(argv[1], 1);
    for(int i = 0; i < argc; i++){
        length += printArg(argv[i], i);
    }
    
    printf("Total characters: %zu\n", length);
	return 0;
}
