/******************************************************************************

Matthew Sliman
02/07/2024
Characters and Strings

*******************************************************************************/
#include <stdio.h>
#include "stdio.h"
#include "string.h"

int StringLengths(char A[])
{   //input: character array
    //returned value: # of factors in the array
    //purpose: count the letters in the char array
    
    int count = 0;
    
    while(A[count] != '\0') //strlen()
        ++count;
    
    return(count);
}
void StringCopy1(char A[], char B[])
{   //input: 2 character arrays
    //returned value: none
    //purpose: copy A[] into B[]
    
    int n;
    for(n = 0; A[n] != '\0'; ++n)
        B[n] = A[n];
        
    B[n] = '\0'; //add NULL
}
void StringCopy2(char A[], char B[])
{   //input: 2 character arrays
    //returned value: none
    //purpose: copy A[] into B[]
    
    int n = 0;
    while(A[n] != '\0')
    {
        B[n] = A[n];
        ++n;
    }
    B[n] = '\0';
}


int main()
{
    
    //single characters
    char letter = 'y';
    
    printf("letter = %c\n", letter);
    
    printf("Enter a letter: ");
    scanf("%c", &letter);
    
    printf("letter = %c", letter);
    
    //strings
    char name[15] = "Matthew Sliman";
    
    printf("\nname = %s\n", name);

    printf("Enter first name: ");
    scanf("%s", name);
    
    printf("name = %s", name);
    
    //functions
    char str1[] = "Happy Weekend";
    char str2[35];
    char str3[35];
    int n;
    
    printf("str1 = %s", str1);
    printf("\nthe string\"%s\" contains %i characters\n", str1, StringLengths(str1));
    
    StringCopy1(str1, str2); //copy str1 into str2
    printf("str2 = %s\n", str2);
    
    //copy str1 into str3
    StringCopy2(str1, str3);
    printf("str3 = %s\n", str3);
    
    return 0;
}

