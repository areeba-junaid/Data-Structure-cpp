#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct Node
{
    int data; //data
    struct Node* link; //link
};//*start = NULL;


struct Node* top = NULL; // global variable start, equate start with null


void push()
{
    struct Node* temp;                                  // declare temp node type pointer variable
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf ("enter data value: ");                      //data input
    scanf ("%d", &temp->data);
    temp->link=NULL;
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->link = top;
        top = temp;
    }
}

void PrintList()
{
    if(top==NULL)
    {
        printf("list empty");
    }
    else
    {
        int a = 0;
        printf("\nyour list is... ");
        struct Node* curr = top; //declare node type pointer variable curr with assigned value of start
        do
        {
            printf("%d", curr->data);
            printf(" ");
            curr = curr->link;
            a = a + 1;

        }
        while(curr!=NULL);

    }

}

void pop()
{
    struct Node* curr = top; //declare node type pointer variable curr with assigned value of start
    int flag=0;

    if (top==NULL)
    {
        printf("stack underflow");
    }else{
        top = curr->link;
        int a = curr ->data;
        delete(curr);
        flag=1;
        printf ("pop value: %d", a);
    }

    if(flag==0)
    {
        printf("\nYour value does not exist \n");
    }

}


int main()
{
    int a;
    while(1)
    {
        printf ("\nchoose an option: \n1-push value\n2-pop value \n3-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                push();
                PrintList();
                break;
            }
            case 2:
            {
                pop();

                PrintList();
                break;
            }
            case 3:
            {
                exit(a);
            }
        }
    }

}
