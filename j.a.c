/*****************************************
Created by Akash Anand *******************
*****Branch - IT  Roll no - 11912051******
******************************************/
#include<stdio.h>
void display(int * arr ,int n)//prints the array
{
    for (int i=0;i<n;i++)
    printf ("%d ",arr[i]);
    printf ("\n");
}
int partition(int arr[], int low,int high)/*arrange array elements such that left elements to pivot are less
    than pivot and right elements to pratition are greater than pivot*/
{
    int i=low+1,j=high,pivot=arr[low],temp; 
    while (1)
    {
        while(arr[i]<pivot && i<high)
        i++;
        while(arr[j]>pivot )
        j--;
        if (i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else break;//we have found correct position
    }
    arr[low]=arr[j];
    arr[j]=pivot;
    return j;// j is correct position
}
void quick_sort(int arr[],int l,int h)
{
    if (l>=h)return;//either array is empty or has 1 element
    int p=partition(arr,l,h);
    quick_sort(arr,l,p-1);
    quick_sort(arr,p+1,h);
}
int main()//driver function
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
