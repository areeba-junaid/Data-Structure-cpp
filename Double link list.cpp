#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	struct node*prev;
}*start=NULL;

insert() //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value:");
	scanf("%d",& temp ->data);
	temp->next=NULL;
	temp->prev=NULL;
	if(start== NULL)
		start=temp;
	else
	{
		struct node *curr=start;
		while (curr->next != NULL)
		{
			curr=curr->next;
        }
	curr->next=temp;
	temp->prev=curr;
	}
}

 outstat(int size) //print function
{
     struct node*curr=start;
     for(int x=1;x<=size;x++)
     {
        printf("\nYour data is :%d",curr->data);
        curr=curr->next;
     }
}

 linear(int size) //linear function
{
    int tosearch,flag =0;
    struct node*curr=start;
	printf("Enter the value you want to search:");
	scanf("%d",&tosearch);
	 for(int x=1;x<=size;x++)
     {
        if (curr->data == tosearch)
		{
		printf("value found at node:%d",x);
		flag=1;
		break;
	   }
       curr=curr->next;
     }
	 if (flag == 0)
        printf("value not found");
}
deletion()
{
	int  todelete ;
	struct node*curr=start;
	printf("\nEnter the value you want to delete:");
	scanf("%d",&todelete);
	if(start->data==todelete)
	{
		start=start->next;
		free(curr);
		
	}
	else
	{
		curr=start->next;
		curr->prev=start;
		while(curr!=NULL)
		{
			if (curr->data==todelete)
			{
				curr->prev->next=curr->next;
				free(curr);
				break;
			}
		    curr=curr->next;
		    curr->prev=curr->prev->next;
		}
			
	}
}
int main()

{ int i,size=5;

	for (i=1;i<=size;i++)
	{
	insert();
	}
	linear(size);
    outstat(size);
    
    deletion();
    outstat(size);
    return 0;
}
