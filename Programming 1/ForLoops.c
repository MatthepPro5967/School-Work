/******************************************************************************

Matthew Sliman
10/16/2023
Write a program to preform various tasks using a for loop

                 _...Q._
               .'       '.
              /           \
             ;.-""""--.._ |
            /'-._____..-'\|
          .' ;  o   o    |`;
         /  /|   ()      ;  \
    _.-, '-' ; '.__.-'    \  \
.-"`,  |      \_         / `'`
 '._`.; ._    / `'--.,_=-;_
    \ \|  `\ .\_     /`  \ `._
     \ \    `/  ``---|    \   (~
      \ \.  | o   ,   \    (~ (~  ______________
       \ \`_\ _..-'    \  (\(~   |.------------.|
        \/  ``        / \(~/     || FREE  SNOW ||
         \__    __..-' -   '.    || """"  """" ||
          \ \```             \   || shovel all ||
          ;\ \o               ;  || you  want! ||
          | \ \               |  ||____________||
          ;  \ \              ;  '------..------'
           \  \ \ _.-'\      /          ||
            '. \-'     \   .'           ||
           _.-"  '      \-'           .-||-.
           \ '  ' '      \           '..---.- '
            \  ' '      _.'
             \' '   _.-'
              \ _.-'

*******************************************************************************/
#include <stdio.h>

int main()
{
    //declare variables
    int product = 1; //used for multiplication, set a 1 so product does not = 0
    int sum = 0, sum2 = 0, sum3 = 0; //addition of all numbers
    int multiples = 0, multiples2 = 0; //the amount of multiples there are (ex. there are 16 multiples of 6 in 100)
    int temp, temp2; //for answers
    int value; //for user input 
    int z; //for user input
    
    //1.  display the natural numbers 1 to 10
    for(int a=1; a<=10; ++a)
    printf("%3i", a);

    printf("\n"); //new line (this will be inbetween different tasks if needed)

    //2.  display the even natural numbers 10 to 25
    for(int a=10; a<=25; ++a)
    {
        if(a % 2 == 0)
        printf("%3i", a);
    }
	
	printf("\n");
	
	//3.  display the odd natural numbers  12 to 24
	for(int a=12; a<=24; ++a )
	{
	    if(a % 2 != 0)
	    printf("%3i", a);
	}
	
	printf("\n");
	
	//4.  display the multiples of 3 from 1 to 100
	for(int a=1; a<=100; ++a)
	{
	    if(a % 3 == 0)
	    printf("%3i", a);
	}
	
	printf("\n");
	
	//5.  display the multiples of 7 from 100 to 1
    for(int a = 1; a<=100; ++a)
    {
        if(a % 7 == 0)
        printf("%3i", a);
    }
    
    printf("\n");
    
	//6.  display the sum of the multiples of 4 from 1 to 100
	for(int a = 1; a<=100; ++a)
	{
	    if(a % 4 == 0)
	    sum = sum + a;
	}
    
    printf(" %i\n", sum);
	
	//7.  display the product of the odd numbers 1 to 20
	for(int a=1; a<=20; ++a)
	{
	    if(a % 2 != 0)
	    product = product * a;
	}
	printf(" %i\n", product);
	
	
	//8.  display the average for the multiples of 6 from 1 to 100
	for(int a =1; a<=100; ++a)
	{
	    if(a % 6 == 0)
	    {
	        sum2 = sum2 + a;
	        multiples = multiples + a/a;
	    }
	}
    
    temp = sum2 / multiples;
    printf(" %i\n", temp);

    //9.  display the table containing the number, 3 times the number and 5 times the number with column headings
    printf(" num  numx3  numx5\n"); //column headings (num - number, numx3 - number x 3, num5 - number x 5)
    for(int a =5; a<=15; ++a)
    printf("%3i   %3i   %5i\n", a, 3*a, 5*a);
    
    //10.  ask the user for a number of values, the user will enter the values and print the sum and the average
    printf(" Enter value here: ");
    scanf("%i", &value);
    
    for(z =1; z<=value; ++z)
    {
        printf("%3i", z);
        sum3 = sum3 + z;
        multiples2 = multiples2 + z/z;
    }
    
    temp2 = sum3 / multiples2;
    printf("\n sum = %i", sum3);
    printf("\n average = %i\n", temp2);
    
    return 0;
}


