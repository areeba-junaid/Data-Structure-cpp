#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int size=10,arr[size],min_index,i,j,temp,flag=0,c;
    for(i=0;i<size;i++)
    {
        printf("Enter the value of element: ");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size-1;i++)
    {   min_index=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[min_index]>arr[j])
            {
                 min_index=j;
                 flag=1;
            }
        }
       if(flag==1)
       {
           temp=arr[i];
           arr[i]=arr[min_index];
           arr[min_index]=temp;
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
    return 0;
}
