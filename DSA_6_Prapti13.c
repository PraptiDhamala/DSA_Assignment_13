#include<stdio.h>
void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxheapify(int arr[], int n, int i)
{
    int large=i ;
    int left= 2*i+1;
    int right= 2*i+2;
    if(left<n && arr[left]>arr[large])
    {
        large=left;
    }
    if(right<n && arr[right]>arr[large])
    {
        large=right;
    }
    if(large != i)
    {
        swap(&arr[i],&arr[large]);
        maxheapify(arr, n, large);
    }
}
void minheapify(int arr[], int n, int i)
{
    int small=i ;
    int left= 2*i+1;
    int right= 2*i+2;
    if(left<n && arr[left]<arr[small])
    {
        small=left;
    }
    if(right<n && arr[right]<arr[small])
    {
        small=right;
    }
    if(small != i)
    {
        swap(&arr[i],&arr[small]);
        minheapify(arr, n, small);
    }
}
void maxheap(int arr[], int n)
{
    for(int i = n/2 - 1 ; i >= 0; i--)
    {
        maxheapify(arr,n,i);
    }
}
void minheap(int arr[], int n)
{
    for(int i = n/2 - 1 ; i >= 0; i--)
    {
        minheapify(arr,n,i);
    }
}
void printarray(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={10,67,54,32,88,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    int mxheap[n];
    int mnheap[n];
    for(int i =0 ; i < n;i++)
    {
        mxheap[i]=arr[i];
        mnheap[i]=arr[i];
    }
    maxheap(mxheap,n);
    minheap(mnheap,n);
    printf("Max heap: \n ");
    printarray(mxheap,n);
    printf("Min heap: \n ");
    printarray(mnheap,n);
    return 0;
}