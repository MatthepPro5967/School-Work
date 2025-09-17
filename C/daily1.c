/*
    Author: Matthew Sliman
    Date: 09/10/2025

    Output: 
    
    This program has the executable name: ./a.out
    That is all

    When I ran the program, the IDE took my c file and made it into an executable. When executing this file,
    the only argument variable passed in was the directory of the executable (no other arguments passed in). Once this
    is ran and passed into the main, I use the printf function to print 2 outputs. At the end of the first one I have
    the format specifier %s which stands for String and then a \n which is an escape sequence for new line. I then pass
    the argument of argv[0] which has a type of char* and an index of 0 that points to the first character of the string
    containing my executable file. argv[0] is a string not just a single character. I then return a value of 0 back to the OS

*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("This program has the executable name: %s\n", argv[0]);
    printf("That is all\n");
    return 0;
}
