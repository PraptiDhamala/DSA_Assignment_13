#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long comparision=0, swap=0;
void bubblesort(int a[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            comparision++;
            if(a[j]>a[j+1])
            {
                int tp=a[j];
                a[j]=a[j+1];
                a[j+1]=tp;
                swap++;
            }
        }
    }
}
void selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            comparision++;
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int tp=a[i];
            a[i]=a[min];
            a[min]=tp;
            swap++;
        }
    }
}
void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            comparision++;
            a[j+1]=a[j];
            swap++;
            j--;
        }
        a[j+1]=key;
    }
}
void merge(int a[],int l, int m, int r)
{
    int i,j,k;
    int n1=m-1+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++) 
    {
        L[i]=a[l+i];
    }
        for(j=0;j<n2;j++) 
    {
        R[j]=a[m+1+j];
    }
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        comparision++;
        if(L[i]<=R[j])
        a[k++]=L[i++];
    else
        a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
        while(j<n2) a[k++]=R[j++];

}
void mergeSort(int a[],int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);

    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main()
{
    int n, choice;
    srand(time(NULL));

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("Before Sorting:\n");
    printArray(arr, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1: bubblesort(arr, n); break;
        case 2: selectionsort(arr, n); break;
        case 3: insertionsort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        default: printf("Invalid choice\n"); return 0;
    }

    printf("\nAfter Sorting:\n");
    printArray(arr, n);

    printf("\nComparisons: %ld", comparision);
    printf("\nSwaps: %ld\n", swap);

    return 0;
}