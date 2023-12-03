// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// typedef struct node NODE;
// typedef struct node * PNODE;
// typedef struct node ** PPNODE;

// void InsertFirst(PPNODE Head,int No)
// {   
//     // Allocate the memory
//     PNODE newn = NULL;
//     newn = (PNODE)malloc(sizeof(NODE));

//     // Initialize the node
//     newn->data = No;
//     newn->next = NULL;

//     if(*Head == NULL)
//     {
//         *Head = newn;
//     }
//     else
//     {
//         newn->next = *Head;
//         *Head = newn;
//     }
// }

// void InsertLast(PPNODE Head , int No)
// {   
//     // Temporary pointer for LL Traversal
//     PNODE Temp = *Head;

//     // Step 1 : Allocate the memory
//     PNODE newn = NULL;
//     newn = (PNODE)malloc(sizeof(NODE));

//     // Step 2 : Initialize the node
//     newn->data = No;
//     newn->next = NULL;
    
//     //  Step 3 : Check whether the LL is empty or not
//     if(*Head == NULL)
//     {
//         *Head = newn;
//     }
//     else
//     {   
//         // Travel the LL till Last Node
//         while (Temp->next !=NULL)
//         {
//             Temp = Temp->next;
//         }
//         Temp->next = newn;
//     }

// }
// void Display(PNODE Head)
// {
//     printf("Elements in the Linked List are : \n");

//     while (Head != NULL)
//     {
//         printf("| %d | -> ",Head->data);
//         Head = Head->next;
//     }
//     printf("NULL \n");
// }

// int Count(PNODE Head)
// {
//     int iCount = 0;

//     while (Head !=NULL)
//     {
//         iCount++;
//         Head = Head->next;
//     }
//     return iCount;
    
// }

// int main()
// {   
//     int iRet = 0;
//     PNODE First = NULL;

//     InsertFirst(&First,101);
//     InsertFirst(&First,51);
//     InsertFirst(&First,21);
//     InsertFirst(&First,11);

//     Display(First);
//     iRet = Count(First);
//     printf("Number of Nodes are : %d\n",iRet);

//     InsertLast(&First,151);
    
//     Display(First);
//     iRet = Count(First);
//     printf("Number of Nodes are : %d",iRet);
    

//     return 0;

// }



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

void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

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
    PNODE Temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (Temp->next!=NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

void Display(PNODE Head)
{
    printf("Elements in the Linked List are : \n");

    while (Head!=NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
    
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    
    Display(First);

    InsertLast(&First,151);
    
    Display(First);

    return 0;
}