#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
}*start=NULL;

void insert()
{


struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value:");
	scanf("%d",& temp ->data);
	temp->next=NULL;
	if(start== NULL)
    {
		start=temp;
		printf("The value is:%u",temp);
		printf("The value is:%u",start);
    }
	else
	{
		struct node *curr=start;
		while (curr->next != NULL)
		{
			curr=curr->next;
		}
	curr->next;

	}

}
int main()

{

    for (int i=1;i<=5;i++)
	{
	insert();
	}
    printf("THE:%d",start->data);
    return 0;
}
