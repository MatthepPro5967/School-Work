/******************************************************************************

Matthew Sliman
1/10/2024
Arrays

*******************************************************************************/
#include <stdio.h>

void Stars(int max)
{   //input: # of stars to print
    //returned value: none
    //purpose: to print stars
    
    for(int n = 0; n <= max; ++n)
        printf("*");
    
    printf("\n");
}
void Histogram(int D[])
{   //input: data array
    //returned value: none
    //purpose: to print histogram
    
    for(int n = 1; n <= 10; ++n)
    {
        printf("%2i: ", n);
        Stars(D[n]);
    }
}
int Mean(int D[])
{   //input: data array
    //returned value: elements
    //purpose: calculate and print the mean
    
    int sum = 0, elements = 0; //declare and initialize variables
    
    //calculate sums
    for(int n = 1; n <= 10; ++n)
    {
        sum = sum + n * D[n];
        elements = elements + D[n];
    }
    
    //calculate and print mean
    printf("Mean: %.2f\n", (float)sum/elements);
    
    return(elements);
}
void Median(int D[], int mid)
{   //input: data array
    //returned value: none
    //purpose: find and print median
    
    int n = 1, sum = 0;
    
    while(sum <= mid)
    {
        sum = sum + D[n];
        ++n;
    }
    printf("Median: %i\n", n - 1);
}
void Mode(int D[])
{   //input: data array
    //returned value: none
    //purpose: find and print mode
    
    int big; 
    
    big = D[1];
    
    //find largest number
    for(int n = 1; n <= 10; ++n)
    {
        if(big < D[n])
            big = D[n];
    }
    
    //print the index(s) of the big
    printf("Mode: ");
    
    for(int n = 1; n <= 10; ++n)
    {
        if(D[n] == big)
            printf("%2i", n);
    }
    
}

int main()
{
    int data[11] = {0,9,5,11,9,7,12,13,14,7,13};
    int middle;
    
    Histogram(data);
    middle = Mean(data)/2;
    Median(data, middle);
    Mode(data);
    
    return 0;
}

