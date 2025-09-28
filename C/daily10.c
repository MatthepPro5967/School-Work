/***********************************************
    
    Author: Matthew Sliman
    Date: 09/28/2025
    Purpose: This program prompts the user to enter a
    negative integer and the clears the buffer if the user
    entered any additional information in the input. It then 
    validates user input by using a while loop that checks if
    the number of successful conversions is not one or if the
    number the user entered is not negative. The first conditional
    makes sure that if the value the user enters is not a number
    and that number gets randomly initialized, that it won't affect
    anything. The second conditional just checks to make sure the user
    input (in the case that its a number of type int) is actually negative.
    Time Spent: 5-10 minutes

***********************************************/
#include <stdio.h>

void clearBuffer(void);

int main()
{
    int negNum;
    int noc;
    
    printf("Enter a negative integer: ");
    noc = scanf("%d", &negNum);
    clearBuffer();
    
    while(noc != 1 || negNum >= 0){
        printf("I'm sorry, you must enter a negative integer less than zero: ");
        noc = scanf("%d", &negNum);
        clearBuffer();
    }
    
    printf("The negative integer was: %d", negNum);
        
    return 0;
}

void clearBuffer(void){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
}
