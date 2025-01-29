/******************************************************************************
Matthew Sliman
10/04/23
Write a program to display the divisibility of a four digit numbers

           .-'"""'-.
      ,____|_______|____,
       '._____________.'  REACH FOR
           |.-- --.|      THE SKY!
           |(o) (o)|
          (|       |)
           |   U   |
 __        | .___. |    YOU'RE MY 
/|||       |       |     FAVORITE
||||       :       :      DEPUTY!
|  |/)      `.___.'
 \  /       __) (__
  \/\      /\ \ / /\
   \ \    /\ \ ^ / /\    THERE'S A
    \ \  / |  |0_/\_ \    SNAKE IN
     \ \/ /|  | \  /\ \    MY BOOT!
      \  / |  |0//\\ \ \
       \/  | /   \ |  \ \
           |/ .-. \|  / /
        .-'|-( ~ )-| / /   HI!
        \  |--`-'--|/ /   MY NAME'S WOODY!
         \ |       | /
          \|   |   |/
           |   |   |
           |   |   |     HOWDY PARDNER!
           |   |   |
           |   |   |
           |   |   |
           |___|___|     YEEEHAH COWBOY!
          `|---|---|'
          *|   |   |*
           |_._|_._|
          /'  /|\  '\    SOMEONE POISONED
     jgs /   /^ ^\   \    THE WATERHOLE!
        /__.'     `.__\

*******************************************************************************/
#include <stdio.h>

int main()
{
    //2 - if the last digit is divisible by 2 then the whole number is divisible by 2
    
    //3 - if the sum of the digits is divisible by 3, the number is also
    
    //4 - if the last two digits from a number divisible by 4, the number is also
    
    //5 - if the last digit is a 5 or a 0, the number is divisible by 5
    
    //6 - if the number is divisible by both 3 and 2, it is also divisible by 6
    
    /*7 - take the last digit, double it, and subtract it from the rest of the number; if the answer is divisible by 7
    (including 0), then the number is also*/
    
    //8 - if the last three digits form a number divisible by 8, then so is the whole number
    
    //9 - if the sum of the digits is divisible by 9, the number is also
    
    //10 if the number ends in 0, it is divisible by 10
    
    /*11 alternately add and subtract the digits from left to right. (you can think of the first digit as being 'added' 
    to zero.) if the result (including 0) is divisible by 11, the number is also. example:to see whether 365,167,484 is 
    divisible by 11,start by adding to 0: 0+3+6+5+1+6+7+4+8+4 = 0; therefore 365,167,484 is divisible by 11*/
    
    //12 - if the number is divisible by both 3 and 4, it is also divisible by 12
    
    /*13 - delete the last digit from the number, then subtract 9 times the deleted digit from the remaining number.
    if what is left is divisible by 13, then so is the original number*/
    
    //14 - if the number passes the test for 2 and 7
    
    //15 - if the number passes the test for 3 and 5
    
    //16 - divide the number in half 3 times and the result is even
    
    /*17 - multiply the last digit by 5 and subtract it from the remaining number. if the new number is divisible
    by 17 then the whole number is*/
    
    //18 - if the number passes the test for 2 and 9
    
    /*19 - add 2 times the last digit to the remaining number. if the new number is divisible by 19 then the whole
    number is*/
    
    //20 - if the tens digit is even and the number ends with 0

    //declare variables
    int first, second, third, fourth; //placeholder numbers
    int number; //user input
    int temp; //calculations
    int flag1, flag2, flag3, flag4, flag5, flag7, flag9; //flags for true and false statements
    
    //user input
        printf("Enter 4 number integer: ");
        scanf("%i", &number);
    
   
    //break numbers into digits
    fourth = number % 10;
    temp = number / 10;
    third = temp % 10;
    temp = temp / 10;
    second = temp % 10;
    temp = temp / 10;
    first = temp % 10;
   
    //divisibility rules and print statments for numbers 2 - 20
    
    //divisible by 2
    //2 - if the last digit is divisible by 2 then the whole number is divisible by 2
    if(fourth % 2 == 0)
    {    
        printf("2, ");
        flag2 = 1;
    }
    else
    flag2 = 0;
    
    //divisible by 3
    //3 - if the sum of the digits is divisible by 3, the number is also
    temp = fourth + third + second + first;
    if(temp % 3 == 0)
    {
        printf("3, ");
        flag3 = 1;
    }   
    else
    flag3 = 0;
    
    //divisible by 4
    //4 - if the last two digits from a number divisible by 4, the number is also
    if((third * 10 + fourth) % 4 == 0)
    {
        printf("4, ");
        flag4 = 1;
    } 
    else
    flag4 = 0;
    
    //divisible by 5
    //5 - if the last digit is a 5 or a 0, the number is divisible by 5
    if(fourth == 5 || fourth == 0)
    {
        printf("5, ");
        flag5 = 1;
    }   
    else
    flag5 = 0;
    
    //divisible by 6
    //6 - if the number is divisible by both 3 and 2, it is also divisible by 6
    if(flag2 == 1 && flag3 == 1)
    printf("6, ");
    
    //divisible by 7
    /*7 - take the last digit, double it, and subtract it from the rest of the number; if the answer is divisible by 7
    (including 0), then the number is also*/
    if(((fourth * 2) - (first * 100 + second * 10 + third)) % 7 == 0)
    {
        printf("7, ");
        flag7 = 1;
    }
    else 
    flag7 = 0;
    
    //divisible by 8
    //8 - if the last three digits form a number divisible by 8, then so is the whole number
    if((second * 100 + third * 10 + fourth) % 8 == 0)
    printf("8, ");
    
    //divisible by 9
    //9 - if the sum of the digits is divisible by 9, the number is also
    if((fourth + third + second + first) % 9 == 0)
    {
        printf("9, ");
        flag9 = 1;
    }
    else 
    flag9 = 0;
    
    //divisible by 10
    //10 if the number ends in 0, it is divisible by 10
    if(fourth == 0)
    printf("10, ");
    
    //divisible by 11
    /*11 alternately add and subtract the digits from left to right. (you can think of the first digit as being 'added' 
    to zero.) if the result (including 0) is divisible by 11, the number is also. example:to see whether 365,167,484 is 
    divisible by 11,start by adding to 0: 0+3-6+5-1+6-7+4-8+4 = 0; therefore 365,167,484 is divisible by 11*/
    if((fourth - third + second - first) % 11 == 0)
    printf("11, ");
    
    //divisible by 12
    //12 - if the number is divisible by both 3 and 4, it is also divisible by 12
    if(flag3 == 1 && flag4 == 1)
    printf("12, ");
    
    //divisible by 13
    /*13 - delete the last digit from the number, then subtract 9 times the deleted digit from the remaining number.
    if what is left is divisible by 13, then so is the original number*/   
    if((((number - fourth) / 10) - (fourth * 9)) % 13 == 0)
    printf("13, ");
    
    //divisible by 14
    //14 - if the number passes the test for 2 and 7
    if(flag2 == 1 && flag7 == 1)
    printf("14, ");
    
    //divisible by 15
    //15 - if the number passes the test for 3 and 5
    if(flag3 == 1 && flag5 == 1)
    printf("15, ");

    //divisible by 16
    //16 - divide the number in half 3 times and the result is even
    if((number / 2 / 2 / 2) % 2 == 0)
    printf("16, ");
    
    //divisible by 17
    /*17 - multiply the last digit by 5 and subtract it from the remaining number. if the new number is divisible
    by 17 then the whole number is*/
    if(((fourth * 5) - ((number - fourth) / 10)) % 17 == 0)
    printf("17, ");
    
    //divisible by 18
    //18 - if the number passes the test for 2 and 9
    if(flag2 == 1 && flag9 == 1)
    printf("18, ");
    
    //divisible by 19
    /*19 - add 2 times the last digit to the remaining number. if the new number is divisible by 19 then the whole
    number is*/
    if(((fourth * 2) + (number - fourth) / 10) % 19 == 0)
    printf("19, ");
    
    //divisible by 20
    //20 - if the tens digit is even and the number ends with 0
    if(third % 2 == 0 && fourth == 0)
    printf("20, ");
    
    return 0;
}








