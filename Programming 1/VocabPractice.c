/******************************************************************************
Matthew Sliman
02/14/2023
Vocabulary Practice
*******************************************************************************/
#include <stdio.h>
#include "stdio.h"
#include "strings.h"
#include <stdlib.h>
#include <time.h>

void VocabMatch(char car, char bus, char airplane, char boat, char train, int num)
{   //input: strings car, bus, airplane, boat, train, int num
    //returned value: none
    //purpose: match vocab
    
    
    
}
int RandomWordGenerator(int num)
{   //input: num
    //returned value: num (randomized)
    //purpose: randomize num
    
    num = (rand() % 4) + 0;
    
    if(num == 0)
        printf("A four-wheeled road vehicle that is powered by an engine and is able to carry a small number of people.");
    if(num == 1)
        printf("A large motor vehicle carrying passengers by road, typically one serving the public on a fixed route and for a fare.");
    if(num == 2)
        printf("A powered flying vehicle with fixed wings and a weight greater than that of the air it displaces.");
    if(num == 3)
        printf("A small vessel propelled on water by oars, sails, or an engine.");
    if(num == 4)
        printf("A series of railroad cars moved as a unit by a locomotive or by integral motors.");
    
    return(num);
}
int main()
{
    srand(time(NULL));
    
    int Transportation[5] = {0, 1, 2, 3, 4};
    int Num;   

    char Car[3] = "car";
    char Bus[3] = "bus";
    char Airplane[8] = "airplane";
    char Boat[4] = "boat";
    char Train[5] = "train";
    
    RandomWordGenerator(Num);
    
    //Transportation[0] = Car;
    
    return 0;
}




