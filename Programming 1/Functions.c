/******************************************************************************
Matthew Sliman
10/31/2023
Guess My Number
*******************************************************************************/
#include <stdio.h>


printf(".------..------..------..------..------.\n");    
printf("|G.--. ||U.--. ||E.--. ||S.--. ||S.--. |\n");          
printf("| :/\\: || (\\/) || (\\/) || :/\\: || :/\\: |\n");        
printf("| :\\/: || :\\/: || :\\/: || :\\/: || :\\/: |\n");        
printf("| '--'G|| '--'U|| '--'E|| '--'S|| '--'S|\n");        
printf("`------'`------'`------'`------'`------'\n");        
printf(".------..------.\n");                                
printf("|M.--. ||Y.--. |\n");                                
printf("| (\\/) || (\\/) |\n");                                
printf("| :\\/: || :\\/: |\n");                                
printf("| '--'M|| '--'Y|\n");                                
printf("`------'`------'\n");                                
printf(".------..------..------..------..------..------.\n");
printf("|N.--. ||U.--. ||M.--. ||B.--. ||E.--. ||R.--. |\n");
printf("| :(): || (\\/) || (\\/) || :(): || (\\/) || :(): |\n");
printf("| ()() || :\\/: || :\\/: || ()() || :\\/: || ()() |\n");
printf("| '--'N|| '--'U|| '--'M|| '--'B|| '--'E|| '--'R|\n");
printf("`------'`------'`------'`------'`------'`------'\n");

int number = 50; //to hold the number to guess
int guess; //to hold the user's guess
int attempts = 0; //to hold the number of attempts

void GuessMyNumberSign(void) //call does this code and goes back
{
    printf("Enter your guess: ");
    scanf("%i", &guess);
    
}
void TooHighSign(void) //function stubs
{
    printf("Too high");
}
void TooLowSign(void)
{
    printf("Too low");
}
void Congratulations(void)
{
    printf("Congratulations!");
}


int main()

}
    for(guess; guess != number; attempts = attempts + 1)
    {
        if(guess > number)
            TooHighSign();
        if else(guess < number)
            TooLowSign();
        else(Congratulations();)


        
    }
    
    GuessMyNumberSign(); //call
    TooHighSign();
    Congratulations();
    
}    
    
    return 0;
}








