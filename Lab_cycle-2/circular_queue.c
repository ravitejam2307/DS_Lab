//Implement Operations on Queue Using Circularly Linked List.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
 int enqueue(int);
 int dequeue();
 int display();


 struct node *front = NULL;
 struct node *rear = NULL;

 int main()
{
	int ch,ele,i,data;
	printf("\n Queue Using Circularly Linked List\n");
	do{
		printf("\n 1.Insert the Data in Queue");
        printf("\n 2.Display the Data in Queue");
        printf("\n 3.Delete the data from the Queue");
        printf("\n 4.Exit");
        printf("\n Enter Your Choice:-");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				   printf("\nEnter the number of data:");
				   scanf("%d",&ele);
				  for(i=0;i<ele;i++)
                  {
                    printf("\nEnter your data:");
				    scanf("%d",&data);
					enqueue(data);
                  }
                   break;
			case 2:display();
				   break;
			case 3:dequeue();
				   break;
			case 4:exit;
				   break;
			default:printf("\nIncorrect Choice");
          }
	}while(ch<=3);
     return 0;
}

  int enqueue(int data) //Insert elements in Queue
 {
	struct node* ptr;//p is a node;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = ptr;
		rear->next = front;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
		ptr->next = front;
	}
 }

  int dequeue() // Delete an element from Queue
{
	struct node* ptr;
	ptr = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else if(front == rear){
		front = rear = NULL;
		free(ptr);
		printf(" %d Element Deleted.\n",ptr->data);
	}
	else{
		front = front->next;
		rear->next = front;
		free(ptr);
		printf(" %d Element Deleted\n",ptr->data);
	}
}
  int display(){ // Print the elements of Queue
	struct node* ptr;
	ptr = front;
	if((front==NULL)&&(rear==NULL))
		printf("\n Queue is Empty");
	else{
            printf("\n Elements in the Queue:\n");
		do{
			printf(" %d\n",ptr->data);
			ptr = ptr->next;
		}while(ptr != front);
	}
}
