#include<stdio.h>
int partition(int[],int,int);
void displayArr(int[],int);

//quick sort
void quickSort(int arr[],int low, int high){
    int pivot;
    if(low<high){
        pivot=partition(arr,low,high);
        quickSort(arr, low,pivot-1);
        quickSort(arr, pivot+1,high);
    }
    displayArr(arr,10);
}
// partitiono of array
int partition(int arr[], int low, int high){
    int i=low,j=high,pivot,temp;
    pivot=i;
    while (i<j)
    {
        while (arr[i]<arr[pivot])
        {
            i++;
        }
        while (arr[j]>arr[pivot])
        {
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        // return j;
    }
    temp=arr[j];
    arr[j]=arr[pivot];
    arr[pivot]=temp;
    return j;
}
//display array elemtents
void displayArr(int arr[],int num){
    int i;
    for ( i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
}
void main(){
    int i, j,arr[10], num=10;
    printf("Code by Deepak(04335304421)\n");
    printf("Enter the Elements of Array");
    for (i = 0; i < num; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,9);
}