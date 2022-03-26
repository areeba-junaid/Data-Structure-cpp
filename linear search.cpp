#include<stdio.h>
#include<conio.h>
int main()
{
	int size=10,index,flag=0,arr[size],search;
	for(index=0;index<size;index++)
	{
		printf("Enter the value :");
		scanf("%d",&arr[index]);
	}
	printf("Enter the value you want to search:");
	scanf("%d",&search);
	for(index=0;index<size;index++)
	{
		if(search==arr[index])
		{
			printf("value found");
			flag=1;
			break;
		}
	}
	if(flag==0)
	  printf("not found");
	return 0;
}
