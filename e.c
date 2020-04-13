#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
}node;
node* root=NULL;
node* decl(int key)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->rchild=temp->lchild=NULL;
    temp->data=key;
    return temp;
}
node* create(node* root,int key)
{
    if (!root)
    return decl(key);
    if (root->data<key)
    root->rchild=create(root->rchild,key);
    if (root->data>key)
    root->lchild=create(root->lchild,key);
    return root;
}
void inorder(node* root)
{
    if (!root)
    return ;
    inorder(root->lchild);
    printf ("%d ",root->data);
    inorder(root->rchild);
}
void preorder(node* root)
{
    if (!root)
    return ;
    printf ("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(node* root)
{
    if (!root)
    return ;
    postorder(root->lchild);
    postorder(root->rchild);
    printf ("%d ",root->data);
}
int main()
{
    int y;//tree creation.........(a)
    printf ("To insert a node press 1 else press 0 to continue\n");
    scanf("%d",&y);
    while(y)
    {
        if (y==1)
        {
            int key;
            printf ("Enter data to insert\n");
            scanf("%d",&key);
            root=create(root,key);
        }
        printf ("To insert a node press 1 else press 0 to continue\n");
        scanf("%d",&y);
    }
    printf ("Inorder Traversal\n");//tree traversal.........(b)
    inorder(root);
    printf ("\nPreorder Traversal\n");
    preorder(root);
    printf ("\nPostorder Traversal\n");
    postorder(root);
}