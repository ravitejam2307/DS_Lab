/*Merge two given linked lists*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};

struct node *create(struct node *start);
struct node *insert_s(struct node *start,int data);
struct node *insert(struct node *start,int data);
void display(struct node *start);
void merge(struct node *p1,struct node *p2);
int main()
{
        struct node *start1=NULL, *start2=NULL;
        start1=create(start1);
        start2=create(start2);

        printf("List1 : ");
        display(start1);
        printf("List2 : ");
        display(start2);
        merge(start1, start2);
        return 0;
}/*End of main()*/

void merge(struct node *p1,struct node *p2)
{
        struct node *start3;
        start3=NULL;

        while(p1!=NULL && p2!=NULL)
        {
                if(p1->data < p2->data)
                {
                        start3=insert(start3,p1->data);
                        p1=p1->next;
                }
                else if(p2->data < p1->data)
                {
                        start3=insert(start3,p2->data);
                        p2=p2->next;
                }
                else if(p1->data==p2->data)
                {
                        start3=insert(start3,p1->data);
                        p1=p1->next;
                        p2=p2->next;
                }
        }
        /*If second list has finished and elements left in first list*/
        while(p1!=NULL)
        {
                start3=insert(start3,p1->data);
                p1=p1->next;
        }
        /*If first list has finished and elements left in second list*/
        while(p2!=NULL)
        {
                start3=insert(start3,p2->data);
                p2=p2->next;
        }
        printf("Merged list is : ");
        display(start3);
}

struct node *create(struct node *start )
{
        int i,n,data;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        for(i=1;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=insert_s(start, data);
        }
        return start;
}/*End of create_slist()*/

struct node *insert_s(struct node *start,int data)
{
        struct node *p,*temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        /*list empty or data to be added in beginning */
        if(start==NULL || data < start->data)
        {
                temp->next=start;
                start=temp;
                return start;
        }
        else
        {
                p=start;
                while(p->next!=NULL && p->next->data < data)
                        p=p->next;
                temp->next=p->next;
                p->next=temp;
        }
        return start;
}/*End of insert_s()*/

struct node *insert(struct node *start,int data)
{
        struct node *p,*temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        /*If list is empty*/
        if(start==NULL)
        {
                temp->next=start;
                start=temp;
                return start;
        }
        else    /*Insert at the end of the list*/
        {
                p=start;
                while(p->next!=NULL)
                        p=p->next;
                temp->next=p->next;
                p->next=temp;
        }
        return start;
}/*End of insert()*/

void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("List is empty\n");
                return;
        }
        p=start;
        while(p!=NULL)
        {
                printf("%d ",p->data);
                p=p->next;
        }
        printf("\n");
}/*End of display()*/


