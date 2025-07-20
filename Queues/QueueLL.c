#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue()
{
    struct node *newnode;
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    int val;
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is empty.\n");
    }
    else if(front==rear)
    {
        temp=front;
        val=temp->data;
        printf("%d is dequeued.\n",val);
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else 
    {
        temp=front;
        val=temp->data;
        printf("%d is dequeued.\n",val);
        front=temp->next;
        free(temp);
    }
}
void display()
{
    struct node*temp;
    if(front==NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
    temp=front;
    printf("Queue is:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
}
void main()
{
    while(1)
    {
    int choice;
    printf("\n----MENU----\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        break;
    }
    }
}