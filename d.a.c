#include <stdio.h>
#define max 5
int queue[max],r=-1,f=-1;
void insert_front(int data)//f--
{
    if (f==-1)
    {
        f=r=0;
        queue[0]=data;
    }
    else if (r==(f-1+max)%max)
    {
        printf ("Overflow\n");
    }
    else
    {
        f=(f-1+max)%max;//decrementing front by 1 and inserting
        queue[f]=data;
    }    
}
void insert_rear(int data)//r++
{
    if (f==-1)
    {
        f=r=0;
        queue[0]=data;
    }
    else
    {
         r=(r+1)%max;
        if (f==r)
        {
            printf ("Overflow\n");
            r=(r-1+max)%max;
        }
        else
        {
            queue[r]=data;
        }
    }
}
void delete_front()//f--
{
    if (f==-1)
    {
        printf("Underflow\n");
    }
    else if (f==r)// when only one element initially
    {
        printf ("%d",queue[f]);
        f=r=-1;
    }
    else
    {
        printf ("%d",queue[f]);
        f=(f+1)%max;//we just increment front by 1 
    } 
}
void delete_rear()//r--
{
    if (f==-1)
    {
        printf("Underflow\n");
    }
    else if (f==r)//when only one element initially
    {
        printf ("%d",queue[f]);
        f=r=-1;
    }
    else
    {
        printf ("%d",queue[r]);
        r=(r-1)%max;
    }
}
void display()
{
    // printf ("r:%d\nf:%d\n",r,f);
    if (f==-1)return ;
    if (f>r)
    {
        for (int i=f;i<max;i++)
        {
            printf ("%d ",queue[i]);
        }
        for (int i=0;i<=r;i++)
        {
            printf ("%d ",queue[i]);
        }
    }
    else
    {
        for (int i=f;i<=r;i++)
        {
            printf ("%d ",queue[i]);
        }
    }
    printf ("\n");
}
int main()
{
    int y,data;
    printf ("To insert at begining press 1\nTo insert at end press 2\n");
    printf ("To delete at begining press 3\nTo delete at end press 4\n");
    printf ("To display press 5\nTo exit press 0\n");
    scanf("%d",&y);
    while(y)
    {
        if (y==1)
        {
            printf ("Enter data to be inserted\n");
            scanf("%d",&data);
            insert_front(data);
        }
        else if (y==2)
        {
            printf ("Enter data to be inserted\n");
            scanf("%d",&data);
            insert_rear(data);
        }
        else if (y==3)
        {
            delete_front();
        }
        else if (y==4)
        {
            delete_rear();
        }
        else if (y==5)
        {
            display();
        }
        printf ("To insert at begining press 1\nTo insert at end press 2\n");
        printf ("To delete at begining press 3\nTo delete at end press 4\n");
        printf ("To display press 5\nTo exit press 0\n");
        scanf("%d",&y);
    }
}
