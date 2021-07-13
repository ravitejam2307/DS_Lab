//Implement Stack Operations Using LinkedList.

#include <stdio.h>
#include <stdlib.h>
struct stack
{
int data;
struct stack *next;
};
    int push();
    int pop();
    int display();
    struct stack *st;//st means stack main node
int main ()
{
    int ch;
        printf("\n*********Stack operations using linked list*********\n");
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Show");
        printf("\n 4.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default:printf("Please Enter valid choice ");
    }
}
while(ch<=4);
return 0;
}

int push()
{
    int ele;

    struct stack *p;//p means a node to pointing a another node(node)
    p = (struct stack*)malloc(sizeof(struct stack));
    if(p == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf(" Enter the value :");
        scanf("%d",&ele);
        if(st==NULL)//l=main node
        {
            p->data = ele;
            p -> next = NULL;
            st=p;
        }
        else
        {
            p->data = ele;
            p->next = st;
            st=p;

        }
        printf(" %d Item pushed\n",ele);

    }
}

int pop()
{
    int ele;
    struct stack *p;
    if (st == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        ele = st->data;
        p = st;
        st = st->next;
        free(p);
        printf(" %d Item popped\n",ele);
        return ele;
    }
}

int display()
{
    int i;
    struct stack *p;
    p=st;
    if(p == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf(" Items in the Stack\n");
        while(p!=NULL)
        {
            printf(" %d\n",p->data);
            p = p->next;
        }
    }
}
