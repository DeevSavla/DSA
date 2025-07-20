#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
# define SIZE 5
int data;
int queue[SIZE];
int front=-1;
int rear=-1;
void enqueue()
{
    printf("Enter that you want to enter:");
    scanf("%d",&data);
    if(rear==SIZE-1)
    {
        printf("Queue is full.\n");
    }    
    else if(rear==-1)
    {
        front++;
        rear++;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}
void dequeue()
{
    int data;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty.\n");
    }
    else if(front==rear)
    {
        data=queue[front];
        front=-1;
        rear=-1;
        printf("%d is dequeued.\n",data);
    }
    else
    {
        data=queue[front];
        front++;
        printf("%d is dequeued.\n",data);
    }
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
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
    scanf("%d",&choice);
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