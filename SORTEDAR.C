#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void sortArray(int arr[],int n)
 {
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
   for(j=0;j<n-i-1;j++)
  {
    if(arr[j]>arr[j+1]);
     {
      temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
     }
   }
  }
 }
void mergeArrays(int arr1[],int arr2[],int n1,int n2,int merged[])
 {
  int i=0,j=0,k=0;
  while(i<n1&&j<n2)
  {
   if(arr1[i]<arr2[j])
   {
    merged[k++]=arr1[i++];
   }else
   {
    merged[k++]=arr2[j++];
   }
  }
   while(i<n1)
   {
    merged[k++] = arr2[i++];
   }
   while(j<n2)
   {
    merged[k++]=arr2[j++];
   }
 }
int main()
 {
  int n1,n2,i,arr1[3],arr2[3],merged[6];
  clrscr();
  printf("Enter the size of the first array:");
  scanf("%d",&n1);
  printf("enter elements for the first array:",n1);
  for(i=0;i<n1;i++)
  {
   scanf("%d",&arr1[i]);
  }
  printf("enter the size of the second array:");
  scanf("%d",&n2);
  printf("Enter elements for the second array:",n2);
  for(i=0;i<n2;i++)
  {
   scanf("%d",&arr2[i]);
  }
  sortArray(arr1,n1);
  sortArray(arr2,n2);
  printf("sorted first array : ");
  for(i=0;i<n1;i++)
  {
    printf("%d",arr1[i]);
  }
  printf("sorted second array:");
  for(i=0;i<n2;i++)
  {
     printf("%d",arr2[i]);
  }
  printf("\n");
  mergeArrays(arr1,arr2,n1,n2,merged);
  printf("Merged array:");
  for(i=0;i<n1+n2;i++)
  {
     printf("%d",merged[i]);
  }
  printf("\n");
  getch();
  return 0;
}
