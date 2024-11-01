/******************************************************************************
Control Structures Guided Practice
A.  (Letter Grades)  
	Write a program that asks the user to enter an integer grade 
	and will print the corresponding letter grade.
B.  (Comparison)   
	Write a program that performs the following steps
	1.  user enters 2 integers
	2.  if the first # is less than the second, print the statement in words
	3.  If the second is less than the first, print the statement in words
	4.  If the numbers are equal, print the statement in words
C.  (Evenly Divisible)  
	Write a program that performs the following steps
	1.  User enters 2 integers
	2.  if the first is evenly divisible by the second, print the statement in words
	3.  If the first is not evenly divisible by the second, print the statement in words
D.  (Conversion from number to word)  
	Write a program that performs the following steps
	1.  User enters an integer
	2.  Use a switch statement to display the number in English
E.  (Calculation based on the first #)   
	Write a program that performs the following steps
	1.  User enters 5 integers
	2.  if the first # is negative, calculate and print the product of the numbers
	3.  if the first # is positive, calculate and print the sum of the numbers
	4.  if the first # is zero, calculate and print the quotient and remainder of the product by the sum.

*******************************************************************************/
#include <stdio.h>

int main()
{
    
    /*B.  (Comparison)   
	Write a program that performs the following steps
	1.  user enters 2 integers
	2.  if the first # is less than the second, print the statement in words
	3.  If the second is less than the first, print the statement in words
	4.  If the numbers are equal, print the statement in words */
	
	//declare variables
	int num1, num2;
	
	//initialize variubles
	printf("Enter 2 integers: ");
	scanf("%i %i", &num1, &num2);
	
	//output
	if(num1 < num2)
	    printf("%i is less than %i \n", num1, num2);
	
	if(num2 < num1)
	    printf("%i is less than %i \n", num2, num1);
	
	if(num1 == num2)
	    printf("%i is equal to %i \n", num1, num2);

    /* C.  (Evenly Divisible)  
	Write a program that performs the following steps
	1.  User enters 2 integers
	2.  if the first is evenly divisible by the second, print the statement in words
	3.  If the first is not evenly divisible by the second, print the statement in words */
	
	//declare variables
	int a, b, c;
	
	//initialize variables
	printf("Enter 2 integers: ");
	scanf("%i %i", &a, &b);
	
	//calculate the remainder
	c=a%b;
	
	//output
	if(c == 0)
	    printf("%i is evenly dibisible by %i\n", a, b);
    else
        printf("%i is not evenly divisible by %i\n", a, b);
	
	
	/* D.  (Conversion from number to word)  
	Write a program that performs the following steps
	1.  User enters an integer
	2.  Use a switch statement to display the number in English */
	
	//declare variables
	int x;
	
	//initialize variables
	printf("Enter an integer(0-9): ");
	scanf("%i", &x);
	
	//output
	switch(x)
	{
	   case 0: printf("Zero\n");
	           break;
	   case 1: printf("One\n");
	           break;
	   case 2: printf("Two\n");
	           break;
	   case 3: printf("Three\n");
	           break;
	   case 4: printf("Four\n");
	           break;
	   case 5: printf("Five\n");
	           break;
	   case 6: printf("Six\n");
	           break;
	   case 7: printf("Seven\n");
	           break;
	   case 8: printf("Eight\n");
	           break;
	   case 9: printf("Nine\n");
	           break;
	   
	   default: printf("Invalid Entry\n");
	}
    
    /* E.  (Calculation based on the first #)   
	Write a program that performs the following steps
	1.  User enters 5 integers
	2.  if the first # is negative, calculate and print the product of the numbers
	3.  if the first # is positive, calculate and print the sum of the numbers
	4.  if the first # is zero, calculate and print the quotient and remainder of the product by the sum. */
	
	//declare variables
	int n1, n2, n3, n4, n5, sum, product;
	
	//initialize variables
	printf("Enter 5 integers seperated by a space: ");
	scanf("%i %i %i %i %i", &n1, &n2, &n3, &n4, &n5);
	
	//calculations
	sum = n1 + n2 + n3 + n4 + n5;
	product = n1 * n2 * n3 * n4 * n5;
	
	//compare and output
	if(n1 < 0)
	    printf("%i * %i * %i * %i * %i = %i\n", n1,n2,n3,n4,n5,product);
	else if(n1 > 0)
	    printf("%i + %i + %i + %i + %i = %i\n", n1,n2,n3,n4,n5,sum);
	else
	{
	product = 0;
	    printf("Qoutient = %i / %i = 0\n", product, sum);
	    printf("Remainder = %i / %i = 0\n", product, sum);
	}
	   
    return 0;
    
}


