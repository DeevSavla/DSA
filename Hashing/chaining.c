#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
}*HashTable[10];

int hash(int val)
{
    return val%10;
}

void insert(int data,struct node *HashTable[])
{
    int index = 0;
    index = hash(data);
    if (HashTable[index]==0)
    {
        HashTable[index] = (struct node *)malloc(sizeof(struct node));
        HashTable[index]->data = data;
        HashTable[index]->next = NULL;
    }
    else{
        struct node *pre,*temp,*nn;
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data = data;
        nn->next = NULL;
        temp = HashTable[index];
        while (temp!=NULL)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp==NULL)
        {
            pre->next = nn;
        }
        else{
            nn->next = temp;
            pre->next = nn;
        }        
    }
}
void display(struct node *HashTable[])
{
    struct node *temp;
    for (int i = 0; i < 10; i++)
    {
        temp = HashTable[i];
        printf("%d ",i);
        while (temp!= NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int choice,data;
    for (int i = 0; i < 10; i++)
    {
        HashTable[i] = 0;
    }
    while (1) {
        printf("\n1. Insert\n2. Linear Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data:");
                scanf("%d",&data);
                insert(data,HashTable);
                break;
            case 2:
                //linear_search();
                break;
            case 3:
                display(HashTable);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice, try again\n");
        }
    }

    return 0;
}