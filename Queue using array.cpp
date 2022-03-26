#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int stack[5],size=5, front=-1,tail=-1;

void EnQueue()
{
    int value;
    printf("\nEnter the data value: ");
    scanf("%d",&value);
    if(tail==size-1 && front!=0)
    {
        tail=0;
        stack[tail]=value;
        printf("\nFirst if");
    }
    else if(front==-1 )
    {
       tail=0;
       front=0;
       stack[tail]=value;
        printf("\nSecond If");
    }
    else if(tail==size-1 && front== 0)
    {
        printf("The stack Overflow");
    }
    else if(tail !=0 && tail==front-1)
    {
        printf("The stack Overflow");
    }

    else{
             tail++;
             stack[tail]=value;
             printf("\nlast");
         }
    printf("\nThe tail is :%d",tail);
    printf("\n The front %d",front);

}
void DeQueue()
{
    if(front>-1 && front<=size-1)
    {
        printf("The pop element is: %d",stack[front]);
        stack[front]=NULL;
        front++;
        printf("\n%d",front);
        if (front==size && tail==size-1)

       {
        front=-1;
        tail=-1;
       }

    }
    else if(front==-1)
    {
       printf("\n The Queue is empty");
    }


}
void PrintList()
{
    if(tail<=-1)
    {
        printf("\nyour list is empty");
    }
    else
    {
        printf("\nYour list:");
    for(int x=0;x<=size-1;x++)
    {   if(stack[x]!=NULL)
    {
       printf("%d ",stack[x]);
    }
    }
    }
}

int main()
{
    int a;
    while(2)
    {
        printf ("\nchoose an option: \n1-push value\n2-pop value \n3-exit\n");
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
