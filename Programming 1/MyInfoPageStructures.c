/******************************************************************************

Matthew Sliman
05/10/2024
Use structures to create an X2 my info Page

*******************************************************************************/
#include <stdio.h>

struct S_Name 
{
    char first[30];
    char middle[30];
    char last[30];
    char suffix[11];
};
struct S_Date 
{
    int day;
    int month;
    int year;
};
struct S_Phone
{
    int AreaCode;
    int PrefixNumber;
    int SubscriberNumber;
};
struct Box1 
{    
    struct S_Name StudentName;
    int Local_Identifier;
    int State_Identifier;
    char Request_StateID[4];
};
struct Box2 
{
    char gender[2];
    struct S_Date Date;
    struct S_Phone HomePhone;
    struct S_Phone WorkPhone;
    struct S_Phone MobilePhone;
    char parentGuard[30];
};

struct Box3 
{
    struct S_Date Graduation;
    int Grade;
    char Calendar[10];
    char Homeroom[5];
    int AMBus;
    int PMBus;
    char InstructionMode[10];
};

struct Box4 
{
    char Enrollment[2];
    char Language[30];
    char IncludeInRank[2];
    char IncludeInHonor[2];
    char X2User[9];
    char StudentEmail[22];
    int MealPin;
};


struct Details
{
    struct Box1 One;
    struct Box2 Two;
    struct Box3 Three;
    struct Box4 Four;
};

int main()
{
    struct Details Me = { {"Matt", "BLA", "BALABLA", "Jr.", 593648831, 512912851, "N"}, {"M", 20,5,2024, 978,646,1242,978,421,7413,978,672,1425, "Messi Ying"}, 
                        {12,6,2025, 11, "Regular", "H113", 20, 20, "In-Person"}, {"Y", "English", "Y", "Y", "ghams2", "ghams2@cpslions.com", 7312} };
                        
    //printed by row
    
    printf("--------------------------------------------------------------------------------");
    printf("----------------------------------------------------------------------------\n");

    
    printf("|First Name:       %s \t|\t       Gender:            %9s|\t", Me.One.StudentName.first, Me.Two.gender);
    printf("|Graduation:       %i/%i/%i\t|\t       Enrollment:         \t  %s|\n", Me.Three.Graduation.day, Me.Three.Graduation.month, Me.Three.Graduation.year, Me.Four.Enrollment);

    printf("|Middle Name:      %s \t|\t       Date of Birth:     %i/%i/%i|\t", Me.One.StudentName.middle, Me.Two.Date.day, Me.Two.Date.month, Me.Two.Date.year);
    printf("|Grade:            %i \t\t|\t       Language:            %s|\n", Me.Three.Grade, Me.Four.Language);


    printf("|Last Name:        %s \t|\t       Home Phone:     %i-%i-%i|\t", Me.One.StudentName.last, Me.Two.HomePhone.AreaCode, Me.Two.HomePhone.PrefixNumber, Me.Two.HomePhone.SubscriberNumber);
    printf("|Calender:         %s \t|\t       Included In Rank:          %s|\n", Me.Three.Calendar, Me.Four.IncludeInRank);

    
    printf("|Suffix:           %s \t\t|      \t       Work Phone:     %i-%i-%i|\t", Me.One.StudentName.suffix, Me.Two.WorkPhone.AreaCode, Me.Two.WorkPhone.PrefixNumber, Me.Two.WorkPhone.SubscriberNumber);
    printf("|Homeroom:         %s \t|\t       Included In Honor:         %s|\n", Me.Three.Homeroom, Me.Four.IncludeInHonor);

    printf("|Local ID:         %i \t|\t       Mobile Phone:   %i-%i-%i|\t", Me.One.Local_Identifier, Me.Two.MobilePhone.AreaCode, Me.Two.MobilePhone.PrefixNumber, Me.Two.MobilePhone.SubscriberNumber);
    printf("|PM Bus:           %i \t\t|    Stdnt Email:     %s|\n", Me.Three.PMBus, Me.Four.StudentEmail);

    printf("|State ID:        %i \t|\t Parent/Guardian:     %s|\t", Me.One.State_Identifier, Me.Two.parentGuard);
    printf("|AM Bus:           %i \t\t|\t       X2 User: \t   %s|\n", Me.Three.AMBus, Me.Four.X2User);


    printf("|Request ID:       %s\t\t|\t\t\t\t\t   |\t", Me.One.Request_StateID);
    printf("|Instruction Mode: %s \t|\t       Meal Pin:               %i|\n", Me.Three.InstructionMode, Me.Four.MealPin);



    printf("--------------------------------------------------------------------------------");
    printf("----------------------------------------------------------------------------\n");


    return 0;
}




