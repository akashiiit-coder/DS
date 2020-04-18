#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL,*last=NULL;
void swap(node* t1,node* t2)
{
    int t=t1->data;
    t1->data=t2->data;
    t2->data=t;
}
void sort(node * start)
{
    node* temp=start->next,*pre,*curr;int key;
    while(temp)
    {
        curr=temp;
        key=curr->data;// curr ko insert karna hai
        pre=temp->prev;
        while ( pre && key<pre->data)
        {
            curr->data=pre->data;
            curr=pre;
            pre=pre->prev;
        }
        curr->data=key;
        temp=temp->next;
    }
}
void display(node* temp)
{
    while(temp)
    {
        printf ("%d ",temp->data);
        temp=temp->next;
    }
    printf ("\n");
}
void create()
{
    if (head==NULL)
    {
        head=last=(node*)malloc(sizeof(node));
        last->prev=NULL;
    }
    else
    {
        last->next=(node*)malloc(sizeof(node));
        last->next->prev=last;
        last=last->next;
    }
    printf ("Enter data to be inserted\n");
    scanf("%d",&last->data);
    last->next=NULL; 
}
int main(void)
{
    int y;
    printf ("To insert data press 1 else 0\n");
    scanf("%d",&y);
    while(y)
    {
        if (y==1)
        create();
         printf ("To insert data press 1 else 0\n");
        scanf("%d",&y);
    }
    printf ("List before sorting\n");
    display(head);
    sort(head);
    printf ("list after sorting\n");
    display(head);
}