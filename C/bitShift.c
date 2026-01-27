/******************************************************************************

    Author: Matthew Sliman
    Date: 1/26/2026
    Efforts: 10 Minutes
    Purpose: This program takes the integer x (initialized at 1), and that integer's 
    bits are shifted left iterativley using a for loop with the condition that x is
    not equal to 0.

*******************************************************************************/
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x = 1;
    int condition = 1;
    
    for(int n = 0; condition; ++n){

        if (x != 0)
            printf("%d: %u\n", n, x);
        else
            condition = 0;
        
        x = x << 1;
    }

    return 0;
}