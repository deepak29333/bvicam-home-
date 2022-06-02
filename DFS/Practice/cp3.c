#include<stdlib.h>
#include <stdio.h>
#define SIZE 5

int cir_queue[SIZE];
int front = -1, rear = -1;


int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
    return 1;
  return 0;
}


int isEmpty() {
  if (front == -1) 
    return 1;
  return 0;
}


void enqueue(int element) {
  if (isFull())
    printf("\n Queue is full!!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    cir_queue [rear] = element;
    printf("\n Inserted  element: %d", element);
  }
}


int dequeue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty!!! \n");
    return (-1);
  } else {
    element = cir_queue [front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 

    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element: %d \n", element);
    return (element);
  }
}


void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
       printf("\n Circular queue: ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", cir_queue [i]);
    }
    printf("%d ", cir_queue [i]);
    
  }	
}

int main() {
  
 int ch,item;
    printf("\nCoded by Deepak(04335304421)\n");
    do
    {
        printf("\n**********OPTIONS**********");
        printf("\n1.Enqueue ");
        printf("\n2.Dequeue ");
        printf("\n3.Display the Queue");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("\nElement to be inserted in the Queue : ");
            scanf("%d", &item);
            enqueue(item);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        } 
    }while(1);

  return 0;
}
