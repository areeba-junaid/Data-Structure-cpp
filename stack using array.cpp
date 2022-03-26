#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int stack[5],size=5, top=-1;

push()
{
    int value;
    printf("\nEnter the data value: ");
    scanf("%d",&value);
    if(top==size-1)
    {
        printf("\nStack is Over flow");
    }
    else{
            top++;
            stack[top]=value;
        }


}
pop()
{
    if(top>-1)
    {
        printf("The pop element is: %d",stack[top]);
        top--;
    }
    else{
        printf("The stack is empty");
    }
}
PrintList()
{
    if(top<=-1)
    {
        printf("\nyour list is empty");
    }
    else{
        printf("\nYour list:");
    for(int x=0;x<=top;x++)
    {
        printf("%d ",stack[x]);
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
