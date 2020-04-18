/*************************************************
            This program was creted
            and     verified     by
                AKASH  ANAND
*************************************************/
// selection sort by exchanging data
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node{
    int data;
    struct node * link;
}node;
node* head,*last;
node* min(node* start)
{
    node* t=(node*)malloc(sizeof(node));
    t->data=INT_MAX;
    while(start)
    {
        if (t->data>start->data)
        t=start;
        start=start->link;
    }
    return t;
}
void swap(node* t1,node* t2)
{
    int t;
    t=t1->data;
    t1->data=t2->data;
    t2->data=t;
}
void sort(node* temp)
{
    node* least;
    while(temp->link)
    {
        least=min(temp);
        if (least!=temp)
        {
            swap(least,temp);
        }
        temp=temp->link;
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
