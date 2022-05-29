#include<stdio.h>
void linearSearch(int arr[],int item){
    int i, j,size;
    size= 10;
    for(i=0;i<size;i++){
        if(arr[i]==item){
            printf("Item Found\n");
            return;
        }
    }
    printf("Item Not Found.\n");
}
void binarySearch(int arr[], int item){
    int left, right, mid,i,j,size,a;
    size= 10;
    for (i = 0; i < size; i++){
        for (j = i + 1; j < size; j++){
            if (arr[i] > arr[j]){
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
        }
    left=0;
    right=size-1;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==item){
            printf("Item Found");
            return;
        }
        else if(arr[mid]<item){
            left=mid+1;
        }
        else 
            right=mid-1;
    }
    printf("item Not Found");
}

void main(){
    int arr[10],i, j,item,choice;
    printf("Coded by Deepak(04335304421)\n");
    //Enter the element of array;
    printf("Enter 10 Elements of array:\n");
    for(i=0;i<10;i++){
        scanf("%d", &arr[i]);
    }
    //searching choice
    printf("enter element to Search in array");
    scanf("%d",&item); 
    do{
    printf("Searching type:-\n");
    printf("1. linear Search.\n2. for Binary Search\n3. exit");
    scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                linearSearch(arr,item);
                break;
            case 2:
                binarySearch(arr,item);
                break;
            default:
                choice=3;
        }
    }while(choice!=3); 
}