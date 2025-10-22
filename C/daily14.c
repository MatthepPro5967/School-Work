/******************************************************************************

    Author: Matthew Sliman
    Date: 10/21/2025
    Purpose: The purpose of this program is to implement stub functions 
    and show the importance of using them when taking a top-down appraoch to 
    program design and implementation. The program asks users to pick between three choices (1, 2, 0) that
    either call a function or terminate a program. In this case,
    my two stub functions are convert_lengths and convert_weights which just indicate
    that the user wants to convert values that are whatever they entered (lengths or weights)
    that is figured with a switch statement. Then, appropriate to the function, it prints the result 
    of the users input.
    Sources of Help: None
    Time Spent: 10 Minutes
     
*******************************************************************************/
#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);

int main(int argc, char *argv[]) {

	int choice;
	
	do {
    	printf("Do you want to convert values that are lengths (1) or weights (2) or terminate program (0)? ");
    	scanf("%d", &choice);
        
    	switch (choice) {
            case 1:
    	        convert_lengths();
    		    break;
    	    case 2:
    	        convert_weights();
    	        break;
            case 0:
                printf("Program terminated.\n");
    	}
	} while(choice != 0);
}

void convert_lengths(void) {
    printf("User chose to convert values that are lengths.\n");
}

void convert_weights(void){
    printf("User chose to convert values that are weights.\n");
}
