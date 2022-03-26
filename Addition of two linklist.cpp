#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int data;
	struct node*next;
	struct node*prev;
}*start1=NULL, *start2=NULL,*start3=NULL;

insert1(int num ) //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	printf("\nyou node :%d",temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	if(start1== NULL)
    {
      start1=temp;
    }
	else
	{
		struct node *curr=start1;
		while (curr->next != NULL)
		{
			curr=curr->next;
        }
	curr->next=temp;
	temp->prev=curr;
	}
}
void insert2 (int num ) //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	printf("\nyou node :%d",temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	if(start2== NULL)
    {
      start2=temp;
    }
	else
	{
		struct node *curr=start2;
		while (curr->next != NULL)
		{
			curr=curr->next;
        }
	curr->next=temp;
	temp->prev=curr;

	}
}
insert3(int num,int carry ) //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	temp->prev=NULL;
	if(start3== NULL)
    {
      start3=temp;
    }
	else
	{
		struct node *curr=start3;
		while (curr->next != NULL)
		{
			curr=curr->next;
        }
	curr->next=temp;
	temp->prev=curr;
	curr->data=curr->data+carry;

	}

}

addition()
{

struct node *curr1=start1;
struct node *curr2=start2;
struct node *curr3=start3;
int sum=0,carry=0;

{   if(curr1==start1 && curr2==start2)
    {
    sum=curr1->data + curr2->data;
    insert3(sum,carry);
    curr1=curr1->next;
    curr2=curr2->next;

    }

    while(curr1!=NULL && curr2 !=NULL)
    {
    sum=curr1->data + curr2->data;
    carry=sum/10;
    if(carry!= 0)
        sum=sum%10;
    insert3(sum,carry);
    curr1=curr1->next;
    curr2=curr2->next;

    }

}

}


printlist3()
{    struct node*curr=start3;
     while (curr->next != NULL)
		{
			printf("\nYour data is :%d",curr->data);
			curr=curr->next;
        }
     printf("\nYour data is :%d",curr->data);
}


int main()
{
int digit,a;
    for(int i=1;i<=2;i++)
    {
    int x=10000;
    printf("\nEnter the value of num:");
    scanf("%d",&a);
    for(int j=1;j<=5;j++)
    {

        digit = a / x;
        a = a % x;
        if(i==1)
        insert1(digit);
        else
        insert2(digit);
       x=x/10;
    }
    }

    addition();
    printlist3();
    return 0;
}
