//Heap_sort

#include<stdio.h>
int temp;
int swap_largest(int arr[], int n, int i)
{
int largest = i; // Initialize largest as root
int left = 2*i + 1;
int right = 2*i + 2;

// If left child is larger than root
if (left < n && arr[left] > arr[largest])
largest = left;

// If right child is larger than largest
if (right < n && arr[right] > arr[largest])
largest = right;

// If largest is not root
if (largest != i)
{
temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;

// Recursively call the swap_largest
swap_largest(arr, n, largest);
}
}
int heapsort(int arr[], int n)
{
  int i;
// Build heap from an unsorted array (rearrange array)
for (int i = n / 2 - 1; i >= 0; i--)
swap_largest(arr, n, i);

// One by one extract an element from heap
for (int i = n - 1; i >= 0; i--)
{

// Move current root to end
temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;

// call swap_largest on the reduced heap
swap_largest(arr, i, 0);
}
}

int print(int arr[], int n)
{
for(int i = 0; i < n; i++)
{
printf("\t %d ", arr[i]);
}
}

//Main Function
int main()
{
int arr[10],i,n;
 printf("--------------HEAP SORTING--------------");
printf("\n Enter total no. of elements : ");
scanf("%d", &n);
printf("\n Enter %d numbers: ", n);
for (i =  0 ; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("\n Before Sorted Elements:");
print(arr,n);
//function call
heapsort(arr,n);
printf("\n  After Sorted Elements:");
print(arr,n);
return 0;
}


