/******************************************************************************

    Author: Matthew Sliman
    Date: 10/04/2025
    Purpose: This program prompts the user to enter the amount of asterisks they
    want printed to the console. The program then validates if the input is of a
    valud variable type, and then verifies that the number the user enters is 
    in the range 1-79 (including). The program then uses a for loop to print the 
    amount of astrisks the user entered.
    Time Spent: 10 minutes

*******************************************************************************/
#include <stdio.h>

void clearBuffer(void);

int main()
{
    int astNum;
    int noc;
    
    printf("PLease enter the number of asterisks you want in your line: ");
    noc = scanf("%d", &astNum);
    clearBuffer();
    
    while(noc != 1 || (astNum < 1 || astNum > 79) ) {
        printf("I'm sorry, that number is unrecognized or out of range, try [1-79]: ");
        noc = scanf("%d", &astNum);
        clearBuffer();
    }
    
    for(int n = 0; n < astNum; ++n) {
        printf("*");
    }

    return 0;
}

void clearBuffer(void){
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
}
