#include <iostream>

using namespace std;

const int size = 5;
int queue[size];
int Front=-1;
int rear=-1;

void EnQueue(int value)
{
    if(rear==Front==-1)
    {
        rear==Front==0;
        queue[rear]=value;
    }
    else if ((rear+1)%size==Front)
    {
        printf("\nqueue overflow");
        //rear++;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=value;
    }

}

void PrintList()
{

    for (int i=Front; i<=rear;i=(i+1)%size)
    {
        printf ("%d", queue[i]);
    }
}

int DeQueue()
{
    if (rear==Front==-1)
    {
        printf("\nqueue underflow");
        return -1;
    }
    else if (rear==Front)
    {
        Front==rear==-1;
    }
    else
    {
        Front=(Front+1)%size;
        printf ("%d", queue[Front]);
    }
}


int main()
{
    int value;
    int a;
    while(1)
    {
        printf ("\nchoose an option: \n1-EnQueue value\n2-DeQueue value \n3-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                printf ("\nenter a value; ");
                scanf ("%d", &value);
                EnQueue(value);
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

