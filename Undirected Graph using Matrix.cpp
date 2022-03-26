#include<stdio.h>
#include<iostream>
using namespace std;
const int n=3;
struct Vertex
{
    char data;
};
struct Vertex Graph[n];
int adj_matrix[n][n];

void AddVertex()
{
    for(int i=0;i<n;i++)
    {
        printf("Enter Vertex Name: ");
        cin>>Graph[i].data;
    }
}
int SearchVertex(char Vertex)
{
    int Index,count=0,flag=0;
    for(int i=0;i<n;i++)
    {
        if(Vertex==Graph[i].data)
           {
               Index=i;
               flag=1;
               return Index;
           }
    }
    if(flag==0)
    {
        printf("Vertex Doesn't Exist");
        return -1;
    }
}
int Degree(char Vertex)
{
    int Index,count=0,flag=0;
    Index=SearchVertex(Vertex);
    if(Index==-1)
        return -1;
    for(int j=0;j<n;j++)
    {
        if(adj_matrix[Index][j]==1)
            { if(Index == j)
                {
                    count=count+2;
                }
                else
                {count=count +1;}
            }
    }
    return count;

}
void AddEdge()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)//Symmetric matrix
        {
            printf("\nEnter '1' for Edge between %c to %c and 0 for viseversa :",Graph[i].data,Graph[j].data);
            cin>>adj_matrix[i][j];
            cout<<adj_matrix[i][j];
            adj_matrix[j][i]=adj_matrix[i][j];
        }
    }

}
void FindNeighbour(char Vertex)
{
    int Index,flag=0;
    Index=SearchVertex(Vertex);
    if(Index==-1)
        return;
    printf("\nNeighbours are: ");
    for(int j=0;j<n;j++)
    {
        if(adj_matrix[Index][j]==1)
           {printf("\n%c",Graph[j]);}
    }
}
void RemoveEdge(char Vertex1,char Vertex2)
{
    int Index,flag=0,row,column;
    row=SearchVertex(Vertex1);
    column=SearchVertex(Vertex2);
    if(row==-1 || column==-1)
        return;
    adj_matrix[row][column]=0;
    adj_matrix[column][row]=0;
}
void IsAdjacent(char V1,char V2)
{
  int row,column;
  row =SearchVertex(V1);
  column=SearchVertex(V2);
  if(column==-1||row==-1)
    {return;}
  if(adj_matrix[row][column]==1)
    printf("\nThese Vertex are adjacent");
  else
     printf("\nThe are not Adjacent");
}
int main()
{
    char v,v2;
    int a, check;
    AddVertex();
    for(int i=0;i<n;i++)
    {
        cout<<Graph[i].data<<endl;
    }
    AddEdge();
    while(1)
    {
        printf ("\n\nchoose an option: \n1-Degree\n2-Find Neighbour\n3 Remove Edge\n4-Is Adjacent\n5-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                printf("Enter the Vertex:");
                cin>>v;

                check=Degree(v);
                if(check !=-1)
                {
                    printf("The degree is :%d",check);
                }
                fflush(stdin);
                break;
            }
            case 2:
            {
                printf("Enter the Vertex:");
                cin>>v;
                 FindNeighbour(v);
                 break;
            }
           case 3:
            {
                printf("Enter the vertex1 Name: ");
                cin>>v;
                printf("Enter the vertex2 Name: ");
                cin>>v2;
                RemoveEdge(v,v2);
                break;
            }

            case 4:
            {
                printf("Enter the vertex1 Name: ");
                cin>>v;
                printf("Enter Vertex 2 Name:");
                cin>> v2;
                IsAdjacent(v,v2);
            }

           case 5:
            {
                exit(a);
            }
           }
    }

}


