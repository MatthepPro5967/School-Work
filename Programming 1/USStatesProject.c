/***********************************************************
 
 Matthew Sliman
 E-block
 4/26/2024
 US States Project
 
      /)/)/) /).-')
    ////((.'_.--'   .(\(\(\                   n/(/.')_         .
   ((((_/ .'      .-`)))))))                  `-._ ('.'        \`(\
  (_._ ` (         `.   (/ |                      \ (           `-.\
      `-. \          `-.  /                        `.`.           \ \
         `.`.          | /                /)         \ \           | L
           `.`._.      ||_               (()          `.\          ) F
   (`._      `. <    .'.-'                \`-._____    ||        .' /
    `(\`._.._(\(\)_.'.'-------------.___   `-.(`._ `-./ /     _.' .'
      (.-.| \_`.__.-<     `.    . .-'   `-.   _> `-._((`.__.-'_.-'
          (.--'   ' |    \ \     /| \.-./ |\ `-.   _.'>.___,-'`.
             (  o  <      |     |  `o   o'  |  /(`'.-'   --.    \
           .'     /      .'   _ |   |   |   |  ( .'/  o .-'   \  |
           (__.-.`-._  -'    '   \  \   /  /    ' /    _/      | J
                 \_  `.      _.__.L |   | J      (  .'\`.    _/-./
                   `-<  .-L|'`-|  ||\\V/ ||       `'   L \  /   /
                      |J  ||    \ ||||  |||            |  |_|  )
                      ||  ||     )||||  |||            || / ||J
                      (|  (|    / |||)  (||            |||  |||
                      ||  ||   / /||||  |||            |(|  |||
                      ||  ||  / / ||||  |||            |||  |||
_______.------.______/ |_/ |_/_|_/// |__| \\__________// |--( \\---------
                    '-' '-'       '-'    `-`           '-'   `-`
 
***********************************************************/
#include <stdio.h>

// Define the structure
struct S_State 
{
    char state_name[50];
    char code_name[3];
    char nickname[100];
    int admission_year;
    int admission_number;
    char capital[50];
    long population;
    int population_rank;
    double area;
};
void PeachState(struct S_State D[])
{   //Made by Matthew Sliman
    //input: structure
    //return: none
    //goal: find which state is known as the peach state

    char peach[12] = {"Peach State"};
    int count = 0;
    
    printf("6.  What state is the peach state?\n");
      
    for(int n = 0; n < 50; ++n)
    {
        for(int x = 0; x < 11; ++ x)
        {
            if(D[n].nickname[x] == peach[x])
                count += 1;
            
            if(count == 11)
                printf("%s is known as the peach state\n", D[n].state_name);
        }
        count = 0;
    }
}
void AD_Even(struct S_State US_States[])
{   //Jose Bethel
    //input: structure
    //return: none
    //goal: find which states were admitted in an even year
    
    printf("9.  Which states were admitted in an even year?\nThe states admitted in an even year are: \n");
    
    for(int i = 0; i < 50; ++i)
    {
        if(US_States[i].admission_year %2 == 0)
        {
            printf("%s in %i\n", US_States[i].state_name,US_States[i].admission_year);
        }
    }
}
void Population_Of_Idaho(struct S_State US_States[])
{   //luca bove, jose bethel
    //input: structure
    //return: none
    //goal: find the population of Idaho
    
    printf("7.  What is the population of Idaho?\n");
    
    int n = 0; // Initialize n to 0
    char I[3] = "ID";
    
    do
    {
        // Loop through all states
        for(int i = 0; i < 50; i++)
        {
            // Compare state code with "ID"
            if(US_States[i].code_name[0] == I[0] && US_States[i].code_name[1] == I[1])
            {
                n = 1; // Found Idaho, set n to 0
                printf("The population of Idaho is %lu \n", US_States[i].population);
                
            }
        }
    }while(n == 0);
}    
void LongestName(struct S_State A[])
{   //Made by Matthew Sliman
    //input: structure
    //return: none
    //goal: find which state has the longest name
    
    int count[50] = {0};
    int count2 = 0;
    int count3 = 0;
   
    printf("2. Which state(s) has the longest name? (including spaces as characters)\n");
    printf("hi");
    
    for(int n = 0; n < 50; ++n)
    {
        for(int x = 0; x < 30; ++x)
            if(A[n].state_name[x] != '\0')
                count[n] += 1;
    }
    for(int n = 0; n < 50; ++n)
    {
        if(count[n] > count2)
            count2 = count[n];
    }
    
    for(int n = 0; n < 50; ++n)
    {
        for(int x = 0; x < 30; ++x)
            if(A[n].state_name[x] != '\0')
                ++count3;
            
        if(count2 == count3)
            printf("%s\n", A[n].state_name);
            
        count3 = 0;
    }
}
void states_ad(struct S_State US_States[])
{   //Micheal Hartman
    //input: structure
    //return: none
    //goal: find which states were admitted in the 1900s
    
    int state_name;
    
    printf("4.  List the states admitted in the 1900s\n");
    printf("The states admitted in the 1900s are: ");
    for(int i = 0; i < 50; ++i)
    {
        if(US_States[i].admission_year >= 1900 && US_States[i].admission_year <= 1999)
        {
            printf("\n %s %i", US_States[i].state_name, US_States[i].admission_year);
        }
    }
    
    printf("\n");
}
void StateCapital(struct S_State US_States[])
{   //RJ Portacion & Aaron Huynh.
    //Fixed by Matthew Sliman
    //input: structure
    //return: none
    //goal: prompt user to enter state and then be given the capital of that state
    
    char input[30];
    int compare_flag;
    int verify_input = 0;
    int choice;
 
    
    printf("3.  Enter a state name.  What is the capital of that state?\n");
    
    do
    {
        printf("Enter a state: ");
        scanf(" %[^\n]", input);
            
        for(int x = 0; x < 50; ++x)
        {
            compare_flag = 0;
                    
            for(int y = 0; y <= 30; ++y)
            {
                if(input[y] != US_States[x].state_name[y] && input[y] != '\0' && US_States[x].state_name[y] != '\0')
                    compare_flag -= 100;
            }
                    
            if(compare_flag == 0)
            {
                printf("The capital of %s", input);
                printf(" is %s.\n",US_States[x].capital);
                verify_input = 1;
            }
        }
    
        if(verify_input == 0)
            printf("NO state found. Make sure the first letter is capitalized, and the spelling is correct!\n");
        
        compare_flag = 0;
        
    }while(verify_input == 0);

}
struct S_State HighPopulation(struct S_State A[])
{   //Writen by: Matthew S., Adrian M., Khlahann N.
    //input: structure
    //return: none
    //goal: find which state has the largest population
    
    printf("8.  What state has the largest population?\n");								
    int highest = A[0].population;
    
    for(int n = 0; n < 50; ++n)
    {
        if(A[n].population > highest)
            highest = A[n].population;
    }
    
    printf("The state with the largest population has a population of: %i\nThe name of the state is: ", highest);
    
    for(int n = 0; n < 50; ++n)
    {
        if(A[n].population == highest)
            printf("%s", A[n].state_name);    
       
    }
    
    printf("\n");
}
void CheckLastState(struct S_State A[])
{   //Writen by: Matthew S., Wilson
    //input: structure
    //return: none
    //goal: find which state was the last to enter the Uniited States

    printf("5.  What was the last state to enter the United States?\n");
    
    int counter;
    
    counter = A[0].admission_number;
    
    for(int n = 0; n < 50; ++n)
    {
        if(A[n].admission_number > counter)
            counter = A[n].admission_number;
            
    }
     for(int n = 0; n < 50; ++n)
    {
        if(counter == A[n].admission_number)
            printf("The state is: %s\n", A[n].state_name);
    }
}
void ListAStates(struct S_State A[])
{   //Writen by: Matthew S., Wilson
    //input: structure
    //return: none
    //goal: find which states begin with the letter 'A'

    int count = 0;
    
    printf("10.  List the states that stark with the letter A.\nThe states whose names begin with the letter 'A' are: ");
    
    char Aa[3] = "aA";
    do
    {
        for(int n = 0; n < 50; ++n)
        {
            if(A[n].state_name[0] == Aa[0] || A[n].state_name[0] == Aa[1])
            {
                ++count;
                printf("%s, ", A[n].state_name);
            }
        }
    }while(count < 6);
    
    printf("\n");
}
void FirstState(struct S_State D[])
{   //Made by Matthew Sliman
    //input: structure
    //return: none
    //goal: find which state was the first in the union
    
    char ans[50];
    int flag;
    int i = D[0].admission_year;
    
    printf("1.  What was the first state in the union?\n");
      
    for(int n = 0; n < 50; ++n)
    {
        if(D[n].admission_year < i)
            i = D[n].admission_year;    
    }
    
    printf("The first state to enter the union was:\n");
    
    for(int n = 0; n < 50; ++n)
    {
        if(D[n].admission_year == i)
            printf("%s in %i\n", D[n].state_name, i);  
    }
}
int main() 
{
    // Declare a variable of the State structure
    struct S_State US_States[50] = {{"Alabama","AL","Yellowhammer State",1819,22,"Montgomery",4833722,23,52420},
	                                {"Alaska","AK","The Last Frontier",1959,49,"Juneau",735132,47,665384},
									{"Arizona","AZ","The Grand Canyon State",1912,48,"Phoenix",6626624,15,113990},
									{"Arkansas","AR","The Natural State",1836,25,"Little Rock",2959373,32,53179},
									{"California","CA","Golden State",1850,31,"Sacramento",38332521,1,163695},
									{"Colorado","CO","The Centennial State",1876,38,"Denver",5268367,22,104094},
									{"Connecticut","CT","Constitution State",1788,5,"Hartford",3596080,29,5543},
									{"Delaware","DE","The First State/The Diamond State",1787,1,"Dover",925749,45,2489},
									{"Florida","FL","Sunshine State",1845,27,"Tallahassee",19552860,4,65758},
									{"Georgia","GA","Peach State",1788,4,"Atlanta",9992167,8,59425},
									{"Hawaii","HI","Aloha State",1959,50,"Honolulu",1404054,40,10932},
									{"Idaho","ID","Gem State",1890,43,"Boise",1612136,39,83569},
									{"Illinois","IL","Prairie State",1818,21,"Springfield",12882135,5,57914},
									{"Indiana","IN","Hoosier State",1816,19,"Indianapolis",6570902,16,36420},
									{"Iowa","IA","Hawkeye State",1846,29,"Des Moines",3090416,30,56273},
									{"Kansas","KS","Sunflower State",1861,34,"Topeka",2893957,34,82278},
									{"Kentucky","KY","Bluegrass State",1792,15,"Frankfort",4395295,26,40408},
									{"Louisiana","LA","Pelican State",1812,18,"Baton Rouge",4625470,25,52378},
									{"Maine","ME","Pine Tree State",1820,23,"Augusta",1328302,41,35380},
									{"Maryland","MD","Old Line State",1788,7,"Annapolis",5928814,19,12406},
									{"Massachusetts","MA","Bay State",1788,6,"Boston",6692824,14,10554},
									{"Michigan","MI","Wolverine State/Great Lakes State",1837,26,"Lansing",9895622,9,96714},
									{"Minnesota","MN","North Star State/Land of 10,000 Lakes",1858,32,"Saint Paul",5420380,21,86936},
									{"Mississippi","MS","Magnolia State",1817,20,"Jackson",2991207,31,48432},
									{"Missouri","MO","Show Me State",1821,24,"Jefferson City",6044171,18,69707},
									{"Montana","MT","Treasure State",1889,41,"Helena",1015165,44,147040},
									{"Nebraska","NE","Cornhusker State",1867,37,"Lincoln",1868516,37,77348},
									{"Nevada","NV","The Silver State",1864,36,"Carson City",2790136,35,110572},
									{"New Hampshire","NH","Granite State",1788,9,"Concord",1323459,42,9349},
									{"New Jersey","NJ","Garden State",1787,3,"Trenton",8899339,11,8723},
									{"New Mexico","NM","Land of Enchantment",1912,47,"Santa Fe",2085287,36,121590},
									{"New York","NY","Empire State",1788,11,"Albany",19651127,3,54555},
									{"North Carolina","NC","Old North State/Tar Heel State",1789,12,"Raleigh",9848060,10,53819},
									{"North Dakota","ND","Peace Garden State/Flickertail State/Roughrider State",1889,39,"Bismarck",723393,48,70698},
									{"Ohio","OH","Buckeye State",1803,17,"Columbus",11570808,7,44826},
									{"Oklahoma","OK","Sooner State",1907,46,"Oklahoma City",3850568,28,69899},
									{"Oregon","OR","Beaver State",1859,33,"Salem",3930065,27,98379},
									{"Pennsylvania","PA","Keystone State",1787,2,"Harrisburg",12773801,6,46054},
									{"Rhode Island","RI","The Ocean State",1790,13,"Providence",1051511,43,1545},
									{"South Carolina","SC","Palmetto State",1788,8,"Columbia",4774839,24,32020},
									{"South Dakota","SD","Mount Rushmore State",1889,40,"Pierre",844877,46,77116},
									{"Tennessee","TN","Volunteer State",1796,16,"Nashville",6495978,17,42144},
									{"Texas","TX","Lone Star State",1845,28,"Austin",26448193,2,268596},
									{"Utah","UT","The Beehive State",1896,45,"Salt Lake City",2900872,33,84897},
									{"Vermont","VT","Green Mountain State",1791,14,"Montpelier",626630,49,9616},
									{"Virginia","VA","Old Dominion State",1788,10,"Richmond",8260405,12,42775},
									{"Washington","WA","The Evergreen State",1889,42,"Olympia",6971406,13,71298},
									{"West Virginia","WV","Mountain State",1863,35,"Charleston",1854304,38,24230},
									{"Wisconsin","WI","Badger State",1848,30,"Madison",5742713,20,65496},
									{"Wyoming","WY","Equality State",1890,44,"Cheyenne",582658,50,97813}};
	
	//call to each functions, questions labeled in order
	
	//1.
	FirstState(US_States);
	//2.
	LongestName(US_States);
	//3. 
	StateCapital(US_States);
    //4. 
	states_ad(US_States);
	//5
	CheckLastState(US_States);
	//6.
	PeachState(US_States);
	//7.
	Population_Of_Idaho(US_States);
	//8. 
	HighPopulation(US_States);
	//9.
	AD_Even(US_States);
	//10.
	ListAStates(US_States);

    return 0;
}








