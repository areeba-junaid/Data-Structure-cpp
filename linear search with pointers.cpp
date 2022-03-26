#include<stdio.h>
#include<conio.h>

void linearsearch (int *p,int tosearch,int size)
{
	int flag=0,b;
	for (int i=0;i<size;i++)
	{
		if (*p== tosearch)
		{

		printf("\nValue found :%d",*p);
		flag=1;
		break;
	   }
       p=p + 1;
	}
	if (flag==0)
	    printf("value not found");
}
int main()
{
  int i,size=10,tosearch,arr[size];

  for(i=0;i<size;i++)
    {
        printf("Enter the value of element: ");
        scanf("%d",&arr[i]);
    }
   printf("Enter the value:");
   scanf("%d",&tosearch);
  linearsearch(arr,tosearch,size);
  return 0;
}
