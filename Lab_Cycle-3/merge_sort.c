//Merge_Sort

#include <stdio.h>
#include <conio.h>
//function prototype
int merge_sort(int arr[],int lb,int ub);
//main function
int main()
{
  int arr[10];
  int n,i;
  printf("--------------MERGE SORTING--------------");
  printf("\n Enter total no. of elements : ");
scanf("%d", &n);
printf("\n Enter %d numbers: ", n);
for (i =  0 ; i < n; i++)
{
scanf("%d", &arr[i]);
}
  printf("\nBefore sorted:");
    for(i=0;i<n;i++)
  printf("\t %d",arr[i]);
  //function call
  merge_sort(arr,0,n-1);
  printf("\nAfter Sorted:");
    for(i=0;i<n;i++)
  printf("\t %d",arr[i]);
  getch();
return 0;
}

//Function Declaration
int merge_sort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        partition(arr,lb,mid,mid+1,ub);

    }
}

int partition(int arr[],int a,int b,int c,int d)
{
  int temp[30];
  int i,j,k;
  i=a,j=c,k=0;

  while(i <= b && j <= d)
  {
    if(arr[i] < arr[j])
    temp[k++] = arr[i++];
  else
    temp[k++] = arr[j++];
  }

  //collect remaining elements
  while(i<=b)
  temp[k++] = arr[i++];

  while(j<=d)
  temp[k++] = arr[j++];

   for(i = a, j=0; i<=d; i++, j++)
        arr[i]=temp[j];
}



