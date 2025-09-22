/******************************************************************************

    Author: Matthew Sliman
    Date: 09/22/25
    Purpose: Use recursion to get the output of a binary representation of any nonnegativbe integer.
    Does this by first checking if the number passed in is 0 (for the 0 case). If it's not, then then
    program will recursivley call itself while passing in half of its value. Does that until the value
    is 1, then runs back up the stack and executes everything after the recursive call which is the print
    statement.

*******************************************************************************/
#include <stdio.h>

void print_binary(int num);


int main()
{
    print_binary(43);
    printf("\n");

    return 0;
}

void print_binary(int num){
    if(num == 0){
        printf("0");
        return;
    }
    
    if(num > 1){
        print_binary(num/2);
    }
    
    printf("%d", num % 2);

}


