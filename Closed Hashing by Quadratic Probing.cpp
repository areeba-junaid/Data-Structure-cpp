 //closed hashing by Quadratic Probing
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
const int size=10;
int count =0;
int arr[10];
void insert()
{
    int data,index,power,flag=0,i=0;          //we initialize breaker to stop loop at one value smaller than index.
    printf("\nEnter the value you want to insert: ");
    scanf("%d",&data);
    index=data%size;                         //we divided the entered number to get the index.
    if(count <size)                          //We will not write count<=size because in 10 Iteration the count will become 10 and if we write= then this program will run 11 iteration also.
    {
                                            //We wrote flag and not index==-1 condition because when the index will be updated the next index might already have data stored in it.
    while (flag==0)
        {

        if(arr[index]==-1)
        {
         arr[index]=data;
         printf("\nThe index is:%d",index);
         count=count + 1;
         flag=1;
         }

        else
        {
        i++;
        power=i*i;
        index=(index+power)%size;
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
    int flag=0,i=0,breaker, search,index,power
    ;
    printf("Enter the value you want to search: ");
    scanf("%d",&search);
    index=search%size;
    breaker=index-1;
    while(flag==0)
    {
        if(search==arr[index])
        {
         printf("Value is found at index :%d",index);
         flag=1;
        }
        else
        {
            i++;
            power=i*i;
            index=(index+1)%size;
        }
        if (index==breaker)
        {   printf("hi");
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
        printf ("\nchoose an option: \n1-insert value\n2-search value \n3-exit\n");
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
