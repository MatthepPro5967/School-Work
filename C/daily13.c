/******************************************************************************

    Author: Matthew Sliman
    Date: 10/08/2025
    Purpose: My program is a game of rock, paper, scissors. The program takes
    the input of each user, validates it, and then checks the winner (respectively).
    I used noc and boolean expressions for user validation. Then converted the user input
    (char) into my enum choices type to make things more simple. Then I implemented nested 
    switch statements checking these enum choices types to make sure that we got all 9 
    outcomes of rock paper scissors 
    Time Spent: 15 minutes

*******************************************************************************/
#include <stdio.h>
#include <ctype.h>


enum choices {ROCK, PAPER, SCISSORS};
typedef enum choices Choices;

int playAgain(void);
void winnerIs(Choices p1, Choices p2);
Choices yourTurn(int p);
void clearBuffer(void);

int main()
{
    Choices player1;
    Choices player2;

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

void winnerIs(Choices p1, Choices p2) {
    
    switch(p1) {
        case ROCK:
            switch(p2) {
                case PAPER:
                    printf("Paper beats rock. Player 2 wins!\n");
                    break;
                case SCISSORS:
                    printf("Rock beats scissors. Player 1 wins!\n");
                    break;
                default:
                    printf("You tied! Nobody wins or looses!\n");
            }
            break;
        case PAPER:
            switch(p2) {
                case ROCK:
                    printf("Paper beats rock. Player 1 wins!\n");
                    break;
                case SCISSORS:
                    printf("Scissors beats paper. Player 2 wins!\n");
                    break;
                default:
                    printf("You tied! Nobody wins or looses!\n");
            }
            break;
        case SCISSORS:
            switch(p2) {
                case ROCK:
                    printf("Rock beats scissors. Player 2 wins!\n");
                    break;
                case PAPER:
                    printf("Scissors beats paper. Player 1 wins!\n");
                    break;
                default:
                    printf("You tied! Nobody wins or looses!\n");
            }
    }
}

Choices yourTurn(int p) {
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
    
    switch(choice) {
        case 'r':
            return ROCK;
        case 'p':
            return PAPER;
        case 's':
            return SCISSORS;
    }
}

void clearBuffer(void) {
    char c;
    do {
        scanf("%c", &c);
    } while(c != '\n');
}