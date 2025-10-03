// Define all helper functions for hw1 in this file


// helpers0.h
#include<stdio.h>
#include<stdlib.h>

// Implement all helper function headers for this file
char formattxt(FILE *fptr, const char *option, const char *symbol_to_remove);
void titlePrompt();
void titlePromptError();
int up_or_down(int c, int upper, int lower);
int cap_first(int c, int *newWord);
int fixed_length(int c, int *curr_line_length);
int should_remove(int c, int next_char, const char *char_to_remove);
void stats(int c, int *char_count, int *word_count, int *line_count,
                 int *curr_line_length, int *max_line_length);