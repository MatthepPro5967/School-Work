/******************************************************************************

Matthew Sliman

*******************************************************************************/
#include <stdio.h>

struct emp_str
{
    int num;
    float hourly_rate;
    float hours;
    float overtime_hours;
    float gross;
    float tax;
    float net_pay;
};
//define structures
struct emp_str UpdateNet(struct emp_str A)
{   //input - structure to be updated
    //returned value - updates structure
    //goal - update net

    A.net_pay = A.gross - A.tax;
    
    return(A);
}
struct emp_str UpdateTax(struct emp_str A)
{   //input - structure to be updated
    //returned value - updates structure
    //goal - update tax

    A.tax = A.gross * .28;
    
    return(A);
}
struct emp_str UpdateGross(struct emp_str A)
{   //input - structure to be updated
    //returned value - updates structure
    //goal - update gross

    A.gross = A.hourly_rate * A.hours + A.overtime_hours * A.hourly_rate * .5;
    
    return(A);
}
struct emp_str UpdateOTHours(struct emp_str A)
{   //input - structure to be updated
    //returned value - updates structure
    //goal - update OT hours

    if(A.hours > 37.5)
        A.overtime_hours = A.hours - 37.5;
    else
        A.overtime_hours = 0;
    
    return(A);
}
struct emp_str UpdateHours(struct emp_str A)
{   //input - structure to be updated
    //returned value - updates structure
    //goal - fill hours

    printf("Enter employee hours: ");
    scanf("%f", &A.hours);
    
    return(A);
}
struct emp_str Get_Gross(struct emp_str A)
{
    
}
void PrintRecord(struct emp_str A)
{
    printf("%5i %10.2f %10.2f", A.num, A.hourly_rate, A.hours);
    printf("%10.2f %10.2f", A.overtime_hours, A.gross);
    printf("%10.2f %10.2f", A.tax, A.net_pay);
    
    printf("\n");

}
int main()
{
    struct emp_str employee1 = {1, 20.00};
    employee1 = UpdateHours(employee1);
    employee1 = UpdateOTHours(employee1);
    employee1 = UpdateGross(employee1);
    employee1 = UpdateTax(employee1);
    employee1 = UpdateNet(employee1);
    
    PrintRecord(employee1);
    
    return 0;
}

