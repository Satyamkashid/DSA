#include<stdio.h>
#include<stdlib.h>
// structure decleration 
struct node
{
    int data;   // 4 byte
    struct node *next;  // 8 byte

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    //  Step 1 : Allocate the memory for node
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    //  Step 2 : Initialize the node
    newn->data = No;
    newn->next = NULL;
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    return 0;
}