/******************************************************************************

    Author: Matthew Sliman
    Date: 2/6/26
    Effort: 25 Minutes
    Purpose: This program adds on to daily 4 by moving from manipulating bits from
    one number to multiple (through an array). A lot of this program was formatting everything
    correctly to work with an array of integers, and then adding the functionality
    of display_flags_as_array. Instead of displaying our numbers from bit 32 to 1, we 
    do it from 1 to 32.

*******************************************************************************/
#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);

int check_flag(unsigned int flag_holder[], int flag_position);

void display_flags(unsigned int flag_holder[], int size);
void display_flags_as_array(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };
    
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    
    display_flags(flag_holder, 5);
    printf("\n\n");
    
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);
    
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    int index = flag_position / 32;
    flag_position -= index * 32;
    
    flag_holder[index] += 1 << flag_position;
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int index = flag_position / 32;
    flag_position -= index * 32;
    
    if(flag_holder[index])
    {
        flag_holder[index] -= 1 << flag_position;
    }
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int index = flag_position / 32;
    flag_position -= index * 32;
    
    int num = 1 << flag_position;
    
    if (flag_holder[index] & num)
        return 1;
    return 0;
}

void display_flags(unsigned int flag_holder[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        display_flags_as_array(flag_holder[i]);
        printf("\n");
    }
}

void display_flags_as_array(unsigned int flag_holder)
{
        for(int i = 0; i < 32; ++i)
        {
                printf("%d", (flag_holder >> i) & 1);
                if(i % 4 == 3)
                {
                    printf(" ");
                }
        }
}