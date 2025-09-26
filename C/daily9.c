/***********************************************
    Author: Matthew Sliman
    Date: 09/25/2025
    Answer to question: What happens if
    the integer that you type is again big?
    Say 500000? Why is this behavior different
    than what you saw with your daily6?
    
    In daily6, we used recursion to print the numbers, so each time we printed
    a number we added a frame to the stack because the method called itself
    again. This time, we are doing that within a loop which means we are doing
    this iterativley. While it still takes some time, it doesn't take any space
    in the callstack (just keeps updating variables in memory).
     
***********************************************/
#include <stdio.h>

void loop_down_to_zero(int num);
void loop_up_to_int(int num);

int main()
{
    int num;
    
    printf("Please enter a positive integer: ");
    scanf("%d", &num);
    
    loop_down_to_zero(num);
    
    printf("****\n");
    
    loop_up_to_int(num);

    return 0;
}

void loop_down_to_zero(int num){
    while(num >= 0){
        printf("%d\n", num);
        --num;
    }
}

void loop_up_to_int(int num){
    int counter = 0;
    while(num >= counter){
        printf("%d\n", counter);
        ++counter;
    }
}