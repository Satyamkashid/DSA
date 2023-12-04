// Doubly Linear Linked List
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;  // #
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;  // #

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;   // #
        *Head = newn;
    }
}

void InsertLast(PPNODE Head , int No)
{   
    PNODE Temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;  // #

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL && (*Head)->prev == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{   
    PNODE Temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL && (*Head)->prev == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head , int No , int iPos)
{
    int Size = 0;
    Size = Count(*Head);
    PNODE newn = NULL;
    int i = 0;
    PNODE Temp = *Head;

    // Case 1 : Invalid Position
    if((iPos < 1) || (iPos > Size+1))
    {   
        printf("Invalid Position \n");
        return;
    }

    // Case 2 : First Position
    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }

    // Case 3 : Last Position
    else if(iPos == Size+1)
    {
        InsertLast(Head,No);
    }

    // Case 4 : Position between First and Last
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;
        
        for(i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
    }
}

void Display(PNODE Head)
{
    printf("Elements in the Doubly Linear Linked List are : \n");
    while (Head != NULL)
    {
        printf("| %d | <=> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
    
}

int Count(PNODE Head)
{
    int iCount = 0;

    while (Head !=NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
    
}

int main()
{   int iRet = 0;
    PNODE First = NULL;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);

    InsertLast(&First,151);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);

    InsertAtPos(&First,90,2);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);
    
    return 0;
}