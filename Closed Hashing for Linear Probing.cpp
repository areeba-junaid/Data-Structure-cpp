//program for closed hashing using linear probing
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
const int size=10;
int count =0;
int arr[10];
void insert()
{
    int data,breaker,index,flag=0;       //we initialize breaker to stop loop at one value smaller than index.
    printf("\nEnter the value you want to insert: ");
    scanf("%d",&data);
    index=data%size;
    if(count <size)
    {
    while (flag==0)//We wrote flag and not index==-1 condition because when the index will be updated the next index might already have data stored in it.
    {
        if(arr[index]==-1)
        {
         arr[index]=data;
         printf("\nThe Index is :%d",index);
         count=count + 1;
         flag=1;
         printf("\nYour total elements are: %d\nThe size is: %d",count,size);
         }
        else
        {
        index=(index+1)%size;
        }

    }
    }
    else
    {
        printf("your array is full");
    }
}

search()
{
    int flag,breaker, search,index;
    printf("\nEnter the value you want to search: ");
    scanf("%d",&search);
    index=search%size;
    breaker=index-1;
    flag=0;
    while(flag==0)
    {
        if(search==arr[index])
        {
         printf("Value is found at Index : %d",index);
         flag=1;
        }
        else
        {
            index=(index+1)%size;
        }
        if (index==breaker)
        {
            break;
        }
    }
    if (flag==0)
        printf("\nValue Not Found");
}

int main()
{

    int a;
    for(int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
    while(1)
    {
        printf ("\n\nchoose an option: \n1-insert value\n2-search value \n3-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                search();
                break;
            }
            case 3:
            {
                exit(a);
            }
        }
    }

}
