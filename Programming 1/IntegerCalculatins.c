/******************************************************************************

Variables - Integer Calculations
Guided practice

*******************************************************************************/
#include <stdio.h>

int main()
{
    //declare and initialize variables
    int a = 10, b = 22, c = 14, temp;
    
    //calculations and output
    //sum of all variables
    temp = a + b + c;
    printf("%i + %i + %i = %i\n", a,b,c,temp);
    
    //2a + b
    temp = 2 * a + b;
    printf("2 * %i + %i = %i\n", a,b,temp);
   
    //3b - c
    temp = 3 * b - c;
    printf("3 * %i - %i = %i\n", b,c,temp);
   
    //4c - 2a
    temp = 4 * c - 2 * a;
    printf("4 * %i - 2 * %i = %i\n", c,a,temp);
   
    //5b + 3a - c
    temp = 5 * b + 3 * a - c;
    printf("5 * %i + 3 * %i - %i = %i\n", b,a,c,temp);
   
    //(3b - 2c)/a Quotient and Remainder
    temp = (3 * b - 2 * c)/a;
    printf("(3 * %i - 2 * %i)/%i    Quotient = %i", b,c,a,temp);
    temp = (3 * b - 2 * c)%a;
    printf("    Remainder = %i\n", temp);


    return 0;
}
