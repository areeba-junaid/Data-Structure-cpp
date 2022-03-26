#include <stdio.h>
#include<conio.h>
struct student //struct
{
    char name[10];
	int marks;
    float GPA;
} st[4];
void linearsearch (int size) //linear function
{
    int search,flag=0;
    printf("Enter the marks you want to search");
    scanf("%d",&search);
    for (int i=0;i<size;i++)
	{
		if (search==st[i].marks)
		{

		printf("value found");
		flag=1;
		break;
	   }
	}
	if (flag==0)
	    printf("value not found");

}
void binarysearch(int size) //binary function
{
    int search;
	int L=0,R=size-1,MP=(L+R)/2,flag=0;
	printf("\nEnter the value you want to search: ");
	scanf("%d",&search);

	while(L<=R)
	{
		if(search==st[MP].marks)
		{
			printf("\nvalue found");
			flag=1;
			break;
		}
		else
		{
			if (search<st[MP].marks)
			   R=MP-1;
			if (search>st[MP].marks)
			   L=MP+1;

		}
			MP=(L+R)/2;

	}
	if (flag==0)
	    printf("value not found");

}

void selection(int size)
{
    int min_index,i,j,flag=0,c;
    float temp;

    for(i=0;i<size-1;i++)
    {   min_index=i;
        for(j=i+1;j<size;j++)
        {
            if(st[min_index].GPA>st[j].GPA)
            {
                 min_index=j;
                 flag=1;
            }
        }
       if(flag==1)
       {
           temp=st[i].GPA;
           st[i].GPA=st[min_index].GPA;
           st[min_index].GPA=temp;
       }
    }
    printf("Your sorted values are:\n{");
    for(i=0;i<size;i++)
    {
     printf("%f",st[i].GPA);
     if(i==size-1)
            printf("}");
     else
            printf(",");
    }
}
void bubble(int size)
{
    int i=0,j;
    float temp;
    for(i=size-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {

            if(st[j].GPA>st[j+1].GPA)
            {
              temp=st[j].GPA;
              st[j].GPA=st[j+1].GPA;
              st[j+1].GPA=temp;

            }
        }
    }
    printf("\nYour sorted values are:\n{");
    for(i=0;i<size;i++)
    {
     printf("%f",st[i].GPA);
     if(i==size-1)
            printf("}");
     else
            printf(",");
    }
}
void bubble1(int size)
{
    int i=0,j;
    float temp;
    for(i=size-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {

            if(st[j].marks>st[j+1].marks)
            {
              temp=st[j].marks;
              st[j].marks=st[j+1].marks;
              st[j+1].marks=temp;

            }
        }
    }
    printf("\nYour sorted values are:\n{");
    for(i=0;i<size;i++)
    {
     printf("%f",st[i].marks);
     if(i==size-1)
            printf("}");
     else
            printf(",");
    }
}

int main()
{
    int num,size=4;
    for(int i=0;i<size;i++)
    {
        printf("Enter name,marks ,GPA:");
        fflush(stdin);
        scanf("%s %d %f",&st[i].name,&st[i].marks,&st[i].GPA);
    }
    printf("\nEnter a number from 1 to 5:");
    scanf("%d",&num);
    while(num >5)
    {
        printf("\nEnter a number from 1 to 5:");
        scanf("%u",&num);
    }
    if (num==1)
       linearsearch(size);
    else if(num==2)
    {
        bubble1(size);
        binarysearch(size);
    }
    else if(num==3)
        bubble(size);
    else if(num==4)
        selection(size);
    else if( num==5)
        printf("The program is ended");

}
