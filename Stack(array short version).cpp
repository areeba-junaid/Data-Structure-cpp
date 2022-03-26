#include <iostream>

using namespace std;

const int size = 5;
int stack[size];
int Top=-1;

void push(int value)
{
    Top++;
    if(Top==size)
    {
        printf("\nstack overflow");
        return;
    }
    stack[Top]=value;
}

void PrintList()
{
    printf("\n");
    printf("Your array is...");
    printf(" {");
    for(int c=0; c<Top+1; c++)
    {
        printf("%d",stack[c]);
        if (c<Top)
        {
            printf(" , ");
        }
    }
    printf("}");
}

int pop()
{
    if (Top==-1)
    {
        printf("\nstack underflow");
        return -1;
    }
    Top--;
}

int main()
{
    int value;
    int a;
    while(1)
    {
        printf ("\nchoose an option: \n1-push value\n2-pop value \n3-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                printf ("\nenter a value; ");
                scanf ("%d", &value);
                push(value);
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
