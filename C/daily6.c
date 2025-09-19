/***********************************************
Author: Matthew Sliman
Date: 09/18/2025
Answer to question: When I ran the program, after printing out thousands of numbers, the program was terminated.
I believe this was due to there being too many frames (a stack on the stack) in the callstack which resulted in a stack overflow because there 
wasn't enough memory for the program (which was why it was terminated)
***********************************************/
#include <stdio.h>

void recursive_down_to_zero(int num);
void recursive_up_to_int(int num);

int main(int argc, char *argv[]){
    
    recursive_down_to_zero(10);
    printf("****\n");
    recursive_up_to_int(10);
}


void recursive_down_to_zero(int num){
    if(num < 0)
        return;
    
    printf("%d\n", num);
    recursive_down_to_zero(num - 1);
}

void recursive_up_to_int(int num){
    if(num < 0)
        return;
    
    recursive_up_to_int(num - 1);
    printf("%d\n", num);
}