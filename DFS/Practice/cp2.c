
//stack implementation using array
#include<stdio.h>
// #include<conio.h>
int a[10], size=10,rear=-1,front=-1,i;
int dequeue();
void enqueue(int);
// void peep();
int isFull();
int isEmpty();
void display();
void main(){
  int choice, item;
  printf("coded by Deepak(04335304421)");
  do{
      printf("\n***********Menu**********");
      printf("\n1. Enqueue");
      printf("\n2. Dequeue");
      printf("\n3. Display Queue element");
      printf("\n4. exit");
      printf("\nEnter your Choice");
      scanf("%d",&choice);
      switch(choice){
        case 1:
            printf("\nEnter element to Push");
            scanf("%d",&item);
            enqueue(item);
            display();
            break;
        case 2:
            printf("\nDequeue element is %d",dequeue());
            display();
            break;
        case 3:
            printf("\nElements of Queue is ");
            display();
            break;
        default:
          choice =4;

      }
  }while(choice!=4);
}
void enqueue(int ele){
    if(isFull()==1){
        printf("\nQueue overflow");
    }
    else if(front==-1){
        rear++;
        front++;
        a[front]=ele;
    }
    else{
        rear++;
        a[rear]=ele;
    }
}
int dequeue(){
    int temp;
    if(isEmpty()){
        printf("\nunderflow");
    }else if(front==rear){
        temp=a[front];
        rear=-1;
        front=-1;
        return temp;
    }
    else{
        temp=a[front];
        front++;
        return temp;
    }
}
int isEmpty(){
    if(front==-1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(rear==(size)-1){
        return 1;
    }
    return 0;
}
void display(){
    if(isEmpty()==1){
        printf("\nQueue is empty");
    }else{
        for(i=front;i<=rear;i++){
        printf("%d ",a[i]);
    }
    }
}