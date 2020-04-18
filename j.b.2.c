/*************************************************
            This program was creted
            and     verified     by
                AKASH  ANAND
*************************************************/
// selection sort by exchanging links
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node{
    int data;
    struct node * link;
}node;
void display(node*);
node* head=NULL,*last=NULL;
node* min(node* start)
{
    node* t=(node*)malloc(sizeof(node)),*par=NULL,*temp=start,*prev=NULL;
    t->data=INT_MAX;
    while(temp)
    {        // printf("yup\n");
        if (t->data>temp->data)
        {
            par=prev;
            t=temp;
        }
        prev=temp;
        temp=temp->link;
    }
    return par;
}
void sort(node* temp)
{
    node* min_par,*temp_par=NULL;
    while(temp->link)
    {
        min_par=min(temp);
        if (min_par!=NULL)//it means element is the smallest itself
        {
            if (temp==head)
            {
                node* t1,*t2;
                t1=head->link;
                t2=min_par->link;
                head->link=t2->link;
                t2->link=t1;
                min_par->link=head;
                head=t2;
            }
            else
            {
                node* t1=min_par->link;
                min_par->link=temp_par->link;
                temp_par->link=t1;
                t1=min_par->link->link;
                min_par->link->link=temp_par->link->link;
                temp_par->link->link=t1;
            }
            if (temp_par!=NULL)
            {
                temp=temp_par->link->link;
                temp_par=temp_par->link;
            }
            else
            {
                temp_par=head;
                temp=head->link;
            } 
        }
        else
        {
            temp_par=temp;
            temp=temp->link;
        }   
    }
}
void display(node * temp)
{
    while(temp)
    {
        printf ("%d ",temp->data);
        temp=temp->link;
    }
    printf ("\n");
}
void create()
{
    printf ("Enter data to be inserted\n");
    if (head==NULL)
    head=last=(node*)malloc(sizeof(node));
    else
    last=last->link=(node*)malloc(sizeof(node));
    last->link=NULL;
    scanf("%d",&last->data);
}
int main()
{
    int y;
    printf ("To insert element press 1 to continue press 0\n");
    scanf("%d",&y);
    while(y)
    {
        if (y==1)
        create();
        printf ("To insert element press 1 to continue press 0\n");
        scanf("%d",&y);
    }
    printf ("Before sorting\n");
    display(head);
    sort(head);
    printf ("After sorting\n");
    display(head);
}
