#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*leftchild;
	struct node*rightchild;
}*root=NULL;

struct node* insert(struct node* start,int value) //insert function
{
    if(start ==NULL)
    {
        printf("OK");
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->leftchild=NULL;
        temp->rightchild=NULL;
        return temp;
        }
    if (value <start->data)

            start->leftchild =insert(start->leftchild,value);
    else
            start->rightchild =insert(start->rightchild,value);

    return start;
}

void searching(struct node *start,int value,int count)
{
    if( start == NULL)
    {
    printf("\nValue not found");
    return;
    }
    else if(value==start->data)
    {
        printf("\nYour value %d is found at %d",start->data,count);
        return ;

    }
    else if(value>start->data)
        searching(start->rightchild,value,count + 1);
    else
        searching(start->leftchild,value,count + 1);
}

struct node* Maximum (struct node *start,int maximum)
{
    if(start->rightchild==NULL)
        return start;
    else if(start !=NULL)
    {

        return  Maximum(start->rightchild,start->data);
    }
}
int Minimum (struct node *start,int minimum)
{

    if(start->leftchild==NULL)
        return start->data;
    else if(start !=NULL)
    {

        return Minimum(start->leftchild,start->data);
    }

}
struct node* deletion(struct node* Node ,int value)
{
    if(Node==NULL)
        return Node;
    if(value<Node->data)
        Node->leftchild=deletion(Node->leftchild,value);
    else if(value>Node->data)
        Node->rightchild=deletion(Node->rightchild,value);

    else if (value == Node->data)
    {
      if(Node->leftchild==NULL && Node->rightchild==NULL)
      {
          printf("HI");
          free(Node);
          return NULL; //yOU MUST HAVE TO RETURN NULL TO TERMINATE THE FUNCTION.

      }
      else if(Node->leftchild==NULL)
      {
          struct node*temp=Node->rightchild;
          free(Node);
          return temp;
      }
      else if(Node->rightchild==NULL)
      {
        struct node*temp=Node->leftchild;
        free(Node);
        return temp;

      }
      else
       {
        struct node *temp;
        temp = Maximum(Node->leftchild,Node->leftchild->data);
        Node->data=temp->data;
        Node->leftchild=deletion(Node->leftchild,temp->data);
       }
    }
    return Node;
}
void inorder(struct node* curr)
{
    if (curr==NULL)
    {
        return;
    }
    inorder(curr->leftchild);
    printf ("%d, ", curr->data);
    inorder(curr->rightchild);
}

void Postorder (struct node* curr)
{
    if (curr==NULL)
    {
        return;
    }
    Postorder(curr->leftchild);
    Postorder(curr->rightchild);
    printf ("%d, ", curr->data);
}

void Preorder (struct node* curr)
{
    if (curr==NULL)
    {
        return;
    }
    printf ("%d, ", curr->data);
    Preorder(curr->leftchild);
    Preorder(curr->rightchild);
}


int main()
{

    int a,value;
    while(1)
    {
        printf ("\nchoose an option: \n1-Insert value\n2-Search value\n3-Maximum value\n4-Minimum value\n6-Inorder\n7-post order\n8-preoder\n5-Delete\n9-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                printf("\nEnter the value you want to insert: ");
                scanf("%d",&value);
                root=insert(root,value);
                break;
            }
            case 2:
            {
                int count=1;
                printf("\nEnter the value you want to search:");
                scanf("%d",&value);
                searching(root,value,count);
                break;
            }

            case 3:
            {
               if(root !=NULL)
                {
                struct node *temp=Maximum(root,root->data);
                printf("\nThe maximum is:%d",temp->data);
                }
                else
                   printf ("\nTHE TREE IS EMPTY");
                break;
            }

            case 4:
            {
                if(root !=NULL)
                {
                printf("\nThe minimum is:%d",Minimum(root,root->data));
                }
                else
                    printf ("\nTHE TREE IS EMPTY");
                break;

               }
            case 5:
            {
                printf("\nEnter the value you want to delete:");
                scanf("%d",&value);
                deletion(root,value);
                break;
            }
            case 6:
                {
                  inorder(root);
                  break;
                }
            case 7:
                {
                    Postorder(root);
                    break;
                }
            case 8:
                {
                    Preorder(root);
                    break;
                }



            case 9:
            {
                exit(a);
            }
        }
    }

}
