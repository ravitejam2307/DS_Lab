//Implement Stack Operations Using Arrays.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int st[10], top=-1;
int push(int st[], int val);
int pop(int st[]);
int display(int st[]);
int main()
{
int val, ch;
printf("\n*********Stack operations using Array*********\n");
do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. PUSH AN ELEMENT");
printf("\n 2. POP AN ELEMENT");
printf("\n 3. DISPLAY THE ELEMENTS IN STACK");
printf("\n 4. EXIT");
printf("\n Enter your option: ");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("\n Enter the Element to be pushed on stack: ");
        scanf("%d", &val);
        push(st, val);
        printf(" %d value pushed\n",val);
        break;
case 2: val = pop(st);
        if(val!= -1)
        printf("\n %d value deleted from stack\n", val);
        else
        printf("\n The value stored at top of stack is: %d", val);
        break;
case 3: display(st);
        break;
default:printf("\nEnter valid choice??\n");
}
}
  while(ch <= 4);
  return 0;
}

 int push(int st[], int val)
{
     if(top == st-1)
    {
     printf("\n STACK OVERFLOW");
    }
 else
    {
     top++;
     st[top] = val;
    }
 return val;
}

 int pop(int st[])
{
 int val;
   if(top == -1)
  {
   printf("\n STACK UNDERFLOW");
   return -1;
  }
else
  {
   val = st[top];
   top--;
   return val;
}
}

 int display(int st[])
{
 int i;
   if(top == -1)
   printf("\n STACK IS EMPTY");
else
 {
  printf("\n Items in the Stack");
  for(i=top;i>=-1;i--)
  printf("\n %d",st[i]);
  printf("\n"); // Added for formatting purposes
 }
}
