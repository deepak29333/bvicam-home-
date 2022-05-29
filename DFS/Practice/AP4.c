#include<stdio.h>

void displayArr(int arr[], int);
//insertion sort function
void insertionSort(int arr[],int num){
    int i,temp,j;
    for ( i = 0; i < num; i++)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    displayArr(arr,num);
    
}
//display element
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
    insertionSort(arr,num);
    
}