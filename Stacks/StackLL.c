#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5
char stack[SIZE];
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push()
{
    struct node *newnode;
    int data;
    printf("Enter data to push:");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}
int pop()
{
    int val;
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is Empty.\n");
        val=-1;
    }
    else
    {
        temp=top;
        val=temp->data;
        top=top->next;
        free(temp);
    }
    return val;
}
void display()
{
    struct node*temp;
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
    temp=top;
    printf("Stack is:\n");
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
    int val,top;
    int choice;
    printf("\n----MENU----\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        val=pop();
        if(val!=-1)
        {
            printf("%d is popped.\n",val);
        }
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