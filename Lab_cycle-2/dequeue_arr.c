 #include <stdio.h>
#include<stdlib.h>
#define size 100

  int dequeue[size];
  int front=-1, rear=-1;
  int enqueue_front(int);
  int enqueue_rear(int);
  int display();
  int getfront();
  int getrear();
  int dequeue_front();
  int dequeue_rear();
 int main()
{
 int ch,x;
 do
{
 printf("\n 1.Enqueue_front");
 printf("\n 2.Enqueue_rear");
 printf("\n 3.Display");
 printf("\n 4.Getfront");
 printf("\n 5.Getrear");
 printf("\n 6.Dequeue_front");
 printf("\n 7.Dequeue_rear");
 printf("\n Enter your choice : ");
 scanf("%d",&ch);
 switch(ch)
{
 case 1:enqueue_front(x);
             break;
 case 2:enqueue_rear(x);
            break;
 case 3:display();
            break;
 case 4:getfront();
            break;
 case 5:getrear();
           break;
 case 6:dequeue_front();
            break;
 case 7:dequeue_rear();
            break;
}
}while(ch<=7);
 return 0;
}
 int enqueue_front(int x)
{
    printf("\n Enter an Element:");
    scanf("%d",&x);
    if((front==0 && rear==size-1) || (front==rear+1))
    {
        printf("\n Dequeue is full");
    }
    else if((front==-1) && (rear==-1))
    {
        front=rear=0;
        dequeue[front]=x;
    }
    else if(front==0)
    {
        front=size-1;
        dequeue[front]=x;
    }
    else
    {
        front=front-1;
        dequeue[front]=x;
    }
}

 int enqueue_rear(int x)
{
     printf("\n Enter an Element:");
     scanf("%d",&x);
    if((front==0 && rear==size-1) || (front==rear+1))
    {
        printf("Dequeue is full");
    }
    else if((front==-1) && (rear==-1))
    {        rear=0;
        dequeue[rear]=x;
    }
    else if(rear==size-1)
    {
        rear=0;
        dequeue[rear]=x;
    }
    else
    {
        rear++;
        dequeue[rear]=x;
    }

}

 int display()
{
    int i=front;
    printf("\n Elements in a dequeue : ");

    while(i!=rear)
    {
        printf("%d",dequeue[i]);
        i=(i+1)%size;
    }
     printf("%d",dequeue[rear]);
}

 int getfront()
{
    if((front==-1) && (rear==-1))
    {
        printf("\n Dequeue is empty");
    }
    else
    {
        printf("\n The value of the front is: %d", dequeue[front]);
    }

}

 int getrear()
{
    if((front==-1) && (rear==-1))
    {
        printf("\n Dequeue is empty");
    }
    else
    {
        printf("\n The value of the rear is: %d", dequeue[rear]);
    }

}

 int dequeue_front()
{
    if((front==-1) && (rear==-1))
    {
        printf("\n Dequeue is empty");
    }
    else if(front==rear)
    {
        printf("\n The deleted element is %d", dequeue[front]);
        front=-1;
        rear=-1;
    }
     else if(front==(size-1))
     {
         printf("\n The deleted element is %d", dequeue[front]);
         front=0;
     }
     else
     {
          printf("\n The deleted element is %d", dequeue[front]);
          front=front+1;
     }
}

 int dequeue_rear()
{
    if((front==-1) && (rear==-1))
    {
        printf("\n Dequeue is empty");
    }
    else if(front==rear)
    {
        printf("\n The deleted element is %d", dequeue[rear]);
        front=-1;
        rear=-1;
    }
     else if(rear==0)
     {
         printf("\n The deleted element is %d", dequeue[rear]);
         rear=size-1;
     }
     else
     {
          printf("\n The deleted element is %d", dequeue[rear]);
          rear=rear-1;
     }
}
