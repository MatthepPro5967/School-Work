/*************************************************************
Matthew Sliman
01/03/2024
Array Functions Practice 2

**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**********************FUNCTIONS*****************************/


void UpdateOriginalArray(int A[], int max)
{
    //input: integer array A[]
    //Returned value: none
    //Purpose: update the original array with random numbers between 0 and 100
   

    for(int n = 0; n < max; ++n)
    {
        A[n] = (int)(rand()%100)+1; //random number generator 
    }
}
void PrintIntegerArray(int A[], int max)
{
    //input: integer array A[], maximum number of elements to print
	//returned value: none
	//purpose: to print any integer array
	
    int count = 0;
    
    for(int n = 0; n < max; ++n)
    {    
        if(A[n] != 0)
        {
            printf("%5i", A[n]);
            count = count + 1;
        }
            
        if(count == 20 || count == 40 || count == 60)
            printf("\n");
    }
    printf("\n");
}
float AverageIntegerArray(int A[], int max)
{
    //input: integer array A[], maximum number of elements to print
	//returned value: average
	//purpose: to find and return the average of integer array
	
	float sum = 0;;
	float average;
	
	for(int n = 0; n < max; ++n)
	{
	    sum = sum + A[n];
	}
	
	average = sum / max;
	printf("Average = %.4f\n\n", average);
	
	return (average);
}
int AboveOrBelowArray( int A[], int Above[], int Below[], int average, int max)
{
    //input: integer array A[], integer array Above[], integer array Below[], average, maximum number of elements to print
	//returned value: above
	//purpose:to find the numbers and amount of numbers above and below the average
	
    int n, above = 0, below = 0;
    
    for(n = 0; n < max; ++n)
    {
        if(A[n] > average)
        {
            Above[above++] = A[n];
                    
        }
        else if(A[n] < average)
        {
            Below[below++] = A[n];
        }
    }
    
    return (above);
}
int main()
{
    srand(time(NULL)); //random number generator

    
    //declare 3 integer arrays
    int Original[60];
    int Above[40];
    int Below[40]; 

    
    UpdateOriginalArray(Original, 60); //randomizer
    
    printf("Data\n");
    PrintIntegerArray(Original, 60); //data
    
    float average = AverageIntegerArray(Original, 60); //average
    
    int above = AboveOrBelowArray(Original, Above, Below, average, 60); //find numbers above and below average
    int below = 60 - above; //how many numbers are above and below (to eliminate zeros)
    
    printf("Above\n");
    PrintIntegerArray(Above, above); //print above array
    
    printf("\nBelow\n");
    PrintIntegerArray(Below, below); //print below array

    return 0;
}

