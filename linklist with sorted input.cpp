//link list program with sorted inputs
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
}*start=NULL;

insert() //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value:");
	scanf("%d",& temp->data);
	temp->next=NULL;
	if(start== NULL)
		start=temp;
	else
	{
		struct node*curr=start;
		while (curr->next != NULL)
		{
         curr=curr->next;
        }
	    curr->next=temp;
        struct node*value=start;
        while(value->next!=NULL)

        {    int p;

            if(value->data>temp->data)
            {  p=temp->data;
               temp->data=value->data;
               value->data=p;
            }

            value=value->next;

        }
	}

}

 outstat() //print function
{
     struct node*curr=start;
     while(curr->next != NULL)
     {
        printf("\nYour data is :%d",curr->data);
        curr=curr->next;
     }
     printf("\nYour data is :%d",curr->data);
}

 linear(int size) //linear search function
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
	struct node *prev;
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
		prev=start;
		while(curr!=NULL)
		{
			if (curr->data==todelete)
			{
				prev->next=curr->next;
				free(curr);
				break;
			}
		    curr=curr->next;
		    prev=prev->next;
		}

	}
}
int main()

{ int i,size=10;

	for (i=1;i<=size;i++)
	{
	insert();
	}
    outstat();
    deletion();
    linear(size);
    outstat();
    return 0;
}
