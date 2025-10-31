/******************************************************************************

    Author: Matthew Sliman
    Date: 10/30/2025
    Purpose: Take daily 14 a little further by adding stub functions to convert_lengths
    and convert_weights. Using proper user input validation and switch statements, based
    on what the user picks between converting lengths and converting lengths, we give them
    two options. Either metric to imperial or imperial to metric. The new stub functions
    indicate that they have been called by printing the name of the function to the console
    Sources of Help: None
    Time Spent: 10 minutes

*******************************************************************************/
#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void clearBuffer(void);
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);

int main(int argc, char *argv[]) {

	int choice;
	
	do {
    	printf("Do you want to convert values that are lengths (1) or weights (2) or terminate program (0)? ");
    	scanf("%d", &choice);
    	clearBuffer();
        
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
	
	return 0;
}

void convert_lengths(void) {
    int choice, noc;
    
    do {
        printf("Do you want to convert lengths from feet/inches to meters/centimeters (1) or from meters/centimeters to feet/inches (2) or 0 to quit? ");
        noc = scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                length_to_metric();
                break;
            case 2:
                length_to_us();
                break;
            case 0:
                return;
        }
    } while(!noc || choice < 0 || choice > 2);
    
}

void convert_weights(void){
    int choice, noc;
    
    do {
        printf("Do you want to convert weights from pounds/ounces to kilograms/grams (1) or from kilograms/grams to pounds/ounces (2) or 0 to quit? ");
        noc = scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                weight_to_metric();
                break;
            case 2:
                weight_to_us();
                break;
            case 0:
                return;
        }
    } while(!noc || choice < 0 || choice > 2);
}

void clearBuffer(void){
    char c;
    do {
        scanf("%c", &c);
    } while(c != '\n');
}

void length_to_metric(void){
    printf("length_to_metric();\n");
}

void length_to_us(void){
    printf("length_to_us();\n");

}

void weight_to_metric(void){
    printf("weight_to_metric();\n");
}

void weight_to_us(void){
    printf("weight_to_us();\n");

}
