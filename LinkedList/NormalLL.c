#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start=NULL;
void create()
{
    struct node *newnode,*temp;
    int data,nodes;
    printf("Enter number of nodes:");
    scanf("%d",&nodes);
    for(int i=0;i<nodes;i++)
    {
        printf("Enter data:");
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        if(start==NULL)
        {
            temp=start=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
}
void reverse(){
    struct node *prev,*current,*post;
    prev=NULL;
    current=post=start;
    while(current!=NULL){
        post=post->next;
        current->next=prev;
        prev=current;
        current=post;
    }
    start=prev;
}
void display()
{
    struct node *temp;
    printf("Linked List is:\n");
    temp=start;
    if(temp==NULL)
    {
        printf("No linked list.\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void delete()
{
    struct node *temp,*pre;
    int val;
    printf("Enter value to delete:");
    scanf("%d",&val);
    temp=start;
    while(temp!=NULL && temp->data!=val)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("No value found.\n");
    }
    else if(temp->data==start->data)
    {
        start=start->next;
        free(temp);
    }
    else
    {
    pre->next=temp->next;
    free(temp);
    }
}
void insertbeg()
{
    struct node *newnode;
    int val;
    printf("Enter value that you want to enter at the beginning:");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=start;
    start=newnode;
}
void insertbefore()
{
    int val,data;
    struct node *pre,*temp,*newnode;
    printf("Enter data before which you want to add something:");
    scanf("%d",&data);
    printf("Enter data that you want to enter:");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    temp=start;
    while(temp->data!=data)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=newnode;
    newnode->next=temp;
}
void insertafter()
{
    int val,data;
    struct node *post,*temp,*newnode;
    printf("Enter data after which you want to add something:");
    scanf("%d",&data);
    printf("Enter data that you want to enter:");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    temp=start;
    while(temp->data!=data)
    {
        temp=temp->next;
    }
    post=temp->next;
    temp->next=newnode;
    newnode->next=post;
}
void main()
{
    while(1)
    {
    int choice;
    printf("----MENU----\n");
    printf("1.Create\n");
    printf("2.InsertBeg\n");
    printf("3.InsertBefore\n");
    printf("4.InsertAfter\n");
    printf("5.Delete\n");
    printf("6.Display\n");
    printf("7.Exit\n");
    printf("8.Reverse\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:create();break;
        case 2:insertbeg();break;;
        case 3:insertbefore();break;
        case 4:insertafter();break;
        case 5:delete();break;
        case 6:display();break;
        case 7:exit(0);break;
        case 8:reverse();break;
        default:break;
    }
    }
}