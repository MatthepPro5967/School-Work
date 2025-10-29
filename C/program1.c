/******************************************************************************

    Author: Matthew Sliman
    Date: 10/28/25
    Purpose: Program implements Collatz Conjecture algorithm. First starts by
    using a function to get the lower and upper ranges to run the algorithm on.
    Then calls another function with those two numbers as arguments which loops
    through each number in the range (inclusive). For each iteration, the Collatz
    Conjecture of the number (if n is odd mulitply by 3 and add 1, if n is even
    divide by 2) is found through another function. That is then set as an argument
    along with the iteration count variable for formatting purposes (both printing
    out numbers and keeping track of columns).
    Time Spent: 30 Minutes

*******************************************************************************/
#include <stdio.h>

const int LowerStartingNum = 1;
const int UpperStartingNum = 1000;
const int UpperEndingNum = 10000;
const int COLUMNS = 7;

void clearBuffer(void); // clears buffer for user input
int getInteger(int, int); // gets user input for ranges
void format(int, int, int); // prints with respective spacing and newlines
int collatzConjecture(int); // does algorithm
void rangeLoop(int, int); // loops through lower and upper range to do algorithm

int main()
{
    int lowerRange = getInteger(LowerStartingNum, UpperStartingNum);
    int higherRange = getInteger(lowerRange, UpperEndingNum);

    rangeLoop(lowerRange, higherRange);

    return 0;
}

void clearBuffer(void){
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}

int getInteger(int low, int high){
    int input;
    
    if (low == LowerStartingNum)
        printf("Enter a starting point: ");
    else
        printf("Enter an ending point: ");

    scanf("%d", &input);
    clearBuffer();
    
    while (input <= low || input >= high) {
        printf("Invalid number. Input must be between (%d and %d).\n", low, high);
        printf("Re-enter number: ");
        
        scanf("%d", &input);    
        clearBuffer();
    }
    
    return input;
}

void format(int number, int result, int count){
    printf("%5d:%-5d", number, result);
    if(count % COLUMNS == 0)
        printf("\n");
}

int collatzConjecture(int number){
    int count = 0;
    
    while (number != 1){
        if (number % 2)
            number = number * 3 + 1;
        else
            number /= 2;
        ++count;
    }
    
    return count;
}

void rangeLoop(int low, int high){
    int result; // keep track of result for each iteration
    int count = 1; // keep track of columns
    
    for (int n = low; n <= high; ++n) {
        result = collatzConjecture(n);
        format(n, result, count);
        ++count;
    }
}