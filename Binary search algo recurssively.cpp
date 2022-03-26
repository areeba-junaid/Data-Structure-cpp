#include<stdio.h>
#include<conio.h>
int binarysearch(int b[],int search,int L,int R){
    int MP=(L+R)/2;
    if(L>R)
    {
     return -1;
    }
    if(search==b[MP])
    {
        printf("The value is found at %d",MP);
        return MP;
    }
    else if (search>b[MP])
        binarysearch(b,search,MP+1,R);
    else if (search<b[MP])
        binarysearch(b,search,L,MP-1);


}
int main()
{

	int search,index,size=10,arr[size],check;
	int L=0,R=size-1,flag=0;
	for(index=0;index<size;index++)
	{
		printf("Enter the value :");
		scanf("%d",&arr[index]);
	}
	printf("Enter the value you want to search:");
	scanf("%d",&search);



	check=binarysearch(arr,search,L,R);
	if(check== -1)
        printf("value not found");



}
