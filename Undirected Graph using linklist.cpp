#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Vertex
{
    char Vertex_Name;
    struct Vertex *next;
    struct Edge *edgelist;
    int visited ;
    int printflag; //Never assign value here ,its no use.
} *Graph=NULL;
;

struct Edge
{
    int weight;
    struct Edge *EdgeNext;
    struct Vertex *VertexHolder;
};
struct Path
{
    struct Vertex* V1;
    struct Path *link;
}*top=NULL;

struct Cycle_Queue
{
    struct Vertex* V;
    struct Cycle_Queue *Next;
}*front=NULL;

void AddVertex()
{
    struct Vertex *temp;
    temp = (struct Vertex*)malloc(sizeof(struct Vertex));
    printf("Enter your Vertex Name:");
    cin>>temp->Vertex_Name; //Scanf is not working with char
    temp->next=NULL;
    temp->visited=-1;
    temp->edgelist=NULL;
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
void swap(struct Vertex**a,Vertex**b)
{
     struct Vertex *t=*a;
	*a=*b;
	*b=t;
}
void ADDEdge()
{
    char v1,v2;
    int weight;
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
                printf("\nEnter Edge weight:");
                scanf("%d",&weight);
               for(int i=1;i<=2;i++)
               {
                    struct Edge*EdgeTemp;
                    EdgeTemp=(struct Edge*)malloc(sizeof(struct Edge));
                    EdgeTemp->weight=weight;
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
                    if(curr==Holder)
                        break;
                    swap(&Holder,&curr);//To switch Holder address with curr
              }
            }
}
void RemoveEdge(char v1,char v2)
{
    int flag=0;
    struct Vertex* VertexCurr=FindVertex(v1);
    struct Vertex* Holder=FindVertex(v2);
    if(VertexCurr==NULL || Holder==NULL)
    {
        return;
    }
    if(VertexCurr->edgelist==NULL)
    {
        printf("\nThere is no edge between these vertices");
        return;
    }
    for(int i=1;i<=2;i++)
    {
        struct Edge*EdgeCurr=VertexCurr->edgelist;
        struct Edge*EdgePrev;
        if (EdgeCurr->VertexHolder==Holder)
        {
            printf("\nThe Edge from \'%c\'to \'%c\' is deleted!",VertexCurr->Vertex_Name,EdgeCurr->VertexHolder->Vertex_Name);
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
                    printf("\nThe Edge from \'%c\'to \'%c\' is deleted",VertexCurr->Vertex_Name,EdgeCurr->VertexHolder->Vertex_Name);
                    EdgePrev->EdgeNext=EdgeCurr->EdgeNext;
                    flag=1;
                    free(EdgeCurr);
                    break;
                }
                EdgeCurr=EdgeCurr->EdgeNext;
                EdgePrev=EdgePrev->EdgeNext;
            }
        }
        if(VertexCurr==Holder)
            break;
        swap(&Holder,&VertexCurr);
    }
    if(flag==0)
    {
        printf("\nThere is no edge between these Vertices");
    }
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
void RemoveVertex(char vertex)
{
   struct Vertex* VertexCurr=FindVertex(vertex);
   if(VertexCurr==NULL)
            return;
   if(VertexCurr->edgelist!=NULL)
   {
   struct Edge*EdgeCurr=VertexCurr->edgelist;
   while(EdgeCurr!=NULL)
   {
      struct Edge *temp=EdgeCurr;
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
        while(prev->next->Vertex_Name!=VertexCurr->Vertex_Name)
        {
       prev=prev->next;
        }
        prev->next=VertexCurr->next;
        free(VertexCurr);
   }
   printf("\n\nThe Vertex %c is now deleted ",vertex);

}
int FindDegree(char Vertex)
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
    {   if(curr==EdgeCurr->VertexHolder)
            count=count+2;
        else
           count=count+1;
        EdgeCurr=EdgeCurr->EdgeNext;
    }
    return count;
    }
}
void EnQueue(struct Vertex*data)
{
    struct Cycle_Queue *rear;                                  // declare temp node type pointer variable
    rear = (struct Cycle_Queue*)malloc(sizeof(struct Cycle_Queue));
    rear->V=data;
    rear->Next=NULL;
    if (front == NULL)
    {
        front = rear;

    }
    else
    {
        struct Cycle_Queue* curr = front; //declare node type pointer variable curr with assigned value of start
        while(curr->Next!=NULL)
        {
            curr = curr->Next;
        }
        curr->Next=rear;
    }
}
struct Vertex* DeQueue()
{
    struct Cycle_Queue* curr = front; //declare node type pointer variable curr with assigned value of start
    if (front==NULL)
    {
        printf("\nQueue underflow");
    }else{
        front = curr->Next;
        struct Vertex* a = curr->V;
        delete(curr);
        return a;
    }
}

int Cycle()
{
    struct Vertex *V1=Graph;
    struct Edge* EdgeCurr;
    V1->visited=1;
    while( V1->next!=NULL)
    {

          if(front !=NULL)
          {
              V1=DeQueue();
              V1->visited=1;
              printf("\nThe pop value is: %c",V1->Vertex_Name);

          }
          EdgeCurr=V1->edgelist;
          while(EdgeCurr!=NULL)
          {
              if(EdgeCurr->VertexHolder->visited==-1)
              {
                  printf("\nEdgePushed :%c",EdgeCurr->VertexHolder->Vertex_Name);
                  EnQueue(EdgeCurr->VertexHolder);
                  EdgeCurr->VertexHolder->visited = 0;
              }
              else if(EdgeCurr->VertexHolder->visited==0)
              {
                  return 1;
              }
              EdgeCurr=EdgeCurr->EdgeNext;

           }
           if(front==NULL)
                {
                    printf("Not cyclic");
                    return 0;
                }
           printf("\nThe visited are: %c",V1->Vertex_Name);
    }
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

int main()
{
    int a,count;
    char v1,v2;
    while(1)
    {
        printf ("\n\nchoose an option: \n1-AddVertex\n2-Add Edge\n3 Degree\n4-FindNeighbour\n5-Remove Edge\n6-Remove Vertex\n7-Find Path\n8-Cycle\n9-exit\n");
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
                count=FindDegree(v1);
                if(count != -1)
                printf("\nThe Vertex %c has Degree: %d",v1,count);
                break;
            }

            case 4:
            {
                printf("Enter the vertex Name: ");
                cin>>v1;
                FindNeighbour(v1);
                break;
            }

            case 5:
            {
                printf("Enter Vertex 1(source) Name: ");
                cin>>v1;
                printf("Enter Vertex 2 (Destination) Name: ");
                cin>>v2;
                RemoveEdge(v1,v2);
                break;
            }

            case 6:
            {
                printf("Enter the vertex Name: ");
                cin>>v1;
                RemoveVertex(v1);
                break;
            }
           case 7:
                {
                printf("Enter Vertex 1(source) Name: ");
                cin>>v1;
                printf("Enter Vertex 2 (Destination) Name: ");
                cin>>v2;
                struct Vertex *V1=FindVertex(v1);
                struct Vertex *V2=FindVertex(v2);
                PrintPath(V1,V2);
                break;
                }

            case 8:
                {
                    int c;
                    c=Cycle();
                    if(c==1)
                    {
                    printf("\n\nIs Cyclic");
                    }
                }
            case 9:
               {

                exit(a);
               }
        }
    }

}

