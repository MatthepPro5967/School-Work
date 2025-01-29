/******************************************************************************

Matthew Sliman
01/07/2024
Fancy 2D Array Payroll

*******************************************************************************/
#include <stdio.h>

#define COLUMNS 7

void Print2DArray(float P[][COLUMNS])
{   //input: Payroll 2D Array
    //returned value: none
    //purpose: print Payroll in table format
    
    
    int counter23 = 1;
    
    printf("\n\t--------------------------------------------\n\t|The following table is");
    printf("\tfor employees 1 - 5|\n\t--------------------------------------------\n\n");
    
    printf("\tEmployee #      Rate        Hours    Gross Pay     Taxes      Net Pay\n");
    printf("\t------------------------------------------------------------------------\n");
    
    do
    {
        for(int rows = 1; rows <= 5; ++rows)
        {
            while(P[rows][1] == counter23)
            {
                printf("\t|\t%0.f  |", P[rows][1]);
        
                for(int cols = 2; cols < COLUMNS; ++cols)
                    printf("%9.2f  |", P[rows][cols]);
                ++counter23;
             
            printf("\n");
            }
        }
    }while(counter23 <= 5);
    
    printf("\t------------------------------------------------------------------------\n");
}
int GetEmployeeNum(void)
{   //input: none
    //returned value: int num
    //purpose: get user input for variable employeenum
    
    int num;
    
    do
    {
        printf("Enter Employee #: ");
        scanf("%i", &num);
        
        if(num < 1 || num > 5)
            printf("Employee # must be between 1 and 5, please try again!\n");
            
    }while(num < 1 || num > 5);
    
    return(num);
}
float GetEmployeeHours(void)
{   //input: none
    //returned value: float hours
    //purpose: get user input for variable hours
    
    float hours;
    do
    {
        printf("Enter Employee Hours: ");
        scanf("%f", &hours);
        
        if(hours < 0 || hours > 45)
            printf("Employee hours must be between 0 and 45, please try again!\n");
            
    }while(hours < 0 || hours > 45);
    
    return(hours);
}
float CalculateOT(float hour)
{   //input: float hour
    //returned value: float hoursot
    //purpose: calculate and return overtime
    
    float hoursot = 0;
    
    if(hour > 37.5)
        hoursot = hour - 37.5;
    
    printf("\n\tEmployee Statistics:\n");    
    printf("\t----------------------------------------\n");
    printf("\t|Overtime = %3.2f", hoursot);    
    
    return(hoursot);
}
float CalculateGross(float hours, float hoursot, float rate)
{   //input: float hours, hoursot, rate
    //returned value: float gross
    //purpose: calculate and return gross pay
    
    float gross;
    
    gross = ((hours - hoursot) * rate) + (hoursot * (rate * 3/2));
    printf("\tGross = %7.2f|\n", gross);
    
    return(gross);
}
float CalculateTaxes(float gross)
{   //input: float gross
    //returned value: float taxes
    //purpose: calculate and return taxes
    
    float taxes;
    
    taxes = gross * 0.28;
    printf("\t|Taxes = %7.2f\t", taxes);
    
    return(taxes);
}
float CalculateNet(float tax, float gross)
{   //input: float tax, gross
    //returned value: float net
    //purpose: calculate and return net pay
    
    float net;
    
    net = gross - tax;
    printf("Net = %7.2f  |\n", net);
    printf("\t----------------------------------------\n\n");
    
    return(net);
}
void ExtraCalculations(float P[][COLUMNS])
{   //input: Payroll 2D Array 
    //returned value: none
    //purpose: calculate the total amounts of everything from the table
    
    float grosspay = 0, totalhours = 0, taxes = 0, ot = 0;
    
    for(int rows = 1; rows <= 5; ++rows)
    {
            totalhours += P[rows][3];
            grosspay += P[rows][4];
            taxes += P[rows][5];
            
            if(P[rows][3] > 37.5)
                ot += P[rows][3] - 37.5;

    }
    
    printf("\n\tExtra Statistics (all employees)\n");
    printf("\t-------------------------------------------------\n");
    printf("\t|Total Hours = %7.2f    Total Gross = %8.2f|\n\t|Total Taxes = %7.2f    Total Overtime = %5.2f|\n", totalhours, grosspay, taxes, ot);
    printf("\t-------------------------------------------------\n\n");
}
void NoOvertime(float hours, float rate)
{   //input: float hours, rate 
    //returned value: none
    //purpose: calculate and print employee record without overtime
    
    float gross = hours * rate;
    float taxes = gross * 0.28;
    float net = gross - taxes;
        
    
    printf("\tEmployee Statistics (WITHOUT Overtime):\n");
    
    printf("\t----------------------------------------\n");
    printf("\t|Overtime = N/A        Gross = %8.2f|\n\t|Taxes = %7.2f       Net = %7.2f   |\n", gross,  taxes, net);
    printf("\t----------------------------------------\n\n");
}
void FillPayroll(float P[][COLUMNS])
{   //input: Payroll 2D Array
    //returned value: none
    //purpose: fill 2D array with necessary information corresponding to table
    
    float counter = 0, hourlyrate, employeehours, ot, gross, taxes, net;
    int employeenumbers[6] = {8,8,8,8,8,8};
    
    printf("\nEnter employee(s) info\n\n");
    
    for(int rows = 1; rows <= 5; ++rows)
    {
        for(int cols = 1; cols < COLUMNS; ++cols)
        {
            switch(cols)
            {
                case 1:
                {
                    do
                    {  
                        counter = 0;
                        employeenumbers[rows] = GetEmployeeNum();
                        for(int d = 1; d <= 5; ++d)
                        {
                            if(employeenumbers[rows] != employeenumbers[d] && rows != d)
                                ++counter;
                        }
                        
                        if(counter != 4)
                            printf("Please Enter a Different Employee Number!\n");
                    }while(counter != 4);
                    P[employeenumbers[rows]][cols] = employeenumbers[rows]; break;
                  
                }
                        
                case 2:
                    hourlyrate = P[employeenumbers[rows]][cols]; break;
                case 3:
                {
                    employeehours = GetEmployeeHours();
                    ot = CalculateOT(employeehours);
                    P[employeenumbers[rows]][cols] = employeehours; break;
                }
                case 4:
                {
                    gross = CalculateGross(employeehours, ot, hourlyrate);
                    P[employeenumbers[rows]][cols] = gross; break;
                }
                case 5:
                {
                    taxes = CalculateTaxes(gross);
                    P[employeenumbers[rows]][cols] = taxes; break;
                } 
                case 6:
                {
                    net = CalculateNet(taxes, gross);
                    P[employeenumbers[rows]][cols] = net; 
                    NoOvertime(employeehours, hourlyrate); break;
                    
                }
            }
        }
    }
    Print2DArray(P);
    ExtraCalculations(P);
}
void Interface(float P[][COLUMNS])
{   //input: Payroll 2D Array
    //returned value: none
    //purpose: Allow user to interact with the software
    
    int choice = 0;
    
    printf(" /$$$$$$$                                         /$$ /$$ \n");
    printf("| $$__  $$                                       | $$| $$\n");
    printf("| $$  \\ $$ /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$ | $$| $$\n");
    printf("| $$$$$$$/|____  $$| $$  | $$ /$$__  $$ /$$__  $$| $$| $$\n");
    printf("| $$____/  /$$$$$$$| $$  | $$| $$  \\__/| $$  \\ $$| $$| $$\n");
    printf("| $$      /$$__  $$| $$  | $$| $$      | $$  | $$| $$| $$\n");
    printf("| $$     |  $$$$$$$|  $$$$$$$| $$      |  $$$$$$/| $$| $$\n");
    printf("|__/      \\_______/ \\____  $$|__/       \\______/ |__/|__/\n");
    printf("                    /$$  | $$                            \n");
    printf("                   |  $$$$$$/                            \n");
    printf("                    \\______/                             \n");
    printf("\nWelcome to payroll, your personal data service!\n\n");
            
    printf(" _   _                    ___  ___   \n");            
    printf("| | | |            ___    |  \\/  |   \n");              
    printf("| | | |___  ___   ( _ )   | .  . | ___  _ __ ___ \n");  
    printf("| | | / __|/ _ \\  / _ \\/\\ | |\\/| |/ _ \\| '__/ _ \\\n");  
    printf("| |_| \\__ \\  __/ | (_>  < | |  | | (_) | | |  __/\n");  
    printf(" \\___/|___/\\___|  \\___/\\/ \\_|  |_/\\___/|_|  \\___|\n");  
    printf("\n('1') to use       ('2') for more      ('3') to exit\n");
    
    do
    {
        printf("\nEnter here: ");
        scanf("%i", &choice);
        
        if(choice != 1 && choice != 2 && choice != 3)
            printf("Please only enter number(s) 1, 2, or 3.\n");
    
    }while(choice != 1 && choice != 2 && choice != 3);
    
        switch(choice)
        {
            
            case 1:
                    FillPayroll(P); break;
            case 2:
                    printf("\n-----------------------------------------------------------------------------------------------\n");
                    printf("Welcome to the future! The C program designed for managing employee wage data provides users\n");  
                    printf("with a convenient and organized solution for calculating gross pay, taxes, and net pay. Its\n");  
                    printf("neat output format enhances user experience by presenting comprehensive financial details in\n");  
                    printf("a clear and easily understandable manner, ensuring efficient analysis and decision-making for\n");  
                    printf("payroll management.\n");
                    printf("-----------------------------------------------------------------------------------------------\n");
                    printf("\n(Any Number) to continue to software\n");
                    printf("\nEnter here: ");
                    scanf("%i", &choice); FillPayroll(P); break;
                    
            case 3:
                    printf("We look forward to business in the future!\n\n");
                    break;
        }
}
int main()
{
    
    float payroll[6][COLUMNS] =   
        {
            {0,0},
            {0, 1, 16.05, 0 },
            {0, 2, 18.12, 0},
            {0, 3, 17.25, 0},
            {0, 4, 25.50, 0},
            {0, 5, 17.35, 0},
        };
   
    Interface(payroll);
    
    printf("                                       _ _ _                            ()     _ \n");                   
    printf("                                      ' ) ) )     _/__/_ /              /\\    //\n");                      
    printf("Come back for more business!      --    / / / __.  /  /  /_  _  , , ,   /  )  // o ______  __.  ____ \n");  
    printf("                                       / ' (_(_/|_<__<__/ /_</_(_(_/_  /__/__</_<_/ / / <_(_/|_/ / <_ \n");  
                                                              

    return 0;
}
