#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
const int size =10;
struct node
{
	float data;
	struct node *next;
}   arr[10];
insert()
{
	int Index;
	float value;
	int invalue;
	printf("\nEnter the value: ");
	scanf("%f",&value);
	invalue=value;
	Index=invalue%size;
	if(arr[Index].data==-1)
	    arr[Index].data=value;
	else
	{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
    temp ->data=value;
	temp->next=NULL;
	if(arr[Index].next== NULL)
		arr[Index].next=temp;
	else
	{
		struct node *curr=arr[Index].next;
		while (curr->next != NULL)
		{
			curr=curr->next;
        }
	   curr->next=temp;
		
	}	    
    }
}
search()
{
	int Index,isearch;
	float search;
	printf("Enter the value you want to search: ");
	scanf("%f",&search);
	isearch=search;
	Index=isearch%size;
	if(search==arr[Index].data)
	{
		printf("Your value is found at Index %d",Index);
	}
	else
	{
		struct node* curr=arr[Index].next;
		while(curr != NULL)
	  {
	  	if(curr->data==search)
	  	{
	  		printf("value is found");
	  		break;
	  		
		}
	 	curr=curr->next;
	}
	  
	}
}

int main()
{
	for(int x=0;x<size;x++)
	{
		arr[x].data =-1.0;
		arr[x].next= NULL;
		printf("\n%f",arr[x].data);
	}
   
  for(int i=0;i<size;i++)
   {
   	insert();
   }
   search();
}

