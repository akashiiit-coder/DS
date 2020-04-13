#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;
node* head=NULL,*last=NULL;
void create()
{
    if (!head)
    last=head=(node*)malloc(sizeof(node));
    else 
    last=last->link=(node*)malloc(sizeof(int));
    printf ("Enter data to be inserted\n");
    scanf("%d",&last->data);
    last->link=NULL;
}
void delete()
{
    node* temp=head;int key;
    printf ("Enter data to be deleted\n");
    scanf("%d",&key);
    if (key==head->data)
    head=head->link;
    else
    {
        node *prev=head;
        while(prev && prev->link->data!=key)
        prev=prev->link;
        if (!prev)
        {
            printf ("Node not found\n");
            return;
        }
        temp=prev->link;
        prev->link=temp->link;
    }
    free(temp);
}
void print()
{
    node* temp=head;
    while(temp)
    {
        printf ("%d ",temp->data);
        temp=temp->link;
    }
    printf ("\n");
}
int main()
{
    int y;//linked list creation.........(a)
    printf ("To insert node press 1 else to continue press 0\n");
    scanf("%d",&y);
    while(y)
    {
        if(y==1)create();
        printf ("To insert node press 1 else to continue press 0\n");
        scanf("%d",&y);
    }
    printf ("To delete a node press 1 else to continue press 0\n");
    scanf("%d",&y);
    while(y)//linked list deletion.........(b)
    {
        if(y==1)delete();
        printf ("To delete a node press 1 else to continue press 0\n");
        scanf("%d",&y);
    }
    print();//printing linked list.........(c)
}