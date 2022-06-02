
//stack implementation using array
#include<stdio.h>
int a[10], size=10,top=-1,i;
int pop();
void push(int);
int isFull();
int isEmpty();
void display();
void main(){
  int choice, item;
  printf("coded by Deepak(04335304421)");
  do{
      printf("\n***********Menu**********");
      printf("\n1. Push");
      printf("\n2. Pop");
      printf("\n3. Display Stack element");
      printf("\n4. exit");
      printf("\nEnter your Choice");
      scanf("%d",&choice);
      switch(choice){
        case 1:
            printf("\nEnter element to Push");
            scanf("%d",&item);
            push(item);
            display();
            break;
        case 2:
            printf("\npop element is %d",pop());
            display();
            break;
        case 3:
            printf("\nElements of stack is ");
            display();
            break;
        default:
          choice =4;

      }
  }while(choice!=4);
}
void push(int ele){
    if(isFull()){
        printf("\nstack overflow");
    }
      top++;
      a[top]=ele;
}
int pop(){
    int temp;
    if(isEmpty()){
        printf("\nunderflow");
        // return ;
    }else{
        temp=a[top];
        top--;
        return temp;
    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(top==(size)-1){
        return 1;
    }
    return 0;
}
void display(){
    if(isEmpty()){
        printf("\nStack is empty");
    }
    for(i=0;i<=top;i++){
        printf("%d ",a[i]);
    }
}