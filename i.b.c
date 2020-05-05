

/*****************************************
Created by Akash Anand********************
*****Branch - IT  Roll no - 11912051******
******************************************/
#include <stdio.h>
#include <stdlib.h>
void print(int * arr, int n)
{
    for (int i=0;i<n;i++)
    printf ("%d ",arr[i]);
    printf ("\n");
}
void merge(int * arr,int low1,int top1,int low2,int top2,int* arr2)
{
    int index=0;
    while (low1<=top1 && low2<=top2)
    {
        if (arr[low1]<arr[low2])
        arr2[index++]=arr[low1++];
        else
        arr2[index++]=arr[low2++];
    }
    while(low1<=top1)
    {
        arr2[index++]=arr[low1];
        low1++;
    }
    while(low2<=top2)
    {
        arr2[index++]=arr[low2];
        low2++;
    }
}
void copy(int a1[],int a2[],int low,int top)
{
    for (int i=low;i<=top;i++)
        a1[i]=a2[i-low];
}
void msort(int l,int r,int * arr)
{
    if (l==r)
    return;

    int mid=(l+r)/2;//mid element of the array
    int temp[r-l+1];//temp array to store sorted elements

    msort(l,mid,arr);
    msort(mid+1,r,arr);

    merge(arr,l,mid,mid+1,r,temp);//merging two subarrays and storing in temp

    copy(arr,temp,l,r);//making change of order in orignal array 

}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    msort(0,n-1,arr);
    print(arr,n);
}