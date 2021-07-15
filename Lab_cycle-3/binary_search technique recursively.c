//BinarySearchTechnique Using Recursively

#include<stdio.h>
#include<stdlib.h>
//function prototype
int binary_search(int[], int, int, int);
//main function
int main()
{
   int num, i, key, position;
   int low, high, list[20];
   printf("\n Enter the total number of elements: ");
   scanf("%d", &num);
   printf("\n Enter the elements of list: ");
   for (i = 0; i < num; i++)
   {
      scanf("%d", &list[i]);
   }
   low = 0;
   high = num - 1;
   printf("\n Enter element to be searched : ");
   scanf("%d", &key);
   //function call
   position = binary_search(list, key, low, high);
   if (position != -1)
   {
      printf("\n Number present at %d", (position + 1));
   } else
      printf("\n The number is not present in the list");
   return 0;
}

// Binary search function for binary search
int binary_search(int a[], int x, int low, int high)
{
   int mid;
   if (low > high)
      return -1;
   mid = (low + high) / 2;
   if (x == a[mid])
   {
      return (mid);
   } else if (x < a[mid])
    {
      binary_search(a, x, low, mid - 1);
   } else {
      binary_search(a, x, mid + 1, high);
   }
}
