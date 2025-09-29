#include "helpers0.h"
#include <string.h>


//Function to print out a single argument to the screen
int printArg(char * arg_str, int pos){

	//Insert your code here
    // am i getting the vector of the argument string?
    // printf("position: %d\n", pos);
    // printf("argument: %s\n", arg_str);
    printf("argv[%d]: %s\n", pos, arg_str);
    size_t length = strlen(arg_str);
    
    return length;
}
