#include<stdio.h>
#include<stdlib.h>
// structure decleration 
struct node
{
    int data;   // 4 byte
    struct node *next;  // 8 byte

};

int main()
{
    struct node *first = NULL;

    return 0;
}