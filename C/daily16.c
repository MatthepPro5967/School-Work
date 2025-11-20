/******************************************************************************

    Author: Matthew Sliman
    Date: 10/30/2025
    Purpose: Take daily 15 a little further by adding stub functions to length_to_metric,
    length_to_us, weight_to_metric, and weight_to_us. Each of these functions were given
    3 new stub functions. One for input, another for conversion, and the last for output.
    The stub functions all return nothing but use pass by reference (poitners) to manipulate
    values without returning anything.
    Sources of Help: None
    Time Spent: 30 minutes

*******************************************************************************/
#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void clearBuffer(void);

void length_to_metric(void);

void metric_input(int* meters, double* centimeters);
void metric_conversion(int meters, double centimeters, int* feet, double* inches);
void metric_output(int feet, double inches);

void length_to_us(void);

void length_input(int* feet, double* inches);
void length_conversion(int feet, double inches, int *meters, double* centimeters);
void length_output(int meters, double centimeters);

void weight_to_metric(void);

void weight_input(int* pounds, double* ounces);
void weight_conversion(int pounds, double ounces, int* kilograms, double* grams);
void weight_output(int kilograms, double grams);

void weight_to_us(void);

void us_input(int* kilograms, double* grams);
void us_conversion(int kilograms, double grams, int* pounds, double* ounces);
void us_output(int pounds, double ounces);


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
    int feet, meters;
    double inches, centimeters;

    length_input(&feet, &inches);
    length_conversion(feet, inches, &meters, &centimeters);
    length_output(meters, centimeters);
}

void length_input(int* feet, double* inches) {
    printf("Enter feet: ");
    scanf("%d", feet);
    clearBuffer();
    printf("Enter inches: ");
    scanf("%lf", inches);
    clearBuffer();
}

void length_conversion(int feet, double inches, int* meters, double* centimeters) {
    double totalFeet = feet + inches / 12.0;
    
    double totalMeters = totalFeet * 0.3048;
    
    *meters = (int)totalMeters;
    *centimeters = (totalMeters - *meters) * 100.0;
}

void length_output(int meters, double centimeters) {
    printf("Converted from feet and inches to their metric equivalents: %d meters and %.2f centimeters.\n", meters, centimeters);
}

void length_to_us(void){
    int meters, feet;
    double centimeters, inches;

    metric_input(&meters, &centimeters);
    metric_conversion(meters, centimeters, &feet, &inches);
    metric_output(feet, inches);

}

void metric_input(int* meters, double* centimeters) {
    printf("Enter meters: ");
    scanf("%d", meters);
    clearBuffer();
    printf("Enter centimeters: ");
    scanf("%lf", centimeters);
    clearBuffer();
}

void metric_conversion(int meters, double centimeters, int* feet, double* inches) {
    double totalMeters = meters + centimeters / 100.0;
    
    double totalFeet = totalMeters / 0.3048;
    
    *feet = (int)totalFeet;
    *inches = (totalFeet - *feet) * 12.0;
}

void metric_output(int feet, double inches) {
    printf("Converted from meters and centimeters to their US equivalents: %d feet and %.2f inches.\n", feet, inches);
}

void weight_to_metric(void){
    int pounds, kilograms;
    double ounces, grams;

    weight_input(&pounds, &ounces);
    weight_conversion(pounds, ounces, &kilograms, &grams);
    weight_output(kilograms, grams);
}

void weight_input(int* pounds, double* ounces) {
    printf("Enter pounds: ");
    scanf("%d", pounds);
    clearBuffer();
    printf("Enter ounces: ");
    scanf("%lf", ounces);
    clearBuffer();
}

void weight_conversion(int pounds, double ounces, int* kilograms, double* grams) {
    double totalPounds = pounds + ounces / 16.0;
    
    double totalKilograms = totalPounds / 2.2046;
    
    *kilograms = (int)totalKilograms;
    *grams = (totalKilograms - *kilograms) * 1000.0;
}

void weight_output(int kilograms, double grams) {
    printf("Converted from pounds and ounces to their metric equivalents: %d kilograms and %.2f grams.\n", kilograms, grams);
}

void weight_to_us(void){
    int kilograms, pounds;
    double grams, ounces;

    us_input(&kilograms, &grams);
    us_conversion(kilograms, grams, &pounds, &ounces);
    us_output(pounds, ounces);
}

void us_input(int* kilograms, double* grams) {
    printf("Enter kilograms: ");
    scanf("%d", kilograms);
    printf("Enter grams: ");
    scanf("%lf", grams);
    clearBuffer();
}

void us_conversion(int kilograms, double grams, int* pounds, double* ounces) {
    double totalKg = kilograms + grams / 1000.0;
    
    double totalPounds = totalKg * 2.2046;
    
    *pounds = (int)totalPounds;
    *ounces = (totalPounds - *pounds) * 16.0;
}

void us_output(int pounds, double ounces) {
    printf("Converted from kilograms and grams to their US equivalents: %d pounds and %.2f ounces.\n", pounds, ounces);
}


