//Implement Queue Operations Using Arrays.

 #include<stdio.h>
 #include<stdlib.h>

 int queue[10];
 int insert(int queue[], int val);
 int delete_que(int queue[]);
 int display(int queue[]);
 int front = -1, rear = -1;

 int main ()
{
    int ch,val;

    printf("\n*********QUEUE operations using Array*********\n");

    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n 1.ENQUEUE AN ELEMENT");
        printf("\n 2.DEQUEUE AN ELEMENT");
        printf("\n 3.DISPLAY THE ELEMENTS IN QUEUE");
        printf("\n 4.EXIT");
        printf("\n Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\nEnter the Element to be enqueue on queue:");
                    scanf("\n%d",&val);
                    insert(queue,val);
                    printf("\n %d Value inserted\n",val);
                    break;

            case 2: val=delete_que(queue);
                    if(val != -1)
                     printf("\n %d value deleted from Queue\n", val);
                    else
                     printf("\n The value stored at top of Queue is: %d", val);
                    break;

            case 3: display(queue);
                    break;

            case 4: exit(0);
                    break;

            default:printf("\nEnter valid choice??\n");
        }
    }
    while(ch <= 4);

    return 0;
}

int insert(int queue[], int val)
{
    if(rear == queue-1)
    {
        printf("\nQUEUE OVERFLOW\n");

        return 0;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear+1;
    }
    queue[rear] = val;
}

int delete_que(int queue[])
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("\n QUEUE UNDERFLOW\n");

        return -1;

    }
    else
    {
        val = queue[front];

        if(front == rear)
        {
            front = -1;
            rear = -1 ;
        }
        else
        {
            front = front + 1;
        }
        return val;

    }
}

int display(int queue[])
{
    int i;

    if(rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\n Items in the Queue\n");

        for(i=front;i<=rear;i++)
        {
            printf(" %d",queue[i]);
            printf("\n");
        }
    }
}
