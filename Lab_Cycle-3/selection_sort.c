//Selection_Sort

#include<stdio.h>
#include<conio.h>

//function prototype
int selection_sort(int arr[],int n);

//main function
int main()
{
int arr[30];
 int i,n;
      printf("--------------SELECTION SORTING--------------\n");
      printf("\n Enter total no. of elements : ");
scanf("%d", &n);
printf("\n Enter %d numbers: ", n);
for (i =  0 ; i < n; i++)
{
scanf("%d", &arr[i]);
}
      printf("Before sorted: ");
        for(i=0; i<n; i++)
      printf("\t%d",arr[i]);
       selection_sort(arr,n);   //function call
      printf("\nSorted Data: ");
        for(i=0; i<n; i++)
      printf("\t%d",arr[i]);
 getch();
 return 0;
}

//function declaration
int selection_sort(int arr[], int n)
{
int pos,temp;
for(int i = 0; i < (n - 1); i++)
{
pos=i;
for(int j = i + 1; j < n; j++)
{
if(arr[pos]>arr[j])
pos=j;
}
if(pos != i)
{
temp=arr[i];
arr[i]=arr[pos];
arr[pos]=temp;
}
//Iteration Process
printf("\nIteration %d: ",i);
    for(int k = 0;k < n; k++)
    {
    printf("\t%d",arr[k]);
    }
}
}


















































