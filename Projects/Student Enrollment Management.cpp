#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<iostream> //for cin and cout
#include<ctype.h>
using namespace std;

struct course
{
    char Name[20];
    char Instructor[20];
    int No;
    struct course*next;
    struct student*start;
}*Cstart=NULL;

struct student
{
    char Name[20];
    int No;
    int Class;
    struct student* link;
};
void EnrollCourse()
{
    struct course*temp;
    temp=(struct course*)malloc(sizeof(struct course));
    printf("Enter your Course No :");
    scanf("%d",&temp->No);
    printf("\nEnter your Course Name: "); //getline didn't work on it
    scanf("%s",&temp->Name);
    printf("\nEnter your Instructor Name: ");
    scanf("%s",&temp->Instructor);
    temp->next=NULL;
    temp->start=NULL;
    if(Cstart==NULL)
    {
        Cstart=temp;
    }
    else
	{
		struct course*curr=Cstart;
		while (curr->next != NULL)
		{
			curr=curr->next;
		}
	curr->next=temp;
   }
}
void EnrollStudent()
{
    int data,flag=0;
    printf ("Enter the course no: ");
    scanf("%d",&data);
    struct course*curr=Cstart;
    while(curr!=NULL)
     {
         if(curr->No==data)
         {
            struct student*stdtemp;
            stdtemp=(struct student*)malloc(sizeof(struct student));
            printf("Enter student no:");
            scanf("%d",&stdtemp->No);
            printf("Enter student name: ");
            scanf("%s",&stdtemp->Name);
            printf("Enter student Class : ");
            scanf("%d",&stdtemp->Class);
            stdtemp->link=NULL;
            if(curr->start==NULL)
            {
                   curr->start=stdtemp;
                   printf("%d", curr->start);
            }
            else
            {
              struct student*stdcurr=curr->start;
              while (stdcurr->link != NULL)
		      {
			   stdcurr=stdcurr->link;
              }
	          stdcurr->link=stdtemp;
            }
            flag=1;
            break;
         }
         curr=curr->next;
    }
        if(flag==0)
        {
            printf("\nCourse no not found ");
        }
}
void SearchCourse()
{
    int data,flag=0;
    printf("Enter the course NO: ");
    scanf("%d",&data);
    if(Cstart == NULL)
        printf("No Course has been Enrolled");
    else
    {
        struct course*curr=Cstart;
        while(curr!=NULL)
        {
            if(curr->No==data)
            {printf("\nThis CourseNO %d is Enrolled %d",curr->No,curr);
                if(curr->start==NULL)
                    printf("\nStudents haven't enrolled in this course");
                else
                { struct student*stdcurr=curr->start;
                  printf("\nThe students enrolled Roll no are:");
                  while(stdcurr!=NULL)
                  {
                     printf("\n%d",stdcurr->No);
                     stdcurr=stdcurr->link;
                  }
                }
                flag=1;
                break;
            }
            curr=curr->next;
            if(flag==0)
        {
            printf("\nCourse no not found ");
        }
        }
     }
}
void SearchStudent()
{

}


int main()
{


    int a,value;
    while(1)
    {
        printf ("\nchoose an option: \n1-Course Enrollment\n2-Student Enrollment\n3-SearchCourse\n4-Minimum value\n5-Delete\n6-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
               EnrollCourse();
                break;
            }
            case 2:
            {
                EnrollStudent();
                break;
            }
            case 3:
            {
                SearchCourse();
                break;
            }
            /*case 4:
            {
                minimum();
                break;
            }
            case 5:
            {
                deletion();
                break;
            }*/
            case 6:
            {
                exit(a);
            }
        }
    }

}

