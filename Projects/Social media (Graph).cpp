#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct User
{
    char Username[20];
    char gmail[30];
    char Password[30];
    struct User*next;
    struct User*prev;
    struct Connect *FriendsList;

} *Network=NULL;

struct Connect
{
    struct Connect *Next;
    struct Connect *Prev;
    struct User *UserAddress;
    int status;
};
struct User* SearchUser(char gmail[20],struct User *Curr)
{
    int ans;
    if(Curr==NULL)
         return NULL;
    ans=strcmp(Curr->gmail,gmail);
    if(ans==0)
        return Curr;

    else
       {
        Curr=SearchUser(gmail,Curr->next);
        return Curr;
       }

}
struct User* CreateAccount(struct User* node)
{
   if(node==NULL)
   {   struct User *temp;
       temp = (struct User*)malloc(sizeof(struct User));
       printf("\nEnter UserName: ");
       scanf("%s",&temp->Username);
       printf("\nEnter gmail: ");
       scanf("%s",&temp->gmail);
       struct User*check=SearchUser(temp->gmail,Network);
       if(check!=NULL)
       {
           printf("This Gmail Already Exist");
           return NULL;
       }
       printf("Enter Password: ");
       scanf("%s",&temp->Password);
       temp->next=NULL;
       temp->prev=NULL;
       temp->FriendsList=NULL;
       return temp;
    }
   else
   {
       node->next=CreateAccount(node->next);

   }
   if(node->next!=NULL)
       node->next->prev=node;
   return  node;
}
struct Connect* SearchFriendlist(struct User *User1,struct User *User2)
{
    if(User1==NULL || User2==NULL)
    {    printf("\n Not Registered");
         return NULL;
    }
    else if(User1==User2)
    {
        printf("\nYou Can't be friend with yourself");
        return NULL;
    }
    struct Connect *curr=User1->FriendsList;
    if(User1->FriendsList!=NULL)
    {
    while(curr!=NULL)
    {
        if (curr->UserAddress==User2)
        {
            return curr;
        }
        curr=curr->Next;
    }
    }
    return NULL;
}

int IsFreind(char gmail[20],char gmail2[20])
{
    struct User * User1=SearchUser(gmail,Network);
    struct User * User2=SearchUser(gmail2,Network);
    struct Connect *Curr=SearchFriendlist(User1,User2);
    if(Curr==NULL)
        return -1;
    else if(Curr->status==1)
    {   printf("User \"%s\" and User \"%s\" are  Friend",User1->gmail,User2->gmail);
        return 1;
    }
    else
        return 0;
}
int HasSentFreindRequest(char gmail[20],char gmail2[20])
{
    struct User * User1=SearchUser(gmail,Network);
    struct User * User2=SearchUser(gmail2,Network);
    struct Connect *Curr=SearchFriendlist(User1,User2);
    if(Curr ==NULL)
        return -1;
    else if(Curr->status==-1)
    {   printf("The User \"%s\" is in your  \"SentFriendRequest List\"",User2->gmail);
        return 1;
    }
    else
        return 0;
}
int HasFreindRequest(char gmail[20],char gmail2[20])
{
     struct User * User1=SearchUser(gmail,Network);
     struct User * User2=SearchUser(gmail2,Network);
    struct Connect *Curr=SearchFriendlist(User1,User2);
    if(Curr ==NULL)
        return -1;
    if(Curr->status==0)
    {   printf("The User \"%s\" is in your \"FriendRequest List\"",User2->gmail);
        return 1;
    }
    else
        return 0;
}

void SentFriendRequest(struct User* User1,struct User *User2,int status)
{
  if(User1==NULL || User2==NULL)
            {printf("\nNot Registered");
            return;}
  else if(IsFreind(User1->gmail,User2->gmail)==1||HasFreindRequest(User1->gmail,User2->gmail)==1 || HasSentFreindRequest(User1->gmail,User2->gmail)==1)
                return;
  else
   {
       struct Connect *Friend;
       Friend = (struct Connect*)malloc(sizeof(struct Connect));
       Friend->UserAddress=User2;
       Friend->Next=NULL;
       Friend->Prev=NULL;
       Friend->status=status;
       if(User1->FriendsList==NULL)
       { User1->FriendsList=Friend;
       }
       else
       {
        struct Connect* curr =User1->FriendsList;
        while(curr->Next!=NULL)
        {curr=curr->Next;}
        curr->Next=Friend;
        Friend->Prev=curr;
        }
   }
   if(status== 0)
        return;
   SentFriendRequest(User2,User1,0);
}

void AcceptFriendRequest(struct User* User1,struct User *User2)
{
    if(User1==NULL || User2==NULL)
    {
        printf("\nAccount Doesn't Exist");
        return;
    }
    if(IsFreind(User1->gmail,User2->gmail) !=0 || HasSentFreindRequest(User1->gmail,User2->gmail) !=0)
       {    printf("\nThere is Nothing to be Accepted");
           return;
       }
    else if(HasFreindRequest(User1->gmail,User2->gmail)==1)
    {
    struct Connect*User1_Friend=SearchFriendlist(User1,User2);
    struct Connect*User2_Friend=SearchFriendlist(User2,User1);
        User2_Friend->status=1;
        User1_Friend->status=1;
    printf("\nFriend Request Accepted");
    }

}
void ViewFriendlist(struct User* user1)
{
    if(user1==NULL)
    {
        printf("\nAccount Doesn't Exist");
        return;
    }
    struct Connect *curr=user1->FriendsList;
    int flag=0;
    if(curr==NULL)
    {
        printf("\n\"You have NO Friends Yet\"");
        return;
    }
    printf("Your Friends are:");
    while(curr!=NULL)
    {
        if(curr->status==1)
           {
            printf("\nName :%s and gmail is: %s",curr->UserAddress->Username,curr->UserAddress->gmail);
            flag=1;
           }
        curr=curr->Next;
    }
    if(flag==0)
        printf("\n\"You have NO Friends Yet\"");
}
void ViewFriendRequests(struct User* user1)
{
    if(user1==NULL)
    {
        printf("\nAccount Doesn't Exist");
        return;
    }
    struct Connect *curr=user1->FriendsList;
    int flag=0;
    if(curr==NULL)
    {
        printf("\n\"You have NO FriendRequests\"");
        return;
    }
    printf("Your Friends Requests are:");
    while(curr!=NULL)
    {
        if(curr->status==0 )
           {
            printf("\nName :%s and gmail is: %s",curr->UserAddress->Username,curr->UserAddress->gmail);
            flag=1;
           }
        curr=curr->Next;
    }
    if(flag==0)
        printf("\n\"You have NO FriendRequests\"");
}

void ViewSentFriendRequest(struct User* user1)
{
      if(user1==NULL)
    {
        printf("\nAccount Doesn't Exist");
        return;
    }
    struct Connect *curr=user1->FriendsList;
    int flag=0;
    if(curr==NULL)
    {
        printf("\n\"You haven't Sent Any Friend Request\"");
        return;
    }
    printf("Your Sent FriendRequests are:");
    while(curr!=NULL)
    {
        if(curr->status==-1 )
           {
            printf("\nName :%s and gmail is: %s",curr->UserAddress->Username,curr->UserAddress->gmail);
            flag=1;
           }
        curr=curr->Next;
    }
    if(flag==0)
        printf("\n\"You haven't Sent Any Friend Request\"");
}

void ViewRegisteredUsers()
{
    struct User* curr=Network;
    if(Network==NULL)
    {
        printf("\n\"You have No Registered Users\"");
        return;
    }
    printf("Registered Users are:");
    while(curr!=NULL)
    {   printf("\nName :%s and gmail is: %s",curr->Username,curr->gmail);
        curr=curr->next;
    }
}
void GetMutualFriends(struct Connect* User1_Friends,struct Connect* User2_Friends,int Count)
{
    struct Connect*Curr=User1_Friends;
    if(User1_Friends==User2_Friends)
    {  printf("\nEnter  gmails of Different Users");
       return;
    }
    if(User1_Friends==NULL || User2_Friends==NULL)
    {
        printf("\nTotal Mutual Friends ARE: %d",Count);
        return;
    }

    while(Curr!=NULL)
    {
        if(Curr->UserAddress==User2_Friends->UserAddress &&Curr->status==1 && User2_Friends->status==1)
           {
            Count =Count+1;
            printf("\nName : %s and gmail: %s",Curr->UserAddress->Username,Curr->UserAddress->gmail);
           }
         Curr=Curr->Next;
    }
    GetMutualFriends(User1_Friends,User2_Friends->Next,Count);
}
void Remove(struct User* User1 ,struct User* User2)
{
    struct Connect*User_Friend=SearchFriendlist(User1,User2);
    if(User_Friend==NULL)
    {
        return;
    }
    if(User1->FriendsList==User_Friend)
    {
        User1->FriendsList=User_Friend->Next;
        if(User_Friend->Next!=NULL)
             User_Friend->Next->Prev=NULL;
        free(User_Friend);
    }
    else
    {   if(User_Friend->Next!=NULL)
                  User_Friend->Next->Prev=User_Friend->Prev;
        User_Friend->Prev->Next=User_Friend->Next;

        free(User_Friend);
    }
    Remove(User2,User1);
}
void RemoveFriend(struct User*User1,struct User*User2)
{   int ans=IsFreind(User1->gmail,User2->gmail);
    if(ans==1)
    {
        Remove(User1,User2);
        printf("\n ........But the person is  REMOVED from the list NOW !!!............!!!");
    }
    else if(ans==0)
    {
         printf("\nThe %s is not in your Friends List ",User1->gmail);
    }
}
void RemoveFriendRequest(struct User*User1,struct User*User2)
{   int ans=HasFreindRequest(User1->gmail,User2->gmail);
    if(ans==1)
    {
        Remove(User1,User2);
        printf("\n ........But the person is  REMOVED from the list NOW !!!............!!!");
    }
    else if(ans==0)
    {
        printf("\nThe %s is not in your FriendsRequest List ",User1->gmail);

    }
}
void RemoveSentFriendRequest(struct User*User1,struct User*User2)
{   int ans=HasSentFreindRequest(User1->gmail,User2->gmail);
    if(ans==1)
    {
        Remove(User1,User2);
        printf("\n ........But the person is  REMOVED from the list NOW !!!............!!!");
    }
    else if(ans==0)
    {
         printf("\nThe %s is not in your SentFriendRequests List ",User1->gmail);

    }
}
void DeleteAccount(struct User* User1)
{
    if (User1==NULL)
    {
        printf("\nAccount Doesn't Exist");
        return;
    }
    if(User1->FriendsList!=NULL)
    {
        struct Connect*User1_Friend=User1->FriendsList;
        while(User1_Friend!=NULL)
        {

            struct Connect*temp=User1_Friend;
            User1_Friend=User1_Friend->Next;
            Remove(User1,temp->UserAddress);
        }

    }
    if(User1==Network)
    {
        Network=User1->next;
        free(User1);
    }
    else
    {

        User1->prev->next=User1->next;
        if(User1->next!=NULL)
         {User1->next->prev=User1->prev;}
        free(User1);
    }

}
int main()
{
    int a,count;
    char gmail[30],gmail2[30];
    while(1)
    {
        printf ("\n\nChoose an option: \n1-CreateAccount\n2-Search User\n3-Sent Friend Request\n4-Accept Friend Request\n5-View FriendsList\n6-View FriendRequests\n7-View SentFriendRequest\n8-View Registered Accounts\n9-IsFriend\n10-MutualFriend\n11-RemoveFriend\n12-Remove FriendRequest\n13-Remove Sent FriendRequest\n14-Delete Account\n15-exit\n");
        scanf ("%d", &a);
        switch (a)
        {
            case 1:
            {
                Network=CreateAccount(Network);
                break;
            }
            case 2:
            {
                printf("\nEnter Gmail:");
                scanf("%s",&gmail);
                struct User* temp=SearchUser(gmail,Network);
                if(temp!=NULL)
                {
                    printf("\nThis User \"%s\" with gmail \"%s\"Exist",temp->Username,temp->gmail);
                }
                else
                {
                    printf("\nThe user doesn't Exist");
                }
                break;
            }
           case 3:
            {
                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                cin>>gmail2;
                struct User * User1=SearchUser(gmail,Network);
                struct User * User2=SearchUser(gmail2,Network);
                SentFriendRequest(User1,User2,-1);
                break;
            }
            case 4:
            {
                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                 cin>>gmail2;
                struct User * User1=SearchUser(gmail,Network);
                struct User * User2=SearchUser(gmail2,Network);
                AcceptFriendRequest(User1,User2);
                break;
            }
          case 5:
            {
                printf("Enter your Gmail:");
                cin>>gmail;
                struct User * User1=SearchUser(gmail,Network);
                ViewFriendlist(User1);
                break;
            }

            case 6:
            {
                printf("Enter your Gmail:");
                cin>>gmail;
                struct User * User1=SearchUser(gmail,Network);
                ViewFriendRequests(User1);
                break;
            }

            case 7:
            {
                printf("Enter your Gmail:");
                cin>>gmail;
                struct User * User1=SearchUser(gmail,Network);
                ViewSentFriendRequest(User1);
                break;;
            }
             case 8:
                {
                 ViewRegisteredUsers();
                 break;
                }
            case 9:
            {

                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                cin>>gmail2;
                int c=IsFreind(gmail,gmail2);
                if(c==0)
                    printf("You are not Friends");
                break;
            }
            case 10:
                {
                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                cin>>gmail2;
                struct User * User1=SearchUser(gmail,Network);
                struct User * User2=SearchUser(gmail2,Network);
                if(User1!=NULL || User2!=NULL)
                    GetMutualFriends(User1->FriendsList,User2->FriendsList,0);
                else
                    printf("Account Doesn't Exist");
                break;
                }
            case 11:
                {
                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                cin>>gmail2;
                struct User * User1=SearchUser(gmail,Network);
                struct User * User2=SearchUser(gmail2,Network);
                RemoveFriend(User1,User2);
                break;
                }
            case 12:
                {
                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                cin>>gmail2;
                struct User * User1=SearchUser(gmail,Network);
                struct User * User2=SearchUser(gmail2,Network);
                RemoveFriendRequest(User1,User2);
                break;
                }
            case 13:
                {
                printf("Enter your Gmail:");
                cin>>gmail;
                printf("Enter your Friend  Gmail:");
                cin>>gmail2;
                struct User * User1=SearchUser(gmail,Network);
                struct User * User2=SearchUser(gmail2,Network);
                RemoveSentFriendRequest(User1,User2);
                break;
                }

            case 14:
                {
                printf("Enter your Gmail:");
                cin>>gmail;
                struct User * User1=SearchUser(gmail,Network);
                DeleteAccount(User1);
                break;
                }
            case 15:
            {
                exit(a);
            }
           }
    }

}
