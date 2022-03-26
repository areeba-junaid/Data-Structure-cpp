#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*leftchild;
	struct node*rightchild;
}*root=NULL;

insert() //insert function
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value:");
	scanf("%d",& temp ->data);
	temp->rightchild=NULL;
	temp->leftchild=NULL;
	if(root== NULL)
		root=temp;
	else
	{
		struct node *curr=root,*parent;
		while (curr != NULL)
		{
		    parent=curr;
		    if(temp->data>curr->data)
            {
                curr=curr->rightchild;
            }
		    else
            {
                curr=curr->leftchild;
            }
        }
        if(temp->data<parent->data)
        {
            parent->leftchild=temp;
        }
        else
            parent->rightchild=temp;
	}
}

void searching()
{
    int search,flag=0;
    printf("Enter the value you want to search: ");
    scanf("%d",&search);
    struct node*curr=root;
        if(root == NULL)
        {
            ("\nYour tree is empty");
        }
        else
        {
            int c=1;
            while(curr!=NULL)
            {
                if(search>curr->data)
                {
                    curr=curr->rightchild;
                }
                else if(search<curr->data)
                {
                    curr=curr->leftchild;
                }
                else if(search==curr->data)
                {
                    printf("\nyour value is: %d",search);
                    flag=1;
                    printf("\nIteration no: %d",c);
                    break;
                }
                c=c+1;
            }
            if(flag==0)
            {
                printf("\n Your value is not found");
            }
        }


    }
struct node* maximum(struct node *start)
{
    int maximum;
    if (start == NULL)
    {
        printf("\The tree is empty");
    }
    else
    {
        struct node *curr =start;
        struct node *max;
        while(curr !=NULL)
        {
            max=curr;
            maximum=curr->data;
            curr=curr->rightchild;

        }
        return max;

    }
}
void minimum()
{
    int minimum;
    if (root == NULL)
    {
        printf("\The tree is empty");
    }
    else
    {
        struct node *curr=root;
        while(curr !=NULL)
        {
            minimum=curr->data;
            curr=curr->leftchild;

        }
        printf("\nYour minimum :%d",minimum);
    }
}
 deletion()
{
    int value;
    printf("\nEnter the value you want to delete: ");
    scanf("%d",&value);
    if(root== NULL)
    {
        printf("\nYour tree is empty");
    }
    else
    {
      struct node*curr=root;
      struct node *parr=curr;
      while(curr !=NULL)
      {
        if(value<curr->data)
        {
            curr=curr->leftchild;
        }
        else if(value>curr->data)
        {
            curr=curr->rightchild;
        }
        if(value==curr->data)
        {
            if(curr->leftchild==NULL && curr->rightchild==NULL)
            {
                free(curr);
                printf("\nYour value is deleted");
                break;
            }
            else if(curr->rightchild==NULL)
            {
                struct node *temp=curr->leftchild;
                printf("\nThe value is deleted");
                free(curr);
                if(parr->data<temp->data)
                    parr->rightchild=temp;
                else
                    parr->leftchild=temp;
                /* printf("%d %d %d %d %d",parr->data, parr->rightchild->data,parr->leftchild->data,curr->data,temp->data);*/
                 break;
            }
             else if(curr->leftchild==NULL)
            {
                struct node *temp=curr->rightchild;
                printf("\nThe value is deleted");
                free(curr);
                if(parr->data<temp->data)
                    parr->rightchild=temp;
                else
                    parr->leftchild=temp;
               /* printf("%d %d %d %d %d",parr->data, parr->rightchild->data,parr->leftchild->data,curr->data,temp->data);*/
                break;

            }
            else
            {
                struct node *temp;
                temp=maximum(curr->leftchild);
                curr->data=temp->data;
                free(temp);
               /*  printf("%d %d %d %d %d",parr->data, parr->rightchild->data,parr->leftchild->data,curr->data,temp->data);*/
                break;
            }

        }
        if(curr==NULL)
        {
            printf("\nValue doesn't exist");
            break;
        }
        parr=curr;

     }

    }
}

int main()
{
    int a,value;
    while(1)
    {
        printf ("\nchoose an option: \n1-Insert value\n2-Search value\n3-Maximum value\n4-Minimum value\n5-Delete\n6-exit\n");
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
                searching();
                break;
            }
            case 3:
            {
                struct node *temp;
                temp = maximum(root);
                printf("\nThe maximum is:%d",temp->data);
                break;
            }
            case 4:
            {
                minimum();
                break;
            }
            case 5:
            {
                deletion();
                break;
            }
            case 6:
            {
                exit(a);
            }
        }
    }

}
