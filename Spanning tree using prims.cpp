#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Vertex
{
    char Vertex_Name;
    struct Vertex *next;
    struct Edge *edgelist;
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
    struct Vertex*V1;
    struct Edge *EdgeHolder;
    struct Queue* link;
};
struct Queue* front = NULL; // global variable start, equate start with null

struct Span
{
    struct Vertex *V1;
    struct Edge *E;
    struct Span *SpanNext;
};
struct Span*SpanStart=NULL;

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
void EnQueue(struct Vertex *V,struct Edge *data)
{
    struct Queue* rear;                                  // declare temp node type pointer variable
    rear = (struct Queue*)malloc(sizeof(struct Queue));
    rear->EdgeHolder=data;
    rear->V1=V;
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

        {    struct Edge*temp1;
             struct Vertex*temp2;

            if(value->EdgeHolder->weight>rear->EdgeHolder->weight)
            {
               temp1=rear->EdgeHolder;
               temp2=rear->V1;
               rear->EdgeHolder=value->EdgeHolder;
               rear->V1=value->V1;
               value->EdgeHolder=temp1;
               value->V1=temp2;

            }
            value=value->link;

        }
	}

}


struct Queue* DeQueue()
{
    struct Queue* curr = front; //declare node type pointer variable curr with assigned value of start
    struct Queue*a;
    if (front==NULL)
    {
        printf("\nQueue underflow");
    }else{
        front = curr->link;
        a = curr ;
        return a;
    }
}
CreateSpan(struct Vertex* Vertex1,struct Edge *EdgeHolder)
{
    struct Span*temp;
	temp=(struct Span*)malloc(sizeof(struct Span));
	temp->V1=Vertex1;
	temp->E=EdgeHolder;
	temp->SpanNext=NULL;
	if(SpanStart== NULL)
    {
		SpanStart=temp;
    }
	else
    {
		struct Span*curr=SpanStart;
		while (curr->SpanNext != NULL)
		{
			curr=curr->SpanNext;
		}
	curr->SpanNext=temp;

	}
}
deletion(struct Edge *todelete)
{
	struct Queue *prev;
	struct Queue*curr=front;
	if(front->EdgeHolder==todelete)
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
			if (curr->EdgeHolder==todelete)
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
struct Edge* FindEdgeWeight(char data)
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
            if(curr->EdgeHolder->VertexHolder->Vertex_Name==data)
            {
                return curr->EdgeHolder;
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

void GetSpanTree()
{
    struct Vertex *SpanV1=Graph;
    struct Edge *EdgeCurr;
    int flag=0;
    while(flag==0)
    {
          SpanV1->visited=1;
          EdgeCurr=SpanV1->edgelist;

          while(EdgeCurr!=NULL)
          {
               if(EdgeCurr->VertexHolder->visited==-1)
               { EdgeCurr->VertexHolder->visited = 0;
                  EnQueue(SpanV1,EdgeCurr);

               }
              else if(EdgeCurr->VertexHolder->visited==0)
              {
                  struct Edge*data=FindEdgeWeight(EdgeCurr->VertexHolder->Vertex_Name);
                  if(EdgeCurr->weight<data->weight)
                  {
                      deletion(data);
                      EnQueue(SpanV1,EdgeCurr);
                      EdgeCurr->VertexHolder->visited = 0;
                  }
              }

              EdgeCurr=EdgeCurr->EdgeNext;

          }
          if(front==NULL)
                {flag=1;
                return;}
           struct Queue *Data = DeQueue();
           CreateSpan(Data->V1,Data->EdgeHolder);
           SpanV1=Data->EdgeHolder->VertexHolder;
           delete(Data);
    }
    return ;
}

void PrintList()
{
    if(SpanStart==NULL)
    {
        printf("\nlist empty");
    }
    else
    {
        printf("\nYour Span list is... ");
        struct Span* curr = SpanStart; //declare node type pointer variable curr with assigned value of start
        while(curr!=NULL)
          {
            printf("\nVertex 1: %c", curr->V1->Vertex_Name);
            printf("\nVertex 2: %c",curr->E->VertexHolder->Vertex_Name);
            printf("\nWeight: %d",curr->E->weight);
            curr = curr->SpanNext;

           }
    }
}

int main()
{
    int a;

    while(1)
    {
        printf ("\n\nchoose an option: \n1-AddVertex\n2-Add Edge\n3-SpanTree\n4-Print\nExit\n");
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
                GetSpanTree();

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




