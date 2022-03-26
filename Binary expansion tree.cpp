//This program takes postfix expression and create binary expansion tree for it.
#include <iostream>
#include<stdio.h>
#include <string>
#include <stdlib.h>
#include<ctype.h>

using namespace std;

struct BTnode
{
    char letter;
    struct BTnode* rightChild;
    struct BTnode* leftChild;
}*BTnode_top=NULL;

struct BTstack
{
    struct BTnode*data;
    struct BTstack*link;

}*BTstack_top=NULL;



void push(struct BTnode* letter)
{

    struct BTstack* temp;                                  // declare temp node type pointer variable
    temp = (struct BTstack*)malloc(sizeof(struct BTstack));
    temp->data=letter;
    temp->link=NULL;
    if (BTstack_top == NULL)
    {
        BTstack_top=temp;
    }
    else
    {
       temp->link = BTstack_top;
      BTstack_top = temp;
    }
}
struct BTnode* pop()
{
    struct BTstack* curr = BTstack_top; //declare node type pointer variable curr with assigned value of start
    if (BTstack_top==NULL)
    {
        printf("stack underflow");
    }
    else{
        BTstack_top = curr->link;
        struct BTnode* a= curr ->data;
        delete(curr);
        return a;
    }
}

int IsOperator(char letter)
{
    if (letter =='|'|| letter=='+'||letter=='-' || letter=='*' || letter=='/' || letter=='^'|| letter=='<' || letter=='>' || letter=='=' || letter=='!'|| letter=='&' )
        return 1;
    else
        return 0;
}

struct BTnode* BuildExpTree(string postfix)
{
    int a=0;
    struct BTnode*temp;
    while (a<=postfix.length()-1)
    {
    if(IsOperator(postfix[a])==1)
    {
        temp = (struct BTnode*)malloc(sizeof(struct BTnode));
        temp->letter=postfix[a];
        struct BTnode* First=pop();
        struct BTnode* Second=pop();
        temp->rightChild=First;
        temp->leftChild=Second;
        push(temp);
    }
    else if (isdigit(postfix[a]) || isalpha(postfix[a]))
    {
        temp = (struct BTnode*)malloc(sizeof(struct BTnode));
        temp->letter=postfix[a];
        temp->leftChild=NULL;
        temp->rightChild=NULL;
        push(temp);
    }
    else
    {
        printf("\nEnter Invalid");
        return 0;
    }
    a++;
    }
    return temp;
}
void inorder(struct BTnode* curr)
{
    if (curr==NULL)
    {
        return;
    }
    inorder(curr->leftChild);
    printf ("%c", curr->letter);
    inorder(curr->rightChild);
}

void Postorder (struct BTnode* curr)
{
    if (curr==NULL)
    {
        return;
    }
    Postorder(curr->leftChild);
    Postorder(curr->rightChild);
    printf ("%c", curr->letter);
}

void Preorder (struct BTnode* curr)
{

    if (curr==NULL)
    {
        return;
    }
    printf ("%c", curr->letter);
    Preorder(curr->leftChild);
    Preorder(curr->rightChild);
}
int main()
{
    string postfix;
    printf("Enter the postfix Expression: ");
    getline(cin,postfix);  //scanf() function doesn't work for string
    cout<<"You Entered :"<< postfix<< endl;  //Printf() doesn't work for for string
    BTnode_top = BuildExpTree(postfix);
if(BTnode_top != 0)
{
    printf("\n\nINORDER: ");
    inorder(BTnode_top);
    printf("\n\nPOSTORDER: ");
    Postorder(BTnode_top);
    printf("\n\nPREORDER: ");
    Preorder(BTnode_top);
    printf("\n");
}

}
