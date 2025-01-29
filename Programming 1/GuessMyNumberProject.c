/******************************************************************************

Matthew Sliman
11/1/2023
Create an advanced "Guess My Number" program with 3 levels

              (
               )
              (
        /\  .-"""-.  /\
       //\\/  ,,,  \//\\
       |/\| ,;;;;;, |/\|
       //\\\;-"""-;///\\
      //  \/   .   \/  \\
     (| ,-_| \ | / |_-, |)
       //`__\.-.-./__`\\
      // /.-(() ())-.\ \\
     (\ |)   '---'   (| /)
      ` (|           |) `
        \)           (/

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //random number generator
    srand(time(NULL));

    //declare variables
    int number; //to hold the number to guess
    int guess; //to hold the user's guess
    int attempts = 0; //to hold the number of attempts
    int count;
    
    void TooHighSign(void) //function stubs
    {
        printf("(`-')                                (`-').->  _                (`-').->,---. \n");
        printf("( OO).->       .->        .->        (OO )__  (_)        .->    (OO )__ |   | \n");
        printf("/    '._  (`-')----. (`-')----.     ,--. ,'-' ,-(`-') ,---(`-'),--. ,'-'|   | \n");
        printf("|'--...__)( OO).-.  '( OO).-.  '    |  | |  | | ( OO)'  .-(OO )|  | |  ||   | \n");
        printf("`--.  .--'( _) | |  |( _) | |  |    |  `-'  | |  |  )|  | .-, \\|  `-'  ||  .' \n");
        printf("   |  |    \\|  |)|  | \\|  |)|  |    |  .-.  |(|  |_/ |  | '.(_/|  .-.  |`--'  \n");
        printf("   |  |     '  '-'  '  '  '-'  '    |  | |  | |  |'->|  '-'  | |  | |  |.--.  \n");
        printf("   `--'      `-----'    `-----'     `--' `--' `--'    `-----'  `--' `--'`--'  \n");

    }
    void TooLowSign(void)
    {
        printf("(`-')                                                        .->    \n");         
        printf("( OO).->       .->        .->          <-.        .->    (`(`-')/`) \n");          
        printf("/    '._  (`-')----. (`-')----.      ,--. )  (`-')----. ,-`( OO).', \n");          
        printf("|'--...__)( OO).-.  '( OO).-.  '     |  (`-')( OO).-.  '|  |\\  |  | \n");          
        printf("`--.  .--'( _) | |  |( _) | |  |     |  |OO )( _) | |  ||  | '.|  |  \n");         
        printf("   |  |    \\|  |)|  | \\|  |)|  |    (|  '__ | \\|  |)|  ||  |.'.|  |  \n");         
        printf("   |  |     '  '-'  '  '  '-'  '     |     |'  '  '-'  '|   ,'.   |,-.,-.,-. \n"); 
        printf("   `--'      `-----'    `-----'      `-----'    `-----' `--'   '--''-''-''-' \n"); 
    }
    void Congratulations(void)
    {
        printf(".------..------..------..------..------..------..------..------..------..------..------..------..------..------..------.\n");
        printf("|C.--. ||O.--. ||N.--. ||G.--. ||R.--. ||A.--. ||T.--. ||U.--. ||L.--. ||A.--. ||T.--. ||I.--. ||O.--. ||N.--. ||S.--. |\n");
        printf("| :/\\: || :/\\: || :(): || :/\\: || :(): || (\\/) || :/\\: || (\\/) || :/\\: || (\\/) || :/\\: || (\\/) || :/\\: || :(): || :/\\: |\n");
        printf("| :\\/: || :\\/: || ()() || :\\/: || ()() || :\\/: || (__) || :\\/: || (__) || :\\/: || (__) || :\\/: || :\\/: || ()() || :\\/: |\n");
        printf("| '--'C|| '--'O|| '--'N|| '--'G|| '--'R|| '--'A|| '--'T|| '--'U|| '--'L|| '--'A|| '--'T|| '--'I|| '--'O|| '--'N|| '--'S|\n");
        printf("`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'\n");
    }
    
    
    
    printf("Welcome to the Guess the Number game!\n");
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
    printf("`------'`------'`------'`------'`------'`------'\n\n");
    
    printf("Type '1' to play!: ");
    scanf("%i", &count);         //begin game
    if(count == 1)
        printf("\n");
    else
        return 0;   
    
    
    do
    {
        printf("\n---------------------------------------------------------------------------------------------------\n\n");
        printf("   ___              _                      _                _                                _    \n");
        printf("  / __|    ___     | |     ___     __     | |_      o O O  | |      ___    __ __    ___     | |   \n");
        printf("  \\__ \\   / -_)    | |    / -_)   / _|    |  _|    o       | |__   / -_)   \\ V /   / -_)    | |   \n");
        printf("  |___/   \\___|   _|_|_   \\___|   \\__|_   _\\__|   TS__[O]  |____|  \\___|   _\\_/_   \\___|   _|_|_ \n");
        printf("_|'''''|_|'''''|_|'''''|_|'''''|_|'''''|_|'''''| {======|_|''''''|_|''''|_|''''|_|'''''|_|'''''''|  \n");
        printf("'`-0-0-''`-0-0-''`-0-0-''`-0-0-''`-0-0-''`-0-0-'./o--000''`-0-0-''`-0-0-''-0-0-''`-0-0-''`-0---0-`  \n\n");
        printf("Type '1' for level one\nType '2' for level two\nType '3' for level three\n");
        
        printf(" __  __                          \n");
        printf("|  \\/  |   ___      _ _    ___   \n");
        printf("| |\\/| |  / _ \\    | '_|  / -_)  \n");
        printf("|_|__|_|  \\___/   _|_|_   \\___|  \n");
        printf("_|'''''|_|'''''|_|'''''|_|'''''| \n");
        printf("'`-0-0-''`-0-0-''`-0-0-''`-0-0-' \n\n");

        printf("Type '4' for more information\nType '5' to quit\nEnter choice here: ");
        scanf("%i", &count);
        printf("------------------------------------------------------------------------------------------\n");
        switch(count)
        
        {
            case 1:                                                             //level 1
                printf(".____                      .__     ____ \n");
                printf("|    |    _______  __ ____ |  |   /_   |\n");
                printf("|    |  _/ __ \\  \\/ // __ \\|  |    |   |\n");
                printf("|    |__\\  ___/\\   /\\  ___/|  |__  |   |\n");
                printf("|_______ \\___  >\\_/  \\___  >____/  |___|\n");
                printf("        \\/   \\/          \\/             \n");


                printf("I've selected a random number between 1 and 100. You have 20 guesses to try and guess it!\n");
                
                count = 20; //set max amount of tries to 20
                number = (rand() % 100) + 1;
                do
                {
                    printf("Enter your guess: "); //user input
                    scanf("%i", &guess);
                    
                    if(guess >= 1 && guess <= 100) //guess restrictions
                    {
                        
                        count = count - 1;
                        attempts = attempts + 1;
                    
                        if(guess > number)
                            TooHighSign();   //function stubs
                        if(guess < number)
                            TooLowSign();
                        printf("You have %i guesses remaining.\n", count);
                    }
                    if(guess < 1 || guess > 100)
                        printf("Invalid input, please try again (this will not be added to number of attempts/guesses)!\n"); //guess restriction
                    if(count == 0)
                            break;
                }while(number != guess);
                    if(count == 0)
                    {       printf("\nWomp womp! Your have no remaining guesses and the game has ended, better luck next time!\n");
                            attempts = 0;
                            printf("Enter any number to continue back to menu: \n");
                            scanf("%i", &count);
                            break;
                    }
                    else 
                    {
                        printf("\nCongratulations! You've guessed the number (%i) in %i attempts!\n\n", number,attempts); //win
                        attempts = 0;
                        printf("Enter any number to continue back to menu: "); //return to menu
                        scanf("%i", &count);
                        break;
                    }
                        
                
            case 2:                                                             //level 2
                printf(".____                      .__    ________  \n");
                printf("|    |    _______  __ ____ |  |   \\_____  \\ \n");
                printf("|    |  _/ __ \\  \\/ // __ \\|  |    /  ____/ \n");
                printf("|    |__\\  ___/\\   /\\  ___/|  |__ /       \\ \n");
                printf("|_______ \\___  >\\_/  \\___  >____/ \\_______ \\ \n");
                printf("        \\/   \\/          \\/               \\/ \n");
                printf("Time for level 2! I've selected a random number between 1 and 500. You have 20 guesses to try and guess it!\n");
                
                count = 20;
                number = (rand() % 500) + 1;
                do
                {
                    printf("Enter your guess: ");
                    scanf("%i", &guess);
                    
                    if(guess >= 1 && guess <= 500)
                    {
                        
                        count = count - 1;
                        attempts = attempts + 1;
                    
                        if(guess > number)
                            TooHighSign();
                        if(guess < number)
                            TooLowSign();
                        printf("You have %i guesses remaining.\n", count);
                    }
                    if(guess < 1 || guess > 500)
                        printf("Invalid input, please try again (this will not be added to number of attempts/guesses)!\n");
                    if(count == 0)
                            break;
                }while(number != guess);
                    if(count == 0)
                    {       printf("\nWomp womp! Your have no remaining guesses and the game has ended, better luck next time!\n");
                            attempts = 0;
                            printf("Enter any number to continue back to menu: \n");
                            scanf("%i", &count);
                            break;
                    }
                    else 
                    {
                        printf("\nCongratulations! You've guessed the number (%i) in %i attempts!\n\n", number,attempts);
                        attempts = 0;
                        printf("Enter any number to continue back to menu: \n");
                        scanf("%i", &count);
                        break;
                    }
            case 3:                                                             //level 3
                
                printf(".____                      .__    ________  \n");
                printf("|    |    _______  __ ____ |  |   \\_____  \\ \n");
                printf("|    |  _/ __ \\  \\/ // __ \\|  |     _(__  < \n");
                printf("|    |__\\  ___/\\   /\\  ___/|  |__  /       \\ \n");
                printf("|_______ \\___  >\\_/  \\___  >____/ /______  / \n");
                printf("        \\/   \\/          \\/              \\/ \n");
                printf("Someone feeling lucky? I've selected a random number between 1 and 1000. You have 20 guesses to try and guess it!\n");
                
                count = 20;
                number = (rand() % 1000) + 1;
                do
                {
                    printf("Enter your guess: ");
                    scanf("%i", &guess);
                    
                    if(guess >= 1 && guess <= 1000)
                    {
                        
                        count = count - 1;
                        attempts = attempts + 1;
                    
                        if(guess > number)
                            TooHighSign();
                        if(guess < number)
                            TooLowSign();
                        printf("You have %i guesses remaining.\n", count);
                    }
                    if(guess < 1 || guess > 1000)
                        printf("Invalid input, please try again (this will not be added to number of attempts/guesses)!\n");
                    if(count == 0)
                            break;
                }while(number != guess);
                    if(count == 0)
                    {       printf("\nWomp womp! Your have no remaining guesses and the game has ended, better luck next time!\n");
                            attempts = 0;
                            printf("Enter any number to continue back to menu: \n");
                            scanf("%i", &count);
                            break;
                    }
                    else 
                    {
                        printf("\nCongratulations! You've guessed the number (%i) in %i attempts!\n\n", number,attempts);
                        attempts = 0;
                        printf("Enter any number to continue back to menu: \n");
                        scanf("%i", &count);
                        break;
                    }
            case 4:                                                             //game description
                printf("\n--------------------------------------------------------------------------------------------\n");
                printf("Guess my number is an interactive game in which you will pick a number within the given range.\n");
                printf("Each level gets progressivley harder,for example, level one is easier than level two.\n");
                printf("Level one ranges from numbers 1 - 100, level two 1 - 500, and level 3 1 - 1000\n");
                printf("Once you begin the game, you will be asked to enter a number (the range depending on the level)\n");
                printf("and depending on that answer you will be shown a text that either reads 'Too high', 'Too low'\n");
                printf("or 'Congratulations'.\n\n");
                printf("   ____    U  ___ u   U  ___ u  ____          _       _   _    ____   _  __    _    \n");
                printf("'U /'___|u   \\/'_ \\/    \\/'_ \\/ |  _'\\       |'|   U |'|u| |U /'___| |'|/ /  U|'|u \n");  
                printf("\\| |  _ /   | | | |    | | | |/| | | |     U | | u  \\| |\\| |\\| | u   | ' /   \\| |/ \n"); 
                printf(" | |_| |.-,_| |_| |.-,_| |_| |U| |_| |\\     \\| |/__  | |_| | | |/__U/| . \\\\u  |_|   \n");
                printf("  \\____| \\_)-\\___/  \\_)-\\___/  |____/ u      |_____|<<\\___/   \\____| |_|\\_\\   (_) \n");  
                printf("  _)(|_       \\\\         \\\\     |||_         //  \\\\(__) )(   _// \\\\,-,>> \\\\,-.|||_ \n"); 
                printf(" (__)__)     (__)       (__)   (__)_)       (_')('_)   (__) (__)(__)\\.)   (_/(__)_) \n");
                printf("----------------------------------------------------------------------------------------------\n");
                printf("\nEnter any number to continue back to menu: ");
                scanf("%i", &count);
                break;
            
            case 5:                                                             //quit button
                printf("Sorry to see you go!");
                return 0;
        }
    
        
    }while(1 == 1); //keeps code in loop
    
    return 0;
}

















