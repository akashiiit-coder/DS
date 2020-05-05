/*****************************************
Created by Akash Anand *******************
*****Branch - IT  Roll no - 11912051******
******************************************/
#include<stdio.h>
void display(int * arr ,int n)
{
    for (int i=0;i<n;i++)
    printf ("%d ",arr[i]);
    printf ("\n");
}
int partition(int arr[], int low,int high,int p)
{
    int n=high-low+1,a1[n],a2[n],i1=0,i2=0,temp,e=arr[low];
    for (int i=low+1;i<=high;i++)//partitioning
    {
        temp=arr[i];
        if (temp<e)
        a1[i1++]=temp;
        else 
        a2[i2++]=temp;
    }
    for (int i=0;i<i1;i++)//copying the elements
    arr[i+low]=a1[i];
    
    arr[i1+low]=e;

    for (int i=0;i<i2;i++)
    arr[low+i1+1+i]=a2[i];

    p=i1+low;
    return p;
}
void quick_sort(int arr[],int l,int h)
{
    if (l>=h)return;
    int p=partition(arr,l,h,p);
    quick_sort(arr,l,p-1);
    quick_sort(arr,p+1,h);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf ("Array before sorting\n");
    display(a,n);
    quick_sort(a,0,n-1);
    printf ("Array after sorting\n");
    display(a,n);
}