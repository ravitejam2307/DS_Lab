//Quick Sort

#include<stdio.h>
#include<conio.h>
//function prototype
int quick_sort(int arr[],int lb,int ub);
//main function
int main()
{
 int arr[30];
 int i,n;
      printf("--------------QUICK SORTING--------------\n");
      printf("\n Enter total no. of elements : ");
scanf("%d", &n);
printf(" Enter %d numbers:",n);
for (i=0;i<n;i++)
{
scanf("%d", &arr[i]);
}
      printf("\n Before sorted:");
        for(i=0; i<n; i++)
      printf("\t %d",arr[i]);
         //function call
        quick_sort(arr,0,n-1);
      printf("\n Sorted Data:");
        for(i=0; i<n; i++)
      printf("\t %d",arr[i]);
 getch();
 return 0;
}

//function declaration
int quick_sort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid = partition(arr,lb,ub);
        quick_sort(arr,lb,mid-1);
        quick_sort(arr,mid+1,ub);
    }
}

int partition(int arr[],int lb,int ub)
{
    int left,right,pivot,temp;
        left=lb;
        right=ub;
        pivot=arr[lb];
        while(left<right)
        {
           while(arr[left]<=pivot && left<ub)
            left++;
           while(arr[right]>pivot && right>=lb)
            right--;
           if(left < right)
           {
               temp=arr[left];
               arr[left]=arr[right];
               arr[right]=temp;
           }
        }
        temp=arr[lb];
        arr[lb]=arr[right];
        arr[right]=temp;
        return right;
}
