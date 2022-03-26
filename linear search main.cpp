#include<stdio.h>
#include<conio.h>

void linearsearch (int *arr,int tosearch)
{
	int flag=0;
	for (int i=0;i<5;i++)
	{
		if (arr[i]== tosearch)
		{
		
		printf("value found");
		flag=1;
		break;
	   }
	}
	if (flag==0)
	    printf("value not found");
}
int main()
{
  int i,size=5,tosearch,arr[size];

  for(i=0;i<size;i++)
    {
        printf("Enter the value of element: ");
        scanf("%d",&arr[i]);
    }
   printf("Enter the value:");
   scanf("%d",&tosearch);
  linearsearch(arr,tosearch);
  return 0;
}
