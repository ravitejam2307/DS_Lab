//Insertion_Sort

#include<stdio.h>
#include<conio.h>
//function prototype
int insertion_sort(int arr[], int n);
//main function
int main()
{
 int arr[10];
 int i,n;
      printf("--------------INSERTION SORTING--------------");
      printf("\n Enter total no. of elements : ");
scanf("%d", &n);
printf("\n Enter %d numbers: ", n);
for (i =  0 ; i < n; i++)
{
scanf("%d", &arr[i]);
}
      printf("\n Before Sorted:");
        for(i=0;i<n;i++)
      printf("\t%d",arr[i]);
      //function call
        insertion_sort(arr,n);
      printf("\n Sorted Data: ");
        for(i=0; i<n; i++)
      printf("\t%d",arr[i]);
   getch();
   return 0;
}

//function declaration
int insertion_sort(int arr[], int n)
{
   int j,temp;

   for(int i=1;i<n;i++)
   {
      temp = arr[i];
      j = i-1;
   while((temp < arr[j]) && (j>=0))
     {
      arr[j+1] = arr[j];
      j--; //j= j - 1;
     }
      arr[j+1] = temp;
       //Iteration process
      printf("\n Iteration %d:",i);
      for(int k=0;k<n;k++)
        printf("\t%d",arr[k]);
   }
}
