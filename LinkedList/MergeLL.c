#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *next;
    int data;
} *start1 = NULL, *start2 = NULL;

struct node *create(struct node *start,int n)
{
    int data;
    struct node *newnode, *temp;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data : ");
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
            temp = start;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return start;
}

void merge()
{
    struct node *temp = start1;

    while (temp != NULL && temp->next!=NULL) 
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        temp->next = start2;
    }

    printf("\nMerged list: ");
    temp = start1;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n1,n2;
    printf("\nEnter Number of nodes for the first list: ");
    scanf("%d", &n1);
    start1=create(start1,n1);
    printf("\nEnter Number of nodes for the second list: ");
    scanf("%d", &n2);
    start2=create(start2,n2);
    merge();
    return 0;
}

