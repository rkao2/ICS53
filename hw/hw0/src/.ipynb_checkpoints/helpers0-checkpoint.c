#include "helpers0.h"
#include <string.h>


//Function to print out a single argument to the screen
int printArg(char * arg_str, int pos){

	//Insert your code here
    // printing the argument string, and then the length of the argument string?
    printf("argv %d: %s\n", arg_str[pos], arg_str);
    size_t length = strlen(arg_str);
    printf("arg length: %zu\n", length);
	return length;
}
