#include<stdio.h>
#include<stdlib.h>

struct Node

{
 int data;
 struct Node *left;
 struct Node *right;
};
 struct Node *createNode(int data)
 {
  struct Node  *newNode=(struct Node *)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
 }
 struct Node *insert(struct Node *root,int data)
 {
  if(root==NULL)
   {
    return createNode(data);
   }
   if(data<root->data)
    {
     root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
     root->right=insert(root->right,data);
    }
   return root;
 }
 struct Node *search(struct Node *root,int data)
   {
    if(root==NULL)
    {
     return 0;
    }
   if(data==root->data)
   {
    return 1;
   }
   else if(data<root->data)
   {
    return search(root->left,data);
   }
   else
   {
    return search(root->right,data);
   }
  }
 struct Node *findMin(struct Node *Node)
  {
   struct Node *current = Node;
    while(current && current->left!=NULL)
    {
     current=current->left;
    }
     return current;
  }
 struct Node *delete(struct Node *root, int data)
  {
   struct Node *temp=findMin(root->right);
   {
    if(root==NULL)
    {
     printf("Node not found.\n");
     return root;
    }
    if(data<root->data)
    {
     root->left=delete(root->left,data);
    }
    else if(data>root->data)
    {
     root->right=delete(root->right,data);
    }
    else
    {
     if(root->left==NULL)
      {
       struct Node *temp=root->right;
       free(root);
       return temp;
      }
     else if(root->right==NULL)
     {
      struct Node *temp=root->left;
      free(root);
      return temp;
     }
     else
     {
      root->data=temp->data;
      root->right=delete(root->right,temp->data);
     }
    return root;
   }
  }
 }
  void displayTree(struct Node *root,int space)
  {
    int i;
    if(root==NULL)
     {
      return;
     }
     space+=10;
     displayTree(root->right,space);
     printf("\n");
     for(i=10;i<space;i++)
     {
      printf(" ");
     }
     printf("%d \n",root->data);
     displayTree(root->left,space);
    }
  void main()
   {
     struct Node *root=NULL;
     int choice,data;
     clrscr();
     while(1)
    {
      printf("\n1.Insert \n2.Delete \n3.DisplayTree \n4.Search \n.5.Exit");
      printf("\n Enter your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
       case 1: printf("Enter data to insert:");
	       scanf("%d",&data);
	       break;
       case 2:  printf("Enter data to delete :");
	       scanf("%d",&data);
	       root=delete(root,data);
	       break;
       case 3: displayTree(root,0);
	       break;
       case 4:  printf("Enter data to search:");
	       scanf("%d",&data);
	       if(search(root,data))
	       {
		printf("%d found in tree",data);
	       }
	       else
	       {
		printf("%d no found in tree",data);
	       }
	       break;
       case 5: exit(0);
	       break;
       default : printf("Invalid choice");
     }
     getch();
    }
  }