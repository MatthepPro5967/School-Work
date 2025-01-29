/******************************************************************************

Matthew Sliman
10/20/2023
Practice: Triangles

*******************************************************************************/
#include <stdio.h>
#define ROW 10
#define COLUMN 10

int main()
{
    //traingle 1    
    for(int r = 1; r <= ROW; ++r)
    {
        for(int c =1;c <= r; ++c)
       {
           printf("*");
       }
       printf("\n");
    }
   
    printf("\n"); //new line
   
   
   //traingle 2
   for(int r = ROW; r >= 1; --r)
   {
        for(int c = 1;c <= r; ++c)
        {
            printf("*");
        }
        printf("\n");
   }
   
   printf("\n"); //new line
   
   //traingle 3
   for(int r = ROW; r >= 1; --r)
   {
        for(int space = 0; space <= 10 - r; ++space)
            printf(" ");
            for(int c = 1;c <= r; ++c)
            {
                printf("*");
            }
                {
                    printf("\n");
                }

   }
        
    printf("\n"); //new line   
        
    //traingle 4    
     for(int r = 1; r <= ROW; ++r)
    {
        for(int space = 0; space <= 10 - r; ++space)
            printf(" ");
        for(int c = 1;c <= r; ++c)
       {
           printf("*");
       }
       printf("\n");
    }
    
    return 0;
}





