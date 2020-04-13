#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL,*last=NULL;
void create()
{
    if (!head)
    {
        last=head=(node*)malloc(sizeof(node));
        last->prev=NULL;
    }
    else
    {
        last->next=(node*)malloc(sizeof(node));
        last->next->prev=last;
        last=last->next;
    }
    last->next=NULL;
    printf ("Enter data to insert");
    scanf("%d",&last->data);
    last->next=NULL;  
}
void delete()
{
    int key;node* temp=head;
    printf ("Enter data to delete\n");
    scanf("%d",&key);
    if (key==head->data)
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
    }
    else
    {
        node* prev=head;
        while(prev->next && prev->next->data!=key)
        prev=prev->next;
        temp=prev->next;
        if (temp->next)
        temp->next->prev=prev;
        prev->next=temp->next;
    }
    free(temp);
}
void print()
{
    node* temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int y;
    printf ("To insert a node press 1 to continue press 0\n");
    scanf("%d",&y);
    while(y)//linked list creation.........(a)
    {
        if (y==1)create();
        printf ("To insert a node press 1 to continue press 0\n");
        scanf("%d",&y);
    }
    printf ("To delete a node press 1 to continue press 0\n");
    scanf("%d",&y);
    while(y)//linked list deletion.........(b)
    {
        if (y==1)delete();
        printf ("To delete a node press 1 to continue press 0\n");
        scanf("%d",&y);
    }
    print();//printing linked list.........(c)
}