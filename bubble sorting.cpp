#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int size=30,arr[size],i,j,temp;
    for(i=0;i<size;i++)
    {
        printf("Enter the value of element: ");
        scanf("%d",&arr[i]);
    }
    for(i=size-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {

            if(arr[j]>arr[j+1])
            {
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;

            }
        }
    }
    printf("Your sorted values are\n{");
    for(i=0;i<size;i++)
    {
     printf("%d",arr[i]);
     if(i==size-1)
            printf("}");
     else
            printf(",");
    }

}

