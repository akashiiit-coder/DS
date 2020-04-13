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
int lnodes(node* root)
{
    if (!root)
    return 0;
    if (!root->rchild && !root->lchild)
    return 1;
    return lnodes(root->lchild)+lnodes(root->rchild);
}
int nlnodes(node* root)
{
    if (!root)
    return 0;
    if (!root->rchild && !root->lchild)
    return 0;
    return 1+nlnodes(root->lchild)+nlnodes(root->rchild);
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
    printf ("No. of leaf nodes: %d\n",lnodes(root));
    printf ("No. of non leaf nodes: %d\n",nlnodes(root));
}