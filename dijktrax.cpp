#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

struct Vertex
{
    char Vertex_Name;
    struct Vertex *next;
    struct Edge *edgelist;
    float Distance;
    int visited;
} *Graph=NULL;

struct Edge
{
    int weight;
    struct Edge *EdgeNext;
    struct Vertex *VertexHolder;
};

struct Queue
{
    struct Vertex* V1;
    struct Queue* link;
};
struct Queue* front = NULL; // global variable start, equate start with null

struct Dijsktra
{
    struct Vertex *V1;
    float Distance;
    struct Dijsktra* link;

};
struct Dijsktra*D_Start=NULL;

void AddVertex()
{
    struct Vertex *temp;
    temp = (struct Vertex*)malloc(sizeof(struct Vertex));
    printf("Enter your Vertex Name:");
    cin>>temp->Vertex_Name; //Scanf is not working with char
    temp->next=NULL;
    temp->visited=-1;
    temp->edgelist=NULL;
    temp->visited=-1;
    temp->Distance=INFINITY;
    if(Graph==NULL)
        {Graph=temp;
         temp->Distance=0;
        }
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
void EnQueue(struct Vertex *data)
{
    struct Queue* rear;                                  // declare temp node type pointer variable
    rear = (struct Queue*)malloc(sizeof(struct Queue));
    rear->V1=data;
    rear->link=NULL;
    if (front == NULL)
    {
        front = rear;

    }

    else
    {
        struct Queue* curr = front; //declare node type pointer variable curr with assigned value of start
        while(curr->link!=NULL)
        {
            curr = curr->link;
        }
        curr->link=rear;

        struct Queue*value=front;
        while(value->link!=NULL)

        {    struct Vertex*temp;

            if(value->V1->Distance>rear->V1->Distance)
            {
               temp=rear->V1;
               rear->V1=value->V1;
               value->V1=temp;
            }
            value=value->link;

        }
	}

}


struct Vertex* DeQueue()
{
    struct Queue* curr = front; //declare node type pointer variable curr with assigned value of start
    if (front==NULL)
    {
        printf("\nQueue underflow");
    }else{
        front = curr->link;
        struct Vertex *a = curr ->V1;
        delete(curr);
        return a;
    }
}
void Shortest_Distance(struct Vertex* Vertex1,float Distance)
{
    struct Dijsktra*temp;
	temp=(struct Dijsktra*)malloc(sizeof(Dijsktra ));
	temp ->V1=Vertex1;
	temp->Distance=Distance;
	temp->link=NULL;
 	if(D_Start== NULL)
    {
		D_Start=temp;
		printf("InIF %d",D_Start);
    }
	else
    {   printf("In Else %d",D_Start);
		struct Dijsktra*curr=D_Start;
		while (curr->link != NULL)
		{
			curr=curr->link;
		}
	curr->link=temp;

	}
}
deletion(struct Vertex *todelete)
{
	struct Queue *prev;
	struct Queue*curr=front;
	if(front->V1==todelete)
	{
		front=front->link;
		free(curr);

	}
	else
	{
		curr=front->link;
		prev=front;
		while(curr!=NULL)
		{
			if (curr->V1==todelete)
			{
				prev->link=curr->link;
				free(curr);
				break;
			}
		    curr=curr->link;
		    prev=prev->link;
		}

	}
}
struct Vertex* VertexInQueue(char data)
{
    int flag=0;
    if(front == NULL)
       {
        printf("\n No Vertex Exist" );
        return NULL;
       }
    else
      {
        struct Queue*curr=front;
        while(curr!=NULL)
        {
            if(curr->V1->Vertex_Name==data)
            {
                return curr->V1;
            }
            curr=curr->link;
        }
    }
    if(flag==0)
        {
            printf("\nVertex not found ");
            return NULL;
        }
}

void Apply_Dijsktra()
{
    struct Vertex *DijsktraV=Graph;
    struct Edge *EdgeCurr;
    float D;
    DijsktraV->visited=1;
    while( DijsktraV->next!=NULL)
    {
        if(front !=NULL)
          {
              DijsktraV=DeQueue();
              DijsktraV->visited=1;
              printf("\nThe visited value is: %c", DijsktraV->Vertex_Name);

          }
          EdgeCurr= DijsktraV->edgelist;
          while(EdgeCurr!=NULL)
          {  if(EdgeCurr->VertexHolder->visited!=1)
              {
                D=DijsktraV->Distance+EdgeCurr->weight ;
                if(EdgeCurr->VertexHolder->Distance==INFINITY)
                {  printf("\nEdgePushed :%c",EdgeCurr->VertexHolder->Vertex_Name);

                  EdgeCurr->VertexHolder->Distance=D;
                  EnQueue(EdgeCurr->VertexHolder);

                }
                else
                {
                  struct Vertex*data=VertexInQueue(EdgeCurr->VertexHolder->Vertex_Name);
                  if(D<data->Distance)
                  {
                      deletion(data);
                      EnQueue(EdgeCurr->VertexHolder);
                      EdgeCurr->VertexHolder->visited = 0;
                  }
                }
              }
              EdgeCurr=EdgeCurr->EdgeNext;
          }


              Shortest_Distance(DijsktraV,DijsktraV->Distance);
              if(front==NULL)
                return;


    }
}

void PrintList()
{
    if(D_Start==NULL)
    {
        printf("\nlist empty");
    }
    else
    {
        printf("\nYour Shortest Path is... ");
        struct Dijsktra *curr = D_Start; //declare node type pointer variable curr with assigned value of start
        printf("\nVertex:\t\tDistance:");
        while(curr!=NULL)
          {
            printf("\n%c\t\t\t%f", curr->V1->Vertex_Name,curr->Distance);
            curr = curr->link;
           }
    }
}

int main()
{
    int a;

    while(1)
    {
        printf ("\n\nchoose an option: \n1-AddVertex\n2-Add Edge\n3-Dijtrax\n4-Print\nExit\n");
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
                Apply_Dijsktra();
                break;
            }
            case 4:
            {
                PrintList();

            }
            case 5:
            {
                exit(a);
            }
        }
    }
}




