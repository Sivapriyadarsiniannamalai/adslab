#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void main()
{
 struct Node{
 int data;
  struct Node *next;
 };
  int choice;
  struct Node *head=NULL, *newNode, *temp;
  while(choice)
 {
  newNode = (struct Node *)malloc(sizeof (struct Node));
  printf("Enter data:");
  scanf("%d",&newNode->data);
  newNode->next = NULL;
  if(head == NULL)
  {
   head = temp = newNode;
  }
  else
  {
   temp->next = newNode;
   printf("Do you want to contin ue (0,1)?");
   scanf("%d",&choice);
   temp = head;
   while(temp!=0)
   {
    printf("%d\n",temp->data);
    temp = temp->next;
   }

  }
   getch();
  }
 }