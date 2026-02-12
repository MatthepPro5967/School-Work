/**********************************************************************
    
    Program: daily6
    Author: Matthew Sliman
    Date: 2/12/2026
    Time spent: 40 minutes
    Purpose: The purpose of this program is to reverse a linked list in place.
    This is done by passing the reference to the head of a node of a linked list 
    and derefrencing to iterate through and change pointers in place. I have 3 variables
    temp, prev, and curr which are all what they sound like. Temp creates a temporary variable 
    that will hold the next pointer in the linked list so I don't lose it when swapping. prev 
    holds the previous node (starting with null) in the linkedlist that the current node should
    be pointing to. curr holds the current node in the list and is used to iterate through via 
    the temp variable.
    
***********************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

//declare your function here.
void reverse_list(Node** head);

int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;
    
    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    
    //call your function to reverse the list (should work for any list given the head node pointer).
    //print the reversed list.
    reverse_list(&temp);
    
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    return 0;
}

//Define your function here
void reverse_list(Node** head)
{
    Node* temp; // hold next pointer so we don't lose it when reversing
    Node* curr; // hold current position in linked list
    Node* prev; // hold previous position in linked list
    
    prev = NULL; // want first element when reversing to point to null
    curr = *head; 

    while(curr != NULL) // iterate using current which is incremented using temp variable
    {
        temp = curr->next; // save the next node
        curr->next = prev; // set next node = to previous (reverse)
        
        prev = curr; // move prev up one link
        curr = temp; // move curr up one link
    }
    
    *head = prev;
    
}