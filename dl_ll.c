
//Double Linked list Menu Driven Operations

#include<stdio.h>
#include<stdlib.h>

struct dlinklist
{
struct dlinklist *prev;
int data;
struct dlinklist *next;
};
typedef struct dlinklist node;
node *start = NULL;

node *create_dll(node *);
node *display(node *);
node *dll_insert_beg(node *);
node *dll_insert_end(node *);
node *dll_insert_pos(node *);
node *dll_delete_beg(node *);
node *dll_delete_end(node *);
node *dll_delete_node(node *);
node *dll_delete_list(node *);
void  dll_traverse_lr(node *);
void  dll_traverse_rl(node *);
node *sort_list(node *);
node *search_list(node *);
int count_node(node *);
int main()
{
int ch,n;
do
{
printf("\n\n********Main Menu********");
printf("\n 1. Create");
printf("\n 2. Display");
printf("\n------------------------------");
printf("\n 3. Insert a node at beginning ");
printf("\n 4. Insert a node at end");
printf("\n 5. Insert a node at specific Position");
printf("\n------------------------------");
printf("\n 6. Delete a node at beginning");
printf("\n 7. Delete a node at Last");
printf("\n 8. Delete a node at specific position");
printf("\n 9: Delete the entire list");
printf("\n------------------------------");
printf("\n 10. Traverse the list from Left to Right");
printf("\n 11. Traverse the list from Right to Left ");
printf("\n------------------------------");
printf("\n 12: Sort the list");
printf("\n 13: Search node in the List");
printf("\n 14: Count the Number of nodes in the List");
printf("\n 15: EXIT");
printf("\n\n Enter your option : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
       start = create_dll(start);
       printf("\n DOUBLE LINKED LIST CREATED");
break;
case 2: start = display(start);
break;
case 3: start = dll_insert_beg(start);
        printf("\n NODE INSERTED AT BEGIN");
break;
case 4: start=dll_insert_end(start);
        printf("\n NODE INSERTED AT END");
break;
case 5: start=dll_insert_pos(start);
        printf("\n NODE INSERTED AT MIDDLE");
break;
case 6: start = dll_delete_beg(start);
        printf("\n NODE DELETED AT BEGIN");
break;
case 7: start=dll_delete_end(start);
        printf("\n NODE DELETED AT END");
break;
case 8: start=dll_delete_node(start);
        printf("\n GIVEN NODE HAS BEEN DELETED");
break;
case 9: start=dll_delete_list(start);
         printf("\n LINKED LIST DELETED");
break;
case 10:printf("The List is(Left to Right):");
        dll_traverse_lr(start);
        printf("NULL");
break;
case 11:printf("The List is(Right to Left):");
        dll_traverse_rl(start);
        printf("NULL");
break;
case 12: start = sort_list(start);
         printf("\n LINKED LIST AFTER SORTED");
break;
case 13: start = search_list(start);
break;
case 14: printf("\n No.Of Nodes: %d",count_node(start));
break;
}
}
while(ch==14);
return 0;
}

node *create_dll(node *start)
{
node *newnode,*temp;
int n,data;
 printf("\n\nHOW MANY NODES U WANT TO CREATE:");
       scanf("%d",&n);
for(int i = 0; i < n; i++)
{
printf("\n Enter data: ");
scanf("%d", &data);
 newnode=(node *)malloc(sizeof(node));
 newnode->data=data;
 newnode->prev=NULL;
 newnode->next=NULL;
if(start == NULL)
{
start = newnode;
}
else
{
temp = start;
while(temp -> next)
temp = temp -> next;
temp -> next = newnode;
newnode -> prev = temp;
}
}
 return start;
}

node *display(node *start)
{
   node *ptr;
   printf("\n No.Of Nodes: %d",count_node(start));
    ptr = start;
       if(start==NULL)
      {
       printf("\n List is Empty");
      }
  else
      {
         printf("\n List elements are ");
     do {
       printf("%d -->", ptr -> data);
       ptr = ptr -> next;
      }
   while(ptr!=NULL);
       printf(" NULL");
      }
  return start;
}


node *dll_insert_beg(node *start)
{
node *newnode;
int data;
newnode=(node *)malloc(sizeof(node));
if(start == NULL)
start = newnode;
else
{
    printf("Enter the data: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode -> next = start;
    start -> prev = newnode;
    start = newnode;
}
return start;
}

node *dll_insert_end(node *start)
{
node *ptr,*newnode;
int data;
newnode=(node *)malloc(sizeof(node));
if(start == NULL)
{
start = newnode;
}
else
{
printf("Enter the data: ");
scanf("%d",&data);
newnode->data=data;
newnode -> prev=NULL;
newnode -> next=NULL;
ptr=start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = newnode;
newnode -> prev = ptr;
return start;
}
}

node *dll_insert_pos(node *start)
{
  node *temp,*newnode;
  int i,data,pos;
 newnode = (node *)malloc(sizeof(node));
 if(newnode == NULL)
     {
     printf("Unable to allocate memory.");
     }
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
        {
            printf("Empty List");
        }
     else
     {
     newnode->prev=temp;
     newnode->next=temp->next;
     temp->next->prev=newnode;
     temp->next=newnode;
     }
      printf("\n Node inserted at %d position\n",pos);
     }
    start = display(start);
  }
}




node *dll_delete_beg(node *start)
{
node *temp;
if(start == NULL)
{
printf("\n Empty list");
return start;
}
else
{
temp = start;
start = start -> next;
start -> prev = NULL;
free(temp);
}
return start;
}


node *dll_delete_end(node *start)
{
node *temp;
if(start == NULL)
{
printf("\n Empty list");
}
else
{
temp = start;
while(temp -> next != NULL)
temp = temp -> next;
temp -> prev -> next = NULL;
free(temp);
return start;
temp = NULL;
}
}



 node *dll_delete_node(node *start)
{
   node *ptr, *temp;
   int data;
   printf("\n Enter the value of the node which has to be deleted :");
      scanf("%d", &data);
      ptr = start;
    if(ptr -> data == data)
   {
      start = dll_delete_beg(start);
   }
   else
   {
    while(ptr -> data != data)
      ptr = ptr -> next;
      if(ptr->next==NULL)
     {
       printf("Empty list");
       return start;
     }
     else if(ptr->next->next==NULL)
     {
        ptr->next=NULL;
     }
     else
     {
      temp = ptr -> next;
      ptr->next=temp->next;
      temp->next->prev=ptr;
      free(temp);
      return start;
   }
}
}

  node *dll_delete_list(node *start)
{
   node *ptr;
   if(start!=NULL)
    {
     ptr=start;
   while(ptr != NULL)
     {
     printf("\n %d is to be deleted next", ptr -> data);
     start = dll_delete_beg(ptr);
     ptr = start;
     }
    }
}

void dll_traverse_lr(node *start)
{
node *temp;
temp = start;
if(start == NULL)
{
printf("\n Empty List");
}
else
{
while(temp != NULL)
{
printf("%d --> ", temp -> data);
temp = temp -> next;
}
}
}


void dll_traverse_rl(node *start)
{
  if(start == NULL)
   {
    return;
   }
   else
   {
       dll_traverse_rl(start->next);
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
  start=display(start);
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
  return (count);
}


















