/******************************************************************************

    Program: Program 3
    Author: Matthew Sliman
    Date: 4/12/26
    Time spent: 1 hour
    Purpose: The purpose of this program is to get nonnegative integer inputs 
    ranging from 0-2,000,000,000 and sort them and remove any duplicates. This program 
    does this by first using a while loop to get all the integers from the user, then shorts them
    using selection sort, and then prints the sorted list without duplicates.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct vector 
{
    int size;
    int capacity;
    int* data;
};
typedef struct vector Vector;

Vector* vector_init_default(void)
{
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    
    if(pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 8;
        pVector->data = malloc(sizeof(int) * pVector->capacity);
        if(pVector->data == NULL)
        {
            printf("Failed to allocate memeory for data.\n");
            free(pVector);
            exit(1);
        }
    }
    
    return pVector;
}

void vector_push_back(Vector* pVector, int number)
{
    if(pVector->size >= pVector->capacity)
    {
        int* temp;
        temp = malloc(sizeof(int) * (pVector->capacity * 2) );
        if(temp == NULL)
        {
            printf("Failed to allocate new space for data.\n");
            exit(1);
        }
        for(int n = 0; n < pVector->size; ++n)
        {
            temp[n] = pVector->data[n];
        }
        pVector->capacity *= 2;
        free(pVector->data);
        pVector->data = temp; 
    }

   
    pVector->data[pVector->size] = number; 
    pVector->size++;
}


void vector_selection_sort(Vector* pVector)
{
    int smallest_index;
    
    for(int i = 0; i < pVector->size - 1; ++i)
    {
        smallest_index = i;
        for(int n = i + 1; n < pVector->size; ++n)
        {
            if(pVector->data[n] < pVector->data[smallest_index])
            {
                smallest_index = n;
            }
        }
        if(smallest_index != i)
        {
            int temp = pVector->data[i];
            pVector->data[i] = pVector->data[smallest_index];
            pVector->data[smallest_index] = temp;
        }
    }
}

void print_list(Vector* pVector)
{
    if(pVector->size == 0)
        return;

    printf("%d\n", pVector->data[0]);

    for(int n = 1; n < pVector->size; ++n)
    {
        if(pVector->data[n] != pVector->data[n - 1])
        {
            printf("%d\n", pVector->data[n]);
        }
    }
}

void vector_destroy(Vector** phVector)
{
    Vector* pVector = (Vector*)*phVector;
    
    free(pVector->data);
    free(pVector);
    *phVector = NULL;
    printf("vector destroyed.\n");
}

int main(int argc, char* argv[])
{
    Vector* pVector = vector_init_default();
    int input = 0;

    while(input != -1)
    {
        scanf("%d", &input);
        if(input == -1)
            break;
        
        vector_push_back(pVector, input);
    }
    vector_selection_sort(pVector);
    print_list(pVector);
    
    vector_destroy(&pVector);
    

    return 0;
}