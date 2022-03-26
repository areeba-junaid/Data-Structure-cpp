#include<stdio.h>
#include<conio.h>
int main()
{
	
	int search,index,size=10,arr[size];
	int L=0,R=size-1,MP=(L+R)/2,flag=0;
	for(index=0;index<size;index++)
	{
		printf("Enter the value :");
		scanf("%d",&arr[index]);
	}
	printf("Enter the value you want to search:");
	scanf("%d",&search);
	
	while(L<=R)
	{
		if(search==arr[MP])
		{
			printf("value found");
			flag=1;
			break;
		}
		else
		{
			if (search<arr[MP])
			   R=MP-1;
			if (search>arr[MP])
			   L=MP+1;
			
		}
			MP=(L+R)/2;
	
	}
	if (flag==0)
	    printf("value not found");
	return 0;
}

