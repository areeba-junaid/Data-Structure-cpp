#include <stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
const int size =10;
struct node
{
	char data[10];
	struct node *next;
	int flag=0;
}   arr[10];
void insert()
{
	int length,sum=0 ,Index;
	char word[10];
	printf("\nEnter the value: ");
	scanf("%s",&word);
	length=strlen(word);
	for(int i=0;i<=length-1;i++)
    {
       sum=sum + word[i];
    }

	Index=sum%size;
	printf("\nIndex IS %d",Index);
	if(arr[Index].flag==0)
    {

        arr[Index].flag=1;
	    strcpy(arr[Index].data,word);

    }
	else
	{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->data,word);
	temp->next=NULL;
	if(arr[Index].next == NULL)
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
     printf("\n%s\n%s\n%s",arr[Index].data,temp->data,word);
    }

}
void search()
{
	int Index,length,sum=0,ans;
	char tosearch[10];
	printf("\nEnter the value you want to search: ");
	scanf("%s",&tosearch);
	length=strlen(tosearch);
	for(int i=0;i<=length-1;i++)
    {
       sum=sum + tosearch[i];
    }
	Index=sum%size;
	printf("%d %s %s\n",Index,tosearch,arr[Index].data);
	ans=strcmp(arr[Index].data,tosearch);

	if (ans == 0)
	{
      printf("\nYour value is found at Index %d",Index);
	}
	else
	{
		struct node* curr=arr[Index].next;
		while(curr != NULL)
	  {
	  	ans=strcmp(curr->data,tosearch);
	  	if(ans==0)
	  	{
	  		printf("value is found in link list");
	  		break;

		}
	 	curr=curr->next;
	}

	}

}


int main()
{

    int a;
    for(int x=0;x<size;x++)
	{

		arr[x].next= NULL;

	}
    while(1)
    {
        printf ("\n\nchoose an option: \n1-insert value\n2-search value \n3-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                search();
                break;
            }
            case 3:
            {
                exit(a);
            }
        }
    }

}

