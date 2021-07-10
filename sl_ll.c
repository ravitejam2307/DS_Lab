
//Singly Linked List Menu Driven Operations.

#include <stdio.h>
#include <stdlib.h>
struct slinklist
{
int data;
struct slinklist *next;
};
typedef struct slinklist node;
node *start = NULL;
node *create_ll(node *);
node *display(node *);
node *insert_beg(node *);
node *insert_end(node *);
node *insert_pos(node *);
node *delete_beg(node *);
node *delete_end(node *);
node *delete_node(node *);
node *delete_list(node *);
void traverse_lr(node *);
void traverse_rl(node *);
node *sort_list(node *);
node *search_list(node *);
int count_node(node *);

int main()
{
int ch;
do
{
printf("\n\n********Main Menu********");
printf("\n 1: Create a list");
printf("\n------------------------------");
printf("\n 2: Display the list");
printf("\n------------------------------");
printf("\n 3: Add a node at the beginning");
printf("\n 4: Add a node at the end");
printf("\n 5: Add a node at specific Position");
printf("\n------------------------------");
printf("\n 6: Delete a node at beginning");
printf("\n 7: Delete a node at end");
printf("\n 8: Delete a given node");
printf("\n 9: Delete the entire list");
printf("\n------------------------------");
printf("\n 10: Traverse from Left to Right");
printf("\n 11: Traverse from Right to Left");
printf("\n------------------------------");
printf("\n 12: Sort the list");
printf("\n 13: Search node in the List");
printf("\n 14: Count nodes in the List");
printf("\n 15: EXIT");
printf("\n\n Enter your option : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
       start=create_ll(start);
       printf("\n SINGLE LINKED LIST CREATED");
break;
case 2: start=display(start);
break;
case 3: start=insert_beg(start);
        printf("\n NODE INSERTED AT BEGIN");
break;
case 4: start=insert_end(start);
        printf("\n NODE INSERTED AT END");
break;
case 5: start=insert_pos(start);
        printf("\n NODE INSERTED AT MIDDLE");
break;
case 6: start = delete_beg(start);
        printf("\n NODE DELETED AT BEGIN");
break;
case 7: start=delete_end(start);
        printf("\n NODE DELETED AT END");
break;
case 8: start=delete_node(start);
        printf("\n GIVEN NODE HAS BEEN DELETED");
break;
case 9:  start=delete_list(start);
         printf("\n LINKED LIST DELETED");
break;
case 10:  printf("\n The List is (Left to Right):");
         traverse_lr(start);
break;
case 11: printf("\n The List is(Right to Left):");
         traverse_rl(start);
          printf("NULL");
break;
case 12: start=sort_list(start);
         printf("\n LINKED LIST AFTER SORTED");
break;
case 13: start = search_list(start);
break;
case 14: printf("\n No.Of Nodes: %d",count_node(start));
break;
}
}while(ch==14);
return 0;
}


node *create_ll(node *start)
{
 node *newnode,*temp;
 int data,n;
 printf("\n\nHOW MANY NODES U WANT TO CREATE:");
       scanf("%d",&n);
       for(int i=0;i<n;i++)
       {
       printf("\nENTER THE DATA:");
       scanf("%d",&data);
 newnode=(node *)malloc(sizeof(node));
  newnode->data=data;
 newnode->next=NULL;
 if(start==NULL)
       {
        start=newnode;
       }
    else
       {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
       }
       }
       return start;
}


 node *display(node *start)
{
   node *ptr;
       printf("\n No.Of Nodes: %d",count_node(start));
   if(start==NULL)
      {
       printf("\n List is Empty");
      }
  else
      {
       ptr=start;
       printf("\n List elements are ");
       while(ptr!=NULL)
      {
       printf("%d -->", ptr -> data);
       ptr = ptr -> next;
      }
       printf("NULL");
       return start;
       }
}

 node *insert_beg(node *start)
{
  node *newnode;
  int data;
  if(start==NULL)
    {
     start = newnode;
    }
  else
    {
     printf("\n Enter the data : ");
     scanf("%d", &data);
     newnode = (node *)malloc(sizeof(node));
  newnode -> data = data;
   newnode->next=start;
   start = newnode;
   return start;
    }
}


node *insert_end(node *start)
{
  node *ptr, *newnode;
  int data;
   newnode = (node *)malloc(sizeof(node));
   if(start==NULL)
    {
     start = newnode;
    }
  else
    {
    printf("\n Enter the data : ");
    scanf("%d", &data);
     newnode -> data = data;
    newnode -> next = NULL;
     ptr = start;
  while(ptr -> next != NULL)
     ptr = ptr -> next;
     ptr -> next = newnode;
     return  start;
    }
}

node *insert_pos(node *start)
{
  node *temp,*newnode;
  int i,data,pos;
 newnode = (node *)malloc(sizeof(node));
 if(newnode == NULL)
     printf("Unable to allocate memory.");
 else
  {
       printf("Enter data to insert at middle position of the list: ");
       scanf("%d", &data);
       newnode->data=data;
       printf("Enter the position to insert new node: " );
       scanf("%d", &pos);
     temp = start;
     for(i=2;i<pos;i++)
     {
          temp=temp->next;
         if(temp==NULL)
            printf("Empty List");
     else
     {
     newnode->next=temp->next;
      temp->next=newnode;
       printf("\n Node inserted at %d position\n",pos);
     }
           start = display(start);
     }
  }
}


   node *delete_beg(node *start)
{
   node *ptr;
   if(start==NULL)
    {
      printf("Empty List");
    }
   else
    {
      ptr = start;
      start = start -> next;
      free(ptr);
      return start;
    }
}

  node *delete_end(node *start)
{
  node *ptr, *preptr;
      ptr = start;
  if(start==NULL)
    {
    printf("Empty List");
    return start;
    }
  else
    {
  while(ptr -> next != NULL)
    {
    preptr = ptr;
    ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);
    return start;
    }
}


node *delete_node(node *start)
{
   node *ptr, *preptr;
   int data;
      printf("\n Enter the value of the node which has to be deleted :");
      scanf("%d", &data);
      ptr = start;
   if(ptr -> data == data)
   {
      start = delete_beg(start);
   }
   else
   {
   while(ptr -> data != data)
     {
      preptr = ptr;
      ptr = ptr -> next;
     }
      preptr -> next = ptr -> next;
      free(ptr);
      return start;
   }
}

   node *delete_list(node *start)
{
   node *ptr;
   if(start!=NULL)
    {
     ptr=start;
   while(ptr != NULL)
     {
     printf("\n %d is to be deleted next", ptr -> data);
     start = delete_beg(ptr);
     ptr = start;
     }
    }
}


   void traverse_lr(node *start)
{
   node *temp;
   if(start==NULL)
    {
     printf("\n Empty List");
    }
   else
    {
     temp=start;
   while(temp!=NULL)
     {
     printf("%d-->",temp->data);
     temp = temp->next;
     }
    }
     printf("NULL");
}


  void traverse_rl(node *start)
{
  if(start == NULL)
   {
    return;
   }
   else
   {
       traverse_rl(start->next);
        printf("%d -->",start->data);
   }
}


 node *sort_list(node *start)
{
  node *ptr1, *ptr2;
  int temp;
    ptr1 = start;
  while(ptr1 -> next != NULL)
  {
    ptr2 = ptr1 -> next;
  while(ptr2 != NULL)
    {
  if(ptr1 -> data > ptr2 -> data)
     {
    temp = ptr1 -> data;
    ptr1 -> data = ptr2 -> data;
    ptr2 -> data = temp;
     }
    ptr2 = ptr2 -> next;
   }
    ptr1 = ptr1 -> next;
  }
    start = display(start);
  return start;
}


node *search_list(node *start)
{
 node *ptr;
 int ele,i=0,flag;
 ptr=start;
 if(ptr==NULL)
 {
     printf("\nEmpty List");
 }
    else
    {
        printf("Enter element which you want to search: ");
        scanf("%d",&ele);
        while(ptr!=NULL)
        {
            if(ptr->data==ele)
            {
                printf("Element found at Location %d",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1)
        {
            printf("\nElement not found\n");
        }
        return start;
        }
}

  int count_node(node *start)
{
  int count=0;
  while(start != NULL)
  {
    count++;
    start = start -> next;
  }
  return count;
}



