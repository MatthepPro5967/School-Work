/******************************************************************************

Matthew Sliman
10/12/2023
Looping

*******************************************************************************/
#include <stdio.h>

int main()
{
    //declare variable
    int a, sum = 0;
    
    for(a = 1; a<=10; ++a)
    {
        printf("%3i", a);
    }
    
    printf("\ta = %i\n",a);
    
    for(int b = 1; b<=10; ++b)
    {
        printf("%3i", b);
    }
    
    printf("\n");
    
    for(int b = 1; b<=10; b=b+2)
    {
        printf("%3i", b);
    }
    
    printf("\n");

    for(int b = 5; b<=15; ++b)
    {
        printf("%3i %3i %5i\n", b, 2*b, b*b);
    }
    
    for(int c = 1; c<=10; ++c)
    {
        printf("%3i", c);
        sum = sum + c;
    }
    
    printf("\nThe sum is %i\n", sum);
    

    return 0;
}

