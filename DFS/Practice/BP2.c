#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct  Node
{
    int coff;
    int pow;
    struct Node *next;
};
typedef struct Node NODE;
void createPoly(NODE **);
void printPoly(NODE *);
void addPoly(NODE **, NODE *, NODE *);

void main()
{
    printf("Coded by Deepak(04335304421)\n");
    NODE *p, *q, *r;
    printf("\n CREATE FIRST POLYNOMIAL");
    createPoly(&p);
    printf("\n FIRST POLYNOMIAL");
    printPoly(p);
    printf("\n CREATE SECOND POLYNOMIAL");
    createPoly(&r);
    printf("\n SECOND POLYNOMIAL");
    printPoly(r);
    printf("\n ADDITION OF THE POLYNOMIAL");
    addPoly(&q,p,r);
    printPoly(q);
    
}

void createPoly(NODE **start)
{
    int flag;
    int coe, pow;
    NODE *node=(NODE *)malloc(sizeof(NODE));
    *start=node;
    do{
        printf("\n INPUT THE COFFICIENT: ");
        scanf("%d",&coe);
        printf("\n INPUT THE POWER: ");
        scanf("%d",&pow);
        node->coff=coe;
        node->pow=pow;
        node->next=NULL;
        //clrscr();
        printf("\n DO YOU WANT TO ADD MORE TERMS TO THE POLYNOMIAL(0/1)");
        scanf("%d",&flag);
        if(flag)
        {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            node->next = newNode;
            node = newNode;
            node->next = NULL;
        }

    }while(flag);
}

void printPoly(NODE *node)
{
    printf("\n POLYNOMIAL EXPRESSION: ");
    while(node!=NULL)
    {
        printf("%dx^ %d",node->coff,node->pow);
        node=node->next;
        if(node!=NULL)
        {
            printf(" + ");
        }
    }
}

void addPoly(NODE **start, NODE *p, NODE *q)
{
    NODE *node=(NODE *)malloc(sizeof(NODE));
    node->next=NULL;
    *start=node;
    while(p && q)
    {
        if(p->pow > q->pow)
        {
            node->pow = p->pow;
            node->coff = p->coff;
            p=p->next;
        }
        else if(p->pow < q->pow)
        {
            node->pow = q->pow;
            node->coff = q->coff;
            q=q->next;
        }
        else{
            node->pow=p->pow;
            node->coff=p->coff + q->coff;
            p=p->next;
            q=q->next;
        }

        if(p && q)
        {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            node->next = newNode;
            node = newNode;
            node->next = NULL;
        }
    }

    while(p || q)
    {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        node->next = newNode;
        node = newNode;
        node->next = NULL;

    
        if(p)
        {
            node->pow=p->pow;
            node->coff=p->coff;
            p=p->next;
        }
        if(q)
        {
            node->pow=q->pow;
            node->coff=q->coff;
            q=q->next;
        }
    }
}
