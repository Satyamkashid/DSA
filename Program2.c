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

int main()
{
    PNODE First = NULL;

    return 0;
}