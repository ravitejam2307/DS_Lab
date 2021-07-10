/*Perform Addition and Multiplications on polynomials*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int coef;
  int exp;
  struct node *next;
};

int insert_term(struct node **,int,int);
int display(struct node *);
int poly_add(struct node **,struct node **,struct node **);
int poly_mul(struct node **,struct node **,struct node **);

int main()

{
struct node *start_p=NULL,*start_q=NULL,*start_r=NULL;
int i,n,c,e;
  printf("Enter first polynomial!\n");
  printf("Enter no of terms:");
  scanf("%d",&n);
for(i=0;i<n;i++)
{
  printf("Enter coefficient: ");
  scanf("%d",&c);
  printf("Enter exponent: ");
  scanf("%d",&e);
insert_term(&start_p,c,e);
}
  printf("Enter second polynomial!\n");
  printf("Enter no of terms:");
  scanf("%d",&n);
for(i=0;i<n;i++)
{
  printf("Enter coefficient: ");
  scanf("%d",&c);
  printf("Enter exponent: ");
  scanf("%d",&e);
insert_term(&start_q,c,e);
}
  printf("First polynomial: ");
display(start_p);
  printf("Second polynomial: ");
display(start_q);
poly_add(&start_p,&start_q,&start_r);
  printf("Sum of two polynomial:\n");
display(start_r);
  start_r=NULL;
poly_mul(&start_p,&start_q,&start_r);
  printf("Product of the two polynomial:\n");
display(start_r);
  return 0;
}

/*Insertion*/
int insert_term(struct node **start,int c,int e)
{
  struct node *temp,*temp1,*prev;
  if(*start==NULL)
 {
  temp=(struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  printf("List is Empty\n");
else
 {
  temp->coef=c;
  temp->exp=e;
  temp->next=NULL;
  *start=temp;
 }}
else
{
  temp1=*start;
  while (temp1!=NULL && temp1->exp>e)
  {
  prev=temp1;
  temp1=temp1->next;
  }
  if(temp1==NULL)
 {
  temp=(struct node *)malloc(sizeof(struct node));
  if (temp==NULL)
  printf("Node is not created\n");
else
  {
  temp->coef=c;
  temp->exp=e;
  temp->next=NULL;
  prev->next=temp;
  }
 }
else
  {
  if(temp1->exp==e)
  temp1->coef=temp1->coef+c;
 else
   {
  if(temp1==*start)
  {
  temp=(struct node *)malloc (sizeof (struct node));
  if(temp==NULL)
  printf("Node is not created\n");
  else
   {
    temp->coef=c;
    temp->exp=e;
    temp->next=*start;
    *start=temp;
   }
  }
else
   {
  temp=(struct node *)malloc(sizeof(struct node));
  if (temp==NULL)
  printf("Node is not created\n");
else
  {
  temp->coef=c;
  temp->exp=e;
  temp->next=temp1;
  prev->next=temp;
  }}}
}}}

/*Display*/

int display(struct node *start)
{
  struct node *temp;
  temp=start;
  if (temp==NULL)
   printf("Empty polynomial\n");
else
  {
  while(temp!=NULL)
  {
  printf("%d x^%d",temp->coef,temp->exp);
  temp=temp->next;
  if(temp!=NULL)
   printf(" + ");
 else
   printf("\n");
  }}}

/*polnomial_Addition*/

int poly_add(struct node** start_p,struct node **start_q,struct node** start_r)
{
  int c,e;
  struct node *p_ptr,*q_ptr;
  *start_r=NULL;
  p_ptr=*start_p;
  q_ptr=*start_q;
  while(p_ptr!=NULL && q_ptr!=NULL)
 {
  if (p_ptr->exp==q_ptr->exp)
  {
   c=p_ptr->coef+q_ptr->coef;
   e=p_ptr->exp;
   insert_term(start_r,c,e);
   p_ptr=p_ptr->next;
   q_ptr=q_ptr->next;
  }
 else
  {
  if (p_ptr->exp>q_ptr->exp)
   {
   c=p_ptr->coef;
   e=p_ptr->exp;
   insert_term(start_r,c,e);
   p_ptr=p_ptr->next;
   }
 else
   {
   c=q_ptr->coef;
   e=q_ptr->exp;
   insert_term(start_r,c,e);
   q_ptr=q_ptr->next;
   } } }
   while(p_ptr!=NULL)
   {
   c=p_ptr->coef;
   e=p_ptr->exp;
   insert_term(start_r,c,e);
   p_ptr=p_ptr->next;
   }
   while (q_ptr!=NULL)
   {
   c=q_ptr->coef;
   e=q_ptr->exp;
   insert_term(start_r,c,e);
   q_ptr=q_ptr->next;
   }}

/*Polynomial_Mulitiplication*/

int poly_mul(struct node ** start_p,struct node **start_q,struct node** start_r)
{
 int c,e;
 struct node *p_ptr,*q_ptr;
 *start_r=NULL;
 p_ptr=*start_p;
 q_ptr=*start_q;
 if (*start_p==NULL && *start_q==NULL)
  printf("\nMultiplication of polynomial is not possible!\n");
else
 {
  while(p_ptr!=NULL)
  {
  q_ptr=*start_q;
  while(q_ptr!=NULL)
  {
  c=p_ptr->coef*q_ptr->coef;
  e=p_ptr->exp+q_ptr->exp;
  insert_term(start_r,c,e);
  q_ptr=q_ptr->next;
  }
  p_ptr=p_ptr->next;
  }}}
