/******************************************************************************

    Author: Matthew Sliman
    Date: 1/30/26
    Effort: 20 Minutes
    Purpose: The purpose of this assignment is to use positional notation to set 
    and check a value (flag). We do this by getting the position in the positional
    notation of a 32 bit integer and set it using set_flag. Set flag then uses the <<
    operator to raise 2 to whatever positon is denoted in the flag_position. check_flag 
    uses the & operator to make sure that whatever number we are checking is denoted in the
    positional notation (0 if not, 1 if is).

*******************************************************************************/
#include <stdio.h>

void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{   
    int flag_holder = 0;
    int i;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    
    for(i=31; i>=0; i--)
    {
            printf("%d", check_flag(flag_holder, i));
            if(i%4 == 0)
            {
                printf(" ");
            }
    }
    printf("\n");
    return 0;
}

void set_flag(int* pFlag_holder, int flag_position)
{
    *pFlag_holder += 1 << flag_position;
}

int check_flag(int flag_holder, int flag_position)
{
    int num = 1 << flag_position;
    
    if (flag_holder & num)
        return 1;
    return 0;
}