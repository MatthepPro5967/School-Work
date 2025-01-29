/******************************************************************************
Matthew Sliman
02/09/2024
Block E
*******************************************************************************/

#include <stdio.h>
#include "stdio.h"
#include "string.h"

void CheckWord(char Word[])
{   //input: word string
    //returned value: none
    //purpose: check words validility
    
    int count = 0;
    
    do
    {
        count = 0;
       
        printf("Enter a word: ");
            scanf("%s", Word);
        for(int n = 0; Word[n] != '\0'; ++n)
            count += 1;
        if(count > 7)
            printf("Invalid Entry!\n");
    }while(count > 7);
}
void PigLatinThing(char Word[])
{   //input: word string
    //returned value: none
    //purpose: transforms word into pig latin
    
    printf("Pig Latin: ");
    
    for(int n = 1; Word[n] != '\0'; ++n)
        printf("%c", Word[n]);
    
     printf("%cay", Word[0]);
}
int main()
{
    char word[8]; //word string for user input
    
    CheckWord(word); //checks if word fits parameters
    
    printf("Word: %s\n", word);
    
    PigLatinThing(word); //translates word to piglatin
    
    return 0;
}

