/******************************************************************************

    Author: Matthew Sliman
    Date: 10/04/2025
    Purpose: My program is a game of rock, paper, scissors. The program takes
    the input of each user, validates it, and then checks the winner (respectively).
    I used noc and boolean expressions for user validation. Then I implemented nested 
    switch statemnts to make sure that we got all 9 outcomes of rock paper scissors 
    Time Spent: 30 minutes

*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int playAgain(void);
void winnerIs(char p1, char p2);
char yourTurn(int p);
void clearBuffer(void);

int main()
{
    char player1;
    char player2;
    int noc;
    int play = 1;

    while(play) {
        player1 = yourTurn(1);
        player2 = yourTurn(2);
        
        winnerIs(player1, player2);
        
        play = playAgain();
    }
    
    return 0;
}

int playAgain(void){
    char choice;
    int noc;
    
    printf("Do you wish to continue? (y/n): ");
    scanf("%c", &choice);
    clearBuffer();
    tolower(choice);
    
    while(noc != 1 || (choice != 'y' && choice != 'n') ) {
        printf("I'm sorry but you must enter either 'y' or 'n'\n;");
        printf("Do you wish to continue? (y/n)");
        scanf("%c", &choice);
        clearBuffer();
        tolower(choice); 
    }
    
    if(choice == 'y')
        return 1;
    return 0;
}

void winnerIs(char p1, char p2) {
    
    switch(p1) {
        case 'r':
            switch(p2) {
                case 'p':
                    printf("Paper beats rock. Player 2 wins!\n");
                    break;
                case 's':
                    printf("Rock beats scissors. Player 1 wins!\n");
                    break;
                default:
                    printf("You tied! Nobody wins or looses!\n");
            }
            break;
        case 'p':
            switch(p2) {
                case 'r':
                    printf("Paper beats rock. Player 1 wins!\n");
                    break;
                case 's':
                    printf("Scissors beats paper. Player 2 wins!\n");
                    break;
                default:
                    printf("You tied! Nobody wins or looses!\n");
            }
            break;
        case 's':
            switch(p2) {
                case 'r':
                    printf("Rock beats scissors. Player 2 wins!\n");
                    break;
                case 'p':
                    printf("Scissors beats paper. Player 1 wins!\n");
                    break;
                default:
                    printf("You tied! Nobody wins or looses!\n");
            }
    }
}

char yourTurn(int p) {
    char choice;
    int noc;
    printf("Player %d it is your turn\n", p);
    printf("Please choose (r)ock, (p)aper, or (s)issors: ");
    noc = scanf("%c", &choice);
    tolower(choice);
    clearBuffer();

    while(noc != 1 || (choice != 'r' && choice != 'p' && choice != 's') ) {
        printf("I'm sorry but you must enter 'r', 'p', or 's'\n");
        printf("Please choose (r)ock, (p)aper, or (s)issors: ");
        noc = scanf("%c", &choice);
        tolower(choice);
        clearBuffer();
    }

    return choice;
}

void clearBuffer(void) {
    char c;
    do {
        scanf("%c", &c);
    } while(c != '\n');
}