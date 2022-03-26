#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct Node
{
    int data; //data
    struct Node* link; //link
};


struct Node* front = NULL; // global variable start, equate start with null


void EnQueue()
{
    struct Node* rear;                                  // declare temp node type pointer variable
    rear = (struct Node*)malloc(sizeof(struct Node));
    printf ("enter data value: ");                      //data input
    scanf ("%d", &rear->data);
    rear->link=NULL;
    if (front == NULL)
    {
        front = rear;

    }
    else
    {
        struct Node* curr = front; //declare node type pointer variable curr with assigned value of start
        while(curr->link!=NULL)
        {
            curr = curr->link;
        }
        curr->link=rear;
    }
}

void PrintList()
{
    if(front==NULL)
    {
        printf("\nlist empty");
    }
    else
    {
        int a = 0;
        printf("\nyour list is... ");
        struct Node* curr = front; //declare node type pointer variable curr with assigned value of start
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


int DeQueue()
{
    struct Node* curr = front; //declare node type pointer variable curr with assigned value of start
    if (front==NULL)
    {
        printf("\nQueue underflow");
    }else{
        front = curr->link;
        int a = curr ->data;
        delete(curr);
        printf ("\nDeQueue value: %d", a);
    }
}


int main()
{
int a;
    while(1)
    {
        printf ("\nchoose an option: \n1-EnQueue value\n2-DeQueue value \n3-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                EnQueue();
                PrintList();
                break;
            }
            case 2:
            {
                DeQueue();
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
