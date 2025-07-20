#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5
char stack[SIZE];
int top = -1;
void push()
{
    int data;
    printf("Enter data to push:");
    scanf("%d",&data);
    if(top==SIZE-1)
    {
        printf("Stack is Full.\n");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}
int pop()
{
    int val;
    if(top==-1)
    {
        printf("Stack is Empty.\n");
        return val=-1;
    }
    else
    {
        val=stack[top];
        top--;
        return val;
    }
}
int peek()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top]; 
    }
}
void display()
{
    if(top==-1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Stack is:\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
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
    printf("3.Peek\n");
    printf("4.Display\n");
    printf("5.Exit\n");
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
        top=peek();
        if(top!=-1)
        {
        printf("%d is at the top of the stack.\n",top);
        }
        break;
    case 4:
        display();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
    }
}