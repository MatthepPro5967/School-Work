/******************************************************************************

    Author: Matthew Sliman
    Date: 11/23/2025
    Purpose: Takes in a population rate and an amount of days and will output
    the newpopulation with the rate after the amount of days. This is calculated
    using fibonacci's sequence to represent the population with each cycle (every 5 days)
    Time Spent: 1 hour 15 minutes
    
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

/*
    Take initial size of green crud population (in pounds) from keyboard done
    Take number of days from keyboard done
    Assume population size increases every 5 days
    Keep user input in a loop to repeat calculation as long as desired (0 is valid)
*/

int getPopulation(void);
int getDays(void);
int getInt(void);

int fib(int, int);
int sequence(int);

int boolContinue(void);

void clearBuffer(void);



int main()
{
    do {
        int population = getPopulation();
        int days = getDays();
        
        int newPopulation = fib(population, days);
        
        printf("With an initial population of %d of crud growing for %d days, the final population would be %d pounds\n", population, days, newPopulation);
        
    } while(boolContinue());

    return 0;
}

int getPopulation(void){
    
    int noc, num;
    
    do {
        printf("Please enter the initial size of the green crud: ");
        noc = scanf("%d", &num);
        clearBuffer();
        
        if (!noc || num <= 0) {
            printf("I'm sorry, that value is unrecognized or is negative.\n");
        }
            
    } while (!noc || num <= 0);
    
    return num;
}

int getDays(void){
    int noc, num;
    
    do {
        printf("Please enter number of days: ");
        noc = scanf("%d", &num);
        clearBuffer();
        
        if (!noc || num <= 0) {
            printf("I'm sorry, that value is unrecognized or is negative.\n");
        }
            
    } while (!noc || num <= 0);
    
    return num;
}

int fib(int population, int days){
    
    int newPopulation = 0;
    if (days / 5 <= 1) // edge case
        return population;
    
    int timePeriod = days / 5; // int division, tells us how many fibonacci numbers there are (not including day 0 which is just the value of population)
    
    for(int n = 1; n <= timePeriod; ++n){
        newPopulation = population * (sequence(n) + sequence(n - 1)); // just add 2 recent numbers and multiply by population rate to get newPopulation
    }
    
    return newPopulation;
    
}

int sequence(int num){
    if (num == 0) return 0;  // day 0, no growth
    if (num == 1) return 1;  // first 5-day interval

    int first = 0;
    int second = 1;
    int next;

    for (int i = 2; i <= num; i++) {
        next = first + second;
        first = second;
        second = next;
    }

    return next;
}


int boolContinue(void){
    
    char choice;
    
    do {
        printf("Would you like to continue? (y/n): ");
        scanf("%c", &choice);
        clearBuffer();
        
        if (choice != 'y' && choice != 'n'){
            printf("Please enter 'y' or 'n'.\n");
        }
        
    } while(choice != 'y' && choice != 'n');
    
    return choice == 'y';
}

void clearBuffer(void){
    
    char c;
    
    do {
        scanf("%c", &c);
    } while(c != '\n');
    
}


