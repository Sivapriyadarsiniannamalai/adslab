#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
  
struct Node{
 int data;
 struct Node* prev;
 struct Node* next;
};

struct Node* createNode(int data)
 { 
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}
void insertEnd(struct Node **head,int data)
 {
  struct Node *newNode=createNode(data);
  struct Node*temp=*head;
if(*head==NULL)
{
 *head=newNode;
 return;
}
while(temp->next!=NULL)
{
 temp=temp->next;
}
temp->next=newNode;
newNode->prev=temp;
}
void deleteNode(struct Node **head, int key)
{
 struct Node *temp=*head;
 if(temp==NULL)
 {
  printf("\n list is empty");
  return;
}
while(temp!=NULL && temp->data!=key)
{
 temp=temp->next;
}
if(temp==NULL)
{
 printf("\n %d not found in the key",key);
 return;
}
if(temp==*head)
 {
  *head=temp->next;
}
if(temp->next!=NULL)
{
 temp->next->prev=temp->prev;
}
if(temp->prev!=NULL)
{
 temp->prev->next=temp->next;
}
free(temp);
printf("\n %d deleted from the list",key);
}
void searchNode(struct Node *head,int key)
{
  struct Node *temp=head;
  int pos=1;
  while(temp!=NULL)
 {
  if(temp->data==key)
   {
    printf("\n The number found at %d position in the list",pos, key);
    return;
   }
   temp=temp->next;
   pos++;
}
printf("\n %d is not found in the list",key);
}
void display(struct Node *head){
struct Node *temp=head;
printf("\n Doubly linked list ");
while(temp!=NULL)
{
 printf("\n %d",temp->data);
 temp=temp->next;
}
printf("\n");
}
void main()
{
 struct Node *head=NULL;
 int choice,value;
 clrscr();
 while(1)
 {
  printf("\n 1.Insertnode");
  printf("\n 2.Deletenode");
  printf("\n 3.Searchnode");
  printf("\n 4.Displaylist");
  printf("\n 5.Exit");
  printf("\n Enter your choice:");
  scanf("\n %d",&choice);
  switch(choice)
  {
    case 1:printf("\n Enter the elements to insert");
           scanf("\n%d",&value);
           insertEnd(&head,value);
           break;
    case 2:printf("\n Enter the elements to delete");
           scanf("\n%d",&value);
           deleteNode(&head,value);
           break;
    case 3:printf("\n Enter the elements to search");
           scanf("\n%d",&value);
           searchNode(head,value);
           break;
    case 4:display(head);
           break;
    case 5:exit(0);
           break;
    default:printf("\n Invalid choice");
}
}
getch();
}
