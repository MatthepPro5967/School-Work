/******************************************************************************

    Author: Matthew Sliman
    Date: 09/22/25
    Purpose: Determine whether a number inputted by the user is even or odd. If 
    the number is even, the number will be divided by 2 and printed. If the number
    is odd, the number will be multiplied by 3 and then 1 will be added.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int number;
    
    printf("Please enter a positive integer: ");
    scanf("%d", &number);
    
    if(number % 2 == 0){
        number /= 2;
    }
    else{
        number = number * 3 + 1;
        printf("true");
    }
    
    printf("The next value of the number is: %d", number);

    return 0;
}
