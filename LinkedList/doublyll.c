#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
} *start = NULL;

void create()
{
    struct Node *newnode, *temp;
    int data, n;
    printf("enter the number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("enter the value of the node:");
        scanf("%d", &data);
        newnode->data = data;
        if (start == NULL)
        {
            newnode->prev = NULL;
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }
        newnode->next = NULL;
    }
}

void inserAtBeg()
{
    struct Node *temp, *newnode;
    int data;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value to be inserted:");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
}

void inserBefore()
{
    struct Node *temp, *newnode, *pre;
    int data, val;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter value before which you want to insert:");
    scanf("%d", &val);
    printf("enter value to be inserted:");
    scanf("%d", &data);
    newnode->data = data;
    temp = start;
    while (temp->data != val)
    {
        pre = temp;
        temp = temp->next;
    }
    pre->next = newnode;
    newnode->prev = pre;
    newnode->next = temp;
    temp->prev = newnode;
}

void insertAfter()
{
    struct Node *temp, *newnode;
    int data, val;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the value after which you want to insert:");
    scanf("%d", &val);
    printf("Enter the value to be inserted:");
    scanf("%d", &data);
    newnode->data = data;
    temp = start;
    while (temp->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        newnode->prev = temp;
        newnode->next = NULL;
        temp->next = newnode;
    }
    else
    {
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void deleteNode()
{
    int data;
    printf("enter data to be deleted:");
    scanf("%d", &data);
    struct Node *temp = start;

    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp->prev == NULL)
    {
        start = temp->next;
        start->prev = NULL;
    }
    else if (temp->next == NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void display()
{
    struct Node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    create();
    // inserAtBeg();
    inserBefore();
    // insertAfter();
    // display();
    deleteNode();
    display();
}