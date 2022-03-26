#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Cycle_Stack
{
    struct Vertex* V;
    struct Cycle_Stack *Next;
}*top=NULL;
struct Vertex
{
    char Vertex_Name;
    struct Vertex *next;
    struct Edge *edgelist;
    int  visited;
    int printflag;
} *Graph=NULL;

struct Edge
{
    int weight;
    struct Edge *EdgeNext;
    struct Vertex *VertexHolder;
};

void AddVertex() //Simple like link list
{
    struct Vertex *temp;
    temp = (struct Vertex*)malloc(sizeof(struct Vertex));
    printf("Enter your Vertex Name:");
    cin>>temp->Vertex_Name; //Scanf is not working with char
    temp->next=NULL;
    temp->edgelist=NULL;
    temp->visited=-1;
    temp->printflag=-1;
    if(Graph==NULL)
        Graph=temp;
    else
    {
        struct Vertex *curr=Graph;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
struct Vertex* FindVertex(char data)
{
    int flag=0;
    if(Graph == NULL)
       {
        printf("\n No Vertex Exist" );
        return NULL;
       }
    else
      {
        struct Vertex*curr=Graph;
        while(curr!=NULL)
        {
            if(curr->Vertex_Name==data)
            {
                return curr;
            }
            curr=curr->next;
        }
    }
    if(flag==0)
        {
            printf("\nVertex not found ");
            return NULL;
        }
}


void ADDEdge()
{
    char v1,v2;
    printf("Enter Vertex 1(source) Name: ");
    cin>>v1;
    printf("Enter Vertex 2 (Destination) Name: ");
    cin>>v2;
    struct Vertex* curr=FindVertex(v1);
    struct Vertex* Holder=FindVertex(v2);

            if(curr==NULL || Holder==NULL)
            {
                return;
            }

            else
            {
               struct Edge*EdgeTemp;
               EdgeTemp=(struct Edge*)malloc(sizeof(struct Edge));
               printf("\nEnter Edge weight:");
               scanf("%d",&EdgeTemp->weight);
               EdgeTemp->VertexHolder=Holder;
               EdgeTemp->EdgeNext=NULL;
            if(curr->edgelist==NULL)
            {
                   curr->edgelist=EdgeTemp;
            }
            else
            {
              struct Edge *EdgeCurr=curr->edgelist;
              while (EdgeCurr->EdgeNext != NULL)
		      {
			   EdgeCurr=EdgeCurr->EdgeNext;
              }
	          EdgeCurr->EdgeNext=EdgeTemp;
            }
            }
}
int FindOutDegree(char Vertex)
{
    int count=0;
    struct Vertex* curr=FindVertex(Vertex);
    if(curr==NULL)
    {
        return -1;
    }
    else
    {
        struct Edge*EdgeCurr=curr->edgelist;
    while (EdgeCurr!= NULL)
    {
        EdgeCurr=EdgeCurr->EdgeNext;
        count=count+1;
    }
    return count;
    }
}
int FindInDegree(char vertex)
{
    int count=0;
    struct Vertex* VertexCurr=Graph;
    if(VertexCurr==NULL)
    {
        return -1;
    }

    while(VertexCurr!=NULL)
    {
        struct Edge* EdgeCurr=VertexCurr->edgelist;
        while (EdgeCurr!= NULL)
        {
            if (EdgeCurr->VertexHolder->Vertex_Name==vertex)
                  {
                      count=count+1;
                  }
            EdgeCurr=EdgeCurr->EdgeNext;
        }
        VertexCurr=VertexCurr->next;
    }
    return count;
}
void FindNeighbour(char Vertex)
{
    struct Vertex* curr=FindVertex(Vertex);
    if(curr==NULL)
    {
        return ;
    }
    struct Edge*EdgeCurr=curr->edgelist;
    while (EdgeCurr!= NULL)
    {
        cout<<EdgeCurr->VertexHolder->Vertex_Name<<endl;
        EdgeCurr=EdgeCurr->EdgeNext;
    }
}
void RemoveEdge(char v1,char v2)
{
    int flag=0;
    struct Vertex* VertexCurr=FindVertex(v1);
    struct Vertex* Holder=FindVertex(v2);
    if(VertexCurr==NULL)
    {
        return;
    }
    if(VertexCurr->edgelist==NULL)
    {
        printf("\nThis Vertex has no Edge");
        return;
    }
    struct Edge*EdgeCurr=VertexCurr->edgelist;
    struct Edge*EdgePrev;
    if (EdgeCurr->VertexHolder==Holder)
     {
       printf("\nThe Edge to  \'%c\' is deleted",EdgeCurr->VertexHolder->Vertex_Name);
       flag =1;
       VertexCurr->edgelist=EdgeCurr->EdgeNext;
       free(EdgeCurr);
     }
     else
     {
         EdgePrev=EdgeCurr;
         EdgeCurr=EdgeCurr->EdgeNext;
        while(EdgeCurr !=NULL)
        {
            if (EdgeCurr->VertexHolder==Holder)
                {
                printf("\nThe Edge to  \'%c\' is deleted",EdgeCurr->VertexHolder->Vertex_Name);
                EdgePrev->EdgeNext=EdgeCurr->EdgeNext;
                flag=1;
				free(EdgeCurr);
				break;
                }
            EdgeCurr=EdgeCurr->EdgeNext;
		    EdgePrev=EdgePrev->EdgeNext;

        }}
    if(flag==0)
    {
        printf("\nThe Vertex %c doesn't have Edge to Vertex %c: ",v1,v2);
    }

}
void RemoveVertex(char vertex)
{

   struct Vertex* VertexCurr=FindVertex(vertex);
   if(VertexCurr==NULL)
            {
                return;
            }
  struct Vertex *start=Graph;
  while(start !=NULL) //This remove the vertex as an edge to other vertex before Deleting the vertex
  {
      RemoveEdge(start->Vertex_Name,vertex);
      start=start->next;
  }
  if(VertexCurr->edgelist!=NULL)
   {
   struct Edge*EdgeCurr=VertexCurr->edgelist;
   while(EdgeCurr!=NULL)//This while loop removes all edge of vertex to be deleted
   {
      struct Edge *temp=EdgeCurr; //This holds the temporarily Edge of an vertex so then after going to the next Edge we won't loose the value to be deleted.
      EdgeCurr=EdgeCurr->EdgeNext;
      RemoveEdge(vertex,temp->VertexHolder->Vertex_Name);
   }
   }
   if(VertexCurr==Graph)
   {
       Graph=VertexCurr->next;
       free(VertexCurr);
   }
   else
   {    struct Vertex*prev=Graph;
        while(prev->next->Vertex_Name!=VertexCurr->Vertex_Name)//This while loop find previos node of our vertex to be deleted
        {
        prev=prev->next;
        }
        prev->next=VertexCurr->next;
        free(VertexCurr);
   }
   printf("\n\nThe Vertex %c is now deleted ",vertex);

}
void Flag()
{
    struct Vertex* Curr=Graph;
    while(Curr!=NULL)
    {
      Curr->visited=-1;
      Curr=Curr->next;
    }
}
int HasPath (struct Vertex *v1,struct Vertex *v2)
{
    if (v1==v2)
    {
        return 1;
    }
    v1->visited=1;
    struct Edge*EdgeCurr=v1->edgelist;
    while (EdgeCurr!= NULL)
    {

      if(EdgeCurr->VertexHolder->visited==-1)
      {

        int hasNbrPath=HasPath(EdgeCurr->VertexHolder,v2);
        if(hasNbrPath==1)
        {
            return 1;
        }
      }
      EdgeCurr=EdgeCurr->EdgeNext;
    }
    return 0;
}

void PrintPath(struct Vertex *v1,struct Vertex *v2)
{
     if(v1 == NULL||v2==NULL)
       {
        return ;
       }

     int hasNbrPath=HasPath(v1,v2);
     Flag();
     if(hasNbrPath==0)
        {  return;
        }
    v1->printflag=1;
    printf(" %c\n",v1->Vertex_Name);
     if (v1==v2)
       {
        return ;
       }
     else
     {
       struct Edge*EdgeCurr=v1->edgelist;
       while (EdgeCurr!= NULL)
           {

            int hasNbrPath=HasPath(EdgeCurr->VertexHolder,v2);
            Flag();
            if(hasNbrPath==1)
             {
              if( EdgeCurr->VertexHolder->printflag==-1)
                 break;
             }
            EdgeCurr=EdgeCurr->EdgeNext;

           }
           PrintPath(EdgeCurr->VertexHolder,v2);
     }
}

void push(struct Vertex*data)
{
    struct Cycle_Stack* temp;                                  // declare temp node type pointer variable
    temp = (struct Cycle_Stack*)malloc(sizeof(struct Cycle_Stack));
    temp->V=data;
    temp->Next=NULL;
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->Next= top;
        top = temp;
    }
}
struct Vertex*pop()
{
    struct Cycle_Stack* curr = top; //declare node type pointer variable curr with assigned value of start
    int flag=0;
    if (top==NULL)
    {
        printf("stack underflow");
    }else{
        top = curr->Next;
        struct Vertex*a = curr ->V;
        delete(curr);
        return a;
    }

    if(flag==0)
    {
        printf("\nYour value does not exist \n");
    }
}
Cycle(struct Vertex*v1)
{
    int flag=0;
    if(Graph==NULL)
    {
        return 0 ;
    }
    push(v1);
    v1->visited=0;
    if(v1->edgelist==NULL)
     {
         v1->visited=1;
         pop();
     }
    else
    {
        struct Edge*EdgeCurr=v1->edgelist;
        while(EdgeCurr!=NULL)
        {
           if(EdgeCurr->VertexHolder->visited==0)
              {
                  return 1;
              }

           if(EdgeCurr->VertexHolder->visited==-1)
             {
                 flag=Cycle(EdgeCurr->VertexHolder);
                 return flag;
             }

            EdgeCurr=EdgeCurr->EdgeNext;
        }
    }

}

int main()
{
    int a,count;
    char v1,v2;
    while(1)
    {
        printf ("\n\nchoose an option: \n1-AddVertex\n2-Add Edge\n3-Out Degree\n4-In Degree\n5-FindNeighbour\n6-Remove Edge\n7-Remove Vertex\n8-Cyclic\n9-Path\n10-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                AddVertex();
                break;
            }
            case 2:
            {
                ADDEdge();
                break;
            }
           case 3:
            {
                printf("Enter the vertex Name: ");
                cin>>v1;
                count=FindOutDegree(v1);
                if(count != -1)
                printf("\nThe Vertex %c has OutDegree: %d",v1,count);
                break;
            }
            case 4:
            {
                 printf("Enter the vertex Name: ");
                cin>>v1;
                count=FindInDegree(v1);
                if(count != -1)
                printf("\nThe Vertex %c has InDegree: %d",v1,count);
                break;
            }
            case 5:
            {
                printf("Enter the vertex Name: ");
                cin>>v1;
                FindNeighbour(v1);
                break;
            }

            case 6:
            {
                printf("Enter Vertex 1(source) Name: ");
                cin>>v1;
                printf("Enter Vertex 2 (Destination) Name: ");
                cin>>v2;
                RemoveEdge(v1,v2);
                break;
            }

            case 7:
            {
                printf("Enter the vertex Name: ");
                cin>>v1;
                RemoveVertex(v1);
                break;
            }
             case 8:
                {
                 Flag();
                 int c;
                 c=Cycle(Graph);
                 if(c==1)
                 printf("\n\nIs Cyclic");
                 else
                 printf("\n\nIt is not Cyclic");
                 break;
                }
            case 9:
            {

                Flag();
                printf("Enter Vertex 1(source) Name: ");
                cin>>v1;
                printf("Enter Vertex 2 (Destination) Name: ");
                cin>>v2;
                struct Vertex *V1=FindVertex(v1);
                struct Vertex *V2=FindVertex(v2);
                PrintPath(V1,V2);
                break;
            }
            case 10:
            {
                exit(a);
            }
           }
    }

}
