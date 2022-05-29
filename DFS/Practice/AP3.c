#include<stdio.h>
//bubble sort
void displayArr(int arr[], int);
void bubbleSort(int arr[], int num){
    int x, y, temp;   
    for(x = 0; x < num - 1; x++){
        for(y = 0; y < num - x - 1; y++){    
            if(arr[y]<arr[y + 1]){
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }
    displayArr(arr,num);
}
//selection sort
void selectionSort(int arr[],int num){
    int i, j,temp;
    for(i=0;i<num;i++){
        for (j = i+1; j < num; j++)
        {
           if (arr[i]<arr[j])
           {
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
           }
           
        }  
    }
    displayArr(arr,num);

}
//display array
void displayArr(int arr[],int num){
    int i;
    for ( i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
}
void main(){
    int i, j, arr[10],item,choice;
    printf("Coded by Deepak(04335304421)\n");
    printf("Enter the element of array\n");
    //enter array element
    for(i=0; i<10;i++){
        scanf("%d",&arr[i]);
    }
    // select choice
    do{
    printf("Sorting type:-\n");
    printf("1. Bubble Sort.\n2.Selection Sort \n3. exit");
    scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                bubbleSort(arr,10);
                break;
            case 2:
                selectionSort(arr,10);
                break;
            default:
                choice=3;
        }
    }while(choice!=3);
}