#include<stdio.h>
#include<conio.h>


int queue[3],front= -1,rear= -1,n = 3;

void queue_enqueue(int data)
{
 if (front==n-1)
 {
  printf("\n queue is full");
 }
 else{
  rear++;
  printf("\n %d inserted ",data);
  if (front==-1)
   {
    front++;
   }
  }
 }

void queue_dequeue()
{
 int i;
 if (front==-1)
 {
  printf("\n queue is empty");
  return;
 }
 else if(front==rear)
 {
  printf("\n deleted item = %d",queue[front]);
  front= -1;
  rear= -1;
 }
 else
 {
 printf("\n Deleted item = %d",queue[front]);
 front++;
 for(i=front;i<=rear;i++)
 queue[i-1]=queue[i];
 front--;
 rear--;
 }
}

void queue_display()
{
int i;
if(front==-1)
{
printf("\n queue is empty");
}
else
{
 printf("\n queue element are :");
 for(i=front;i<=rear;i++)
 {
  printf("%d",queue[i]);
 }
}
}
void main()
{
 int choice,s;
 clrscr();
 do{
  printf("\n 1.Insertion:");
  printf("\n 2.Deletion:");
  printf("\n 3.Display:");
  printf("\n 4.Exit:");
  printf("\n Enter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {

  case 1: printf("Enter the element to insert:");
	  scanf("%d",&s);
	  queue_enqueue(s);
	   break;

  case 2: queue_dequeue();
	   break;
  case 3: queue_display();
	    break;
  case 4: exit(0);
	  break;
   default : printf("Wrong choice!!!!");
  }
 }
  while(choice!=4);
}


