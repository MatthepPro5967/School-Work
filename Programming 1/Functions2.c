/******************************************************************************

Fuctions 2  void - input
Matthew Sliman
11/19/2023
Fill in the function stubs with given directions

*******************************************************************************/
#include <stdio.h>

void EvenOrOdd(int num)
{   //determine and print a statement whether num is even or odd
    //input: num - number to be evaluated
    //returned output: none

    //declare variable
    
    //calculations
    
    //printed output
    if(num % 2 == 0)
        printf("The number (%i) is even\n", num);
    else
        printf("The number (%i) is odd\n", num);
}
void IsGreaterThan(int target, int guess)
{   //compare guess to target to determine if guess > num
    //input: num - number to compare, target - number to compare to
    //returned output: none
    
    //compare and print
    if(guess > target)
        printf("The guess (%i) is greater than the target (%i)\n", guess,target);
    else
        printf("The guess (%i) is not greater than the target (%i)\n", guess,target);
    
}
void IsLessThan(int target, int guess)
{   //compare guess to target to determine if guess < num
    //input: num - number to compare, target - number to compare to
    //returned output: none
    
    //compare and print
    if(guess < target)
        printf("The guess (%i) is less than the target (%i)\n", guess,target);
    else
        printf("The guess (%i) is not less than the target (%i)\n", guess,target);
}
void IsEqualTo(int target, int guess)
{   //compare guess to target to determine if guess = num
    //input: num - number to compare, target - number to compare to
    //returned output: none
    
    //compare and print
    if(guess == target)
        printf("The guess (%i) is equal to the target (%i)\n", guess,target);
    else
        printf("The guess (%i) is not equal to the target (%i)\n", guess,target);
    
}
void Squared(int num)
{   //calculate and print the square of input num 
    //input: num - # to be squared
    //returned output: none

    //declare variable
    int squared;
    //calculations
    squared = num * num;
    //printed output
    printf("The number (%i) squared is %i\n", num,squared);

}
void SumOfIntegers(int max)
{   //calculate and print the sum of 1 to  max values
    //input: max number
    //returned output: none

    //local variables
    int n;
    int total = 0;

    //calculations using a for loop
    for(n = 1; n <= max; ++n)
    {
        total = total + n; 
    }

    //printed output
    printf("The sum of integers (of %i) is %i\n", max, total);
}
    

int main()
{
    SumOfIntegers(100);
    Squared(15);
    IsEqualTo(12,20);
    IsEqualTo(12,12);
    IsLessThan(12, 10);
    IsLessThan(12, 15);
    IsGreaterThan(12,40);
    IsGreaterThan(12,1);
    EvenOrOdd(10);
    EvenOrOdd(15);

    return 0;
}



