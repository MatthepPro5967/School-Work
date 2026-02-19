/**********************************************************************
    
    Program: daily6B
    Author: Matthew Sliman
    Date: 2/18/2026
    Time spent: 1 hour 
    Purpose: The purpose of this program is to take numbers in a linked list 
    and combine them into one appropriately (ex. 1->8->9 = 189) using math.
    Two of these linked lists are then taken and added accordingly into one 
    list using the reverse_list function to order everything correctly. A bunch
    of other functions were made and implemented around program 6 that make the 
    give main code execute correctly.
    
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

void reverse_list(Node** head);

void head_insert(Node** head, int num);

Node* list_sum(Node* head1, Node* head2);

void print_list(Node* head);

void destroy_list(Node* head);

int main(int argc, char* argv[])
{

    //add up 189 + 11
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head_sum = NULL;

    //create a list for the number 189
    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);

    
    //create a list for the number 11
    head_insert(&head2, 1);
    head_insert(&head2, 1);

    head_sum = list_sum(head1, head2);
    printf("The sum of ");
    print_list(head1);
    printf(" + ");
    print_list(head2);
    printf("\n");
    printf(" = ");
    print_list(head_sum);
    printf("\n");
    
    //clean up three lists
    destroy_list(head1); head1 = NULL;
    destroy_list(head2); head2 = NULL;
    destroy_list(head_sum); head_sum = NULL;
    


    
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


void head_insert(Node** head, int num)
{
    Node* temp;
    
    temp = malloc(sizeof(Node));
    
    if(temp == NULL)
    {
        printf("Failed to create temp\n");
        exit(1);
    }
    
    temp->data = num;
    temp->next = *head;
    
    *head = temp;
    
}

void print_list(Node* head)
{

    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }

}

void destroy_list(Node* head)
{
    Node* temp;
    temp = head;
    
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}

Node* list_sum(Node* head1, Node* head2)
{
    Node* newHead = NULL;
    Node* temp1;
    Node* temp2;
    
    reverse_list(&head1);
    reverse_list(&head2);
    
    temp1 = head1; // So we don't change the values of head1 and head2 and then reverse them
    temp2 = head2;
    
    int total = 0, total1 = 0, total2 = 0;
    int increment = 1;
    
    while(temp1 != NULL)
    {
        total1 += temp1->data * increment;
        temp1 = temp1->next;
        increment *= 10;
    }
    
    increment = 1;
    
    while(temp2 != NULL)
    {
        total2 += temp2->data * increment;
        temp2 = temp2->next;
        increment *= 10;
    }
    
    total = total1 + total2;
    

    while(total != 0)
    {
        head_insert(&newHead, total % 10);
        total /= 10;
    }
    
    reverse_list(&head1);
    reverse_list(&head2);
    
    return newHead;
}