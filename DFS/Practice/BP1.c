#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};
typedef struct node NODE;

NODE *start = NULL;

void insBegining(int item)
{
 NODE *node;
 node = (NODE*)malloc(sizeof(NODE));
 node->data = item;
 if(start==NULL)
 {
  node->next = NULL;
 }
 else
 {
  node->next = start;
 }
 start = node;
 printf("\nNODE INSERTED");
}

void Lastinsert(int item)
{
 NODE *ptr=(NODE*)malloc(sizeof(NODE));
 NODE*temp;
 if(ptr == NULL )
 {
  printf("\n OVERFLOW");
 }
 else
 {
  ptr->data=item;
  if(start == NULL)
  {
   ptr->next=NULL;
   start=ptr;
   printf("\nNODE INSERTED");
   }
   else
   {
    temp = start;
    while(temp->next != NULL)
    {
     temp = temp->next;
    }
    temp->next=ptr;
    ptr->next = NULL;
    printf("NODE INSERTED");
   }
 }
}

void displayList()
{
 NODE *temp;
 temp = start;
 if(temp == NULL)
 {
  printf("\n LIST IS EMPTY!");
 }
 else
 {
     printf("\n LIST: ");
  while(temp != NULL)
  {
   printf("%d -> ", temp->data);

   temp = temp -> next;
   }
   printf("NULL");
  }
 }
void delbeg()
{
 NODE *ptr;
 if(start == NULL)
 {
  printf("\n List is Empty");
 }
 else
 {
  ptr=start;
  start= start -> next;
  free(ptr);
  printf("\n Node deleted from the begining...");
 }
}

void enddel()
{
 NODE *ptr,*ptr1;
 if(start == NULL)
 {
  printf("\nList is empty");
 }
 else if(start -> next ==NULL)
 {
  start=NULL;
  free(start);
  printf("\nOnly node of the list deleted");
 }
 else
 {
  ptr=start;
  while(ptr->next != NULL)
  {
  ptr1=ptr;
  ptr=ptr->next;
  }
 ptr1->next= NULL;
 free(ptr);
 printf("\n Deleted node from the last");
 }
}

void specificins(int item, int loc)
{

 NODE *ptr=(NODE *)malloc(sizeof(NODE));
 NODE *temp;
 int i;
 if(ptr == NULL)
 {
  printf("\n Overflow");
 }
 else
 {
  
  ptr->data=item;
  temp=start;
  for(i=0;i<loc-1;i++)
  {
   temp=temp->next;
   if(temp==NULL)
   {
    printf("\nCan't insert");
    return;
   }
  }
  ptr->next=temp->next;
  temp->next=ptr;
  printf("\n Node inserted");
 }
}

void specificdel(int loc)
{
 NODE *ptr,*ptr1;
 int i;
 ptr=start;
 for(i=0;i<loc;i++)
 {
  ptr1=ptr;
  ptr=ptr->next;
  if(ptr==NULL)
  {
   printf("\nThere are less than %d elements in the list",loc);
   return ;
  }
 }
 ptr1->next=ptr->next;
 free(ptr);
 printf("\nNode Deleted");
}

void search()
{
 NODE *ptr;
 int item,i=0,flag=1;
 ptr=start;
 if(ptr==NULL)
 {
  printf("\nEmpty list");
 }
 else
 {
  printf("\nEnter item which you want to search?");
  scanf("%d",&item);
  while(ptr!=NULL)
  {
   if(ptr->data==item)
   {
    printf("\n Item found at location %d ",(i));
    flag=0;
   }
   i++;
   ptr=ptr->next;
  }
  if(flag!=0)
  {
  printf("\nItem not found");
  }
 }
 
}

void main()
{
 int choice,loc,item;
 printf("Coded By Deepak(04335304421)\n");
 do
 {
 printf("\n\n**********OPTIONS**********");
 printf("\n1. INSERT AT BEGINING");
 printf("\n2. INSERT AT SPECIFIC LOCATION");
 printf("\n3. INSERT AT END");
 printf("\n4. DELETE FROM BEGINING");
 printf("\n5. DELETE FROM SPECIFIC LOCATION");
 printf("\n6. DELTE FROM END");
 printf("\n7. SEARCH THE ELEMENT");
 printf("\n8. DISPLAY THE LIST");
 printf("\n9.Exit");
 printf("\n ENTER YOUR CHOICE ");
 scanf("%d", &choice);
 switch(choice)
 {
  case 1:printf("\n Input the Node Data: ");
	 scanf("%d",&item);
	 insBegining(item);
	 break;
  case 2:printf("\n Input the Node Data: ");
	 scanf("%d",&item);
     printf("\n Enter the location:");
  scanf("%d",&loc);
	 specificins(item,loc);
	 break;
  case 3:printf("\n Input the Node Data: ");
	 scanf("%d",&item);
	 Lastinsert(item);
	 break;
  case 4:delbeg();
	 break;
  case 5:
	 printf("\nEnter the location:");
	 scanf("%d",&loc);
	 specificdel(loc);
	 break;
  case 6:enddel();
	 break;
  case 7:search();
	 break;
  case 8:
  displayList();
	 break;
  case 9:exit(0);
  default : printf("\n WRONG CHOICE");
  }
 }while(choice!=10);
}
