#include <stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;


int const  n=10;
int sorted_arr[n];
Merge(int arr[n],int LB,int mid,int UB)
{
    int i,j,k;
    i=LB;
    k=LB;
    j=mid+1;
    while(i<=mid && j<=UB)
    {
        if(arr[i]<=arr[j])
        {
            sorted_arr[k]=arr[i];
            i++;
        }
        else
        {
          sorted_arr[k]=arr[j];
          j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=UB)
        {
            sorted_arr[k]=arr[j];
            j++;
            k++;
        }
    }
    else
        {
            while(i<=mid)
            {
                sorted_arr[k]=arr[i];
                i++;
                k++;
            }
        }
}
MergeSort(int arr[n],int LB,int UB)
{
    if(LB<=UB)
    {
        int mid=(LB+UB)/2;
        MergeSort(arr,LB,mid);
        MergeSort(arr,mid+1,UB);
        Merge(arr,LB,mid,UB);
    }
}
int main()
{
    int arr[n];
    for (int i=0;i<=n-1;i++)
    {
        cout<<"Enter the number: ";
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    cout<<"The sorted list is: "<<endl;
    for (int i=0;i<=n-1;i++)
    {
        cout<<sorted_arr[i]<<endl;
    }
}
