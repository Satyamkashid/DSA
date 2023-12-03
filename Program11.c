#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{   
    // Allocate the memory
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialize the node
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head , int No)
{   
    // Temporary pointer for LL Traversal
    PNODE Temp = *Head;

    // Step 1 : Allocate the memory
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    // Step 2 : Initialize the node
    newn->data = No;
    newn->next = NULL;
    
    //  Step 3 : Check whether the LL is empty or not
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {   
        // Travel the LL till Last Node
        while (Temp->next !=NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }

}

void InsertAtPos(PPNODE Head,int No,int iPos)
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
        Temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{   
    if(*Head == NULL)   // Case 1
    {
        return;
    }
    else if((*Head)->next == NULL)  // Case 2
    {
        free(*Head);
        *Head = NULL;
    }
    else    // Case 3
    {
        PNODE Temp = *Head;
        *Head = (*Head)->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{   
    if(*Head == NULL)   // Case 1
    {
        return;
    }
    else if((*Head)->next == NULL)  // Case 2
    {
        free(*Head);
        *Head = NULL;
    }
    else    // Case 3
    {
        PNODE Temp = *Head;
        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head,int iPos)
{
    int Size = 0;
    Size = Count(*Head);
    PNODE Temp =*Head;
    int i = 0;
    PNODE Targetnode = NULL; 

    // Case 1 : Invalid Position
    if((iPos < 1) || (iPos > Size))
    {   
        printf("Invalid Position \n");
        return;
    }

    // Case 2 : First Position
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }

    // Case 3 : Last Position
    else if(iPos == Size)
    {
        DeleteLast(Head);
    }

    // Case 4 : Position between First and Last
    else
    {
        for(i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Targetnode = Temp->next;
        Temp->next = Temp->next->next;
        free(Targetnode);
    }
}

void Display(PNODE Head)
{
    printf("Elements in the Linked List are : \n");

    while (Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
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
{   
    int iRet = 0;
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

    // DeleteFirst(&First);

    // Display(First);
    // iRet = Count(First);
    // printf("Number of Nodes are : %d\n",iRet);

    // DeleteLast(&First);

    // Display(First);
    // iRet = Count(First);
    // printf("Number of Nodes are : %d\n",iRet);

    InsertAtPos(&First,40,3);

    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteAtPos(&First,3);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n",iRet);

    return 0;

}