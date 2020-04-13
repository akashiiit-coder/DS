#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;
node* create(int key)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->rchild=temp->lchild=NULL;
    temp->data=key;
    return temp;
}
int nodes(node* root)
{
    if (!root)return 0;
    return 1+nodes(root->lchild)+nodes(root->rchild);
}
int main()
{
    node* root=create(10);//creation of binary tree..........(a)
    root->lchild=create(5);
    root->rchild=create(15);
    root->lchild->lchild=create(3);
    root->lchild->rchild=create(7);
    root->rchild->lchild=create(13);
    root->rchild->rchild=create(17);
    printf ("No. of nodes\n%d",nodes(root));
}