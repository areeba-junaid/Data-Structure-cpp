//addition of two linklists
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
void insert3(int num ) //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
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
	}
}

addition()
{

struct node *curr1=start1;
struct node *curr2=start2;
int sum,carry=0;
while (curr1->next !=NULL && curr2 !=NULL)
{
    curr1=curr1->next;
    curr2=curr2->next;

}
if(curr1->next==NULL && curr2->next==NULL)
{
while(curr1 != start1 && curr2 != start2)
{
    sum=0;
    sum=curr1->data + curr2->data +carry;
    carry=sum/10;
    if(carry!= 0)
        sum=sum%10;
    insert3(sum);
    curr1=curr1->prev;
    curr2=curr2->prev;
}
if(curr1 ==start1 && curr2== start2)
 {  sum=0;
    sum=curr1->data + curr2->data+carry;
    insert3(sum);
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

