// Implement all helper functions for hw1 in this file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "helpers1.h"

// Implement all helper functions for hw1 in this file

// process text as characters by characters->count all chars
// detect new lines to count lines and measure line lengths
// detect trailing whitespaces


// start with opening the input file, and then use a loop to read it
// create a method to calculate teh statistics

/*
 * 
 * call the different format options, maybe do a switch? 
 * for each format option that is called, call the stats function on it, to get the calculated stats for that function
 * print it to an stdout file before calling teh stats function
 * edge case: what if none of the format options are called
 * edge case: what if all of them are called ???
 *
  */


void titlePrompt(){
    fprintf(stderr, "Usage: ./formattxt -L | -U | -T | -t | -R SYMBOLS [-W Word]\n");
}

// handles upper and lower case (-U & -L)
int up_or_down(int c, int upper, int lower) {
    if (upper) { return toupper(c);}
    if (lower) { return tolower(c);}
    return c;
}

// -T : capitalizes the first letter in the word
int cap_first(int c, int *newWord){

    if(isspace(c)){
        *newWord = 1; // if the first character is a whitespace, return
        return c;
    }

    if(*newWord && isalpha(c)){
        *newWord = 0;
        return toupper(c);
    }

    *newWord = 0;
    return tolower(c);
}

// -t : format the input for terminal printing <= 80 characters per line excluding new line char
int fixed_length(int c, int *curr_line_length){
    int max_length = 80;
    (*curr_line_length)++;

    if (c == '\n') { 
        *curr_line_length = 0; 
        return c; }

    if (*curr_line_length > max_length) {
        putchar('\n');
        *curr_line_length = 1;
    }
    return c;

    /** 
    static int line_length = 0;

    // for the chars in the option, if it is <= max_length, go to newline
    if (c == '\n') {
        // reset line length when input already has a newline
        line_length = 0;
        return c;
    }

    line_length++;

    if (line_length > max_length) {
        // reset counter, current char is first on new line
        putchar('\n');
        line_length = 1;
    }

    return c;
    */
}

// -R : removes the command line letters after the option
int should_remove(int c, const char *char_to_remove){
    return(strchr(char_to_remove, c) != NULL);
}

// handle the statistics
void stats(int c, int *char_count, int *word_count, int *line_count,
                 int *curr_line_length, int *max_line_length) {

    static int in_word = 0;

     if(c == EOF){
        if(in_word){
            (*word_count)++;
            in_word = 0;
        }
        if(*curr_line_length >= 0) {
            (*line_count)++;
            if(*curr_line_length > *max_line_length){
                *max_line_length = *curr_line_length;
            }
            *curr_line_length = 0;
        }
        return;
    }

    (*char_count)++;
    
    if(c == '\n'){
        
        if (in_word){
            (*word_count)++;
            in_word = 0;
        } 

    // if it's the end of the line, then make it the longest line
        if(*curr_line_length > *max_line_length){
            *max_line_length = *curr_line_length;
        }

        (*line_count)++; // update line count
        *curr_line_length = 0; // reset the next line
        in_word = 0; // signals end of the word

    } else {
        (*curr_line_length)++; 
        if(isspace(c)){
            if(in_word){
                (*word_count)++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    
}


char formattxt(FILE *fptr, const char *option) {


    FILE *outputFile = fopen("student_stderr.txt", "w");
    if(outputFile == NULL){
        printf("Error opening output file!\n");
        return 1;
    }

    int upper = 0; 
    int lower = 0;
    int title = 0;
    int firstChar = 0;
    int removeChar = 0;
    int endError = 0;

    
    if(strcmp(option, "-h") == 0){ titlePrompt(); }
    else if(strcmp(option, "-U") == 0) upper = 1;
    else if(strcmp(option, "L") == 0) lower = 1;
    else if (strcmp(option, "-T") == 0) title = 1;
    else if (strcmp(option, "-t") == 0) firstChar = 1;
    else if (strcmp(option, "-R") == 0) removeChar = 1;
    else if(strcmp(option, "-P") == 0) endError = 1;

    int c;
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    int max_line_length = 0;
    int curr_line_length = 0;
    int new_word = 1;


    while ((c = getc(fptr)) != EOF) {
        // apply transformations

        if(upper || lower) c = up_or_down(c, upper, lower);
        if(title) c = cap_first(c, &new_word);
        if(firstChar) c = fixed_length(c, &curr_line_length);
        if(removeChar && should_remove(c, option)) continue;

        /*
        if(strcmp(option, "-h") == 0){ titlePrompt(); }
        else if(strcmp(option, "-U") == 0 || strcmp(option, "-L") == 0) {
            c = up_or_down(c, option);
        }
        else if (strcmp(option, "-T") == 0) {c = cap_first(c); }
        else if (strcmp(option, "-t") == 0) {c = fixed_length(c, &curr_line_length);}
        else if (strcmp(option, "-R") == 0) {
            if(should_remove(c, option)){ continue;} // confused what R does
        } else if (strcmp(option, "-W") == 0){
            printf("Option -W not implemented yet\n");
        }
        else if(strcmp(option, "-P") == 0) { // option P 
            printf("ERROR!, no input file recieved\n");
        }
        */

        // print transformed char
        putchar(c);
        // printf("%c", result);

        // update stats
        stats(c, &char_count, &word_count, &line_count,
                    &curr_line_length, &max_line_length);
    }

  

    stats(EOF, &char_count, &word_count, &line_count,
            &curr_line_length, &max_line_length);

    fprintf(outputFile, "%d\n", char_count); // char count
    fprintf(outputFile, "%d\n", line_count); // line count
    fprintf(outputFile, "%d\n", word_count); // word count
    fprintf(outputFile, "%d\n", max_line_length); // length

    if (fptr != stdin) fclose(fptr);
    fclose(outputFile);
    
    return 0;
}