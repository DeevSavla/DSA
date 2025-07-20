#include<stdio.h>
#include<conio.h>
#define SIZE 10

int hashtable[SIZE] ;


void linear_insert() 
{
    int key, index, i, hkey;
    printf("\nEnter data:\n");
    scanf("%d", &key);
    hkey = key % SIZE;
    for(i = 0; i < SIZE; i++)
        {
        index = (hkey + i) % SIZE;
        if(hashtable[index] == -1)
        {
            hashtable[index] = key;
            printf("%d inserted at %d",key,index);
            break;
        }
        }

        if(i == SIZE)

        printf("\nelement cannot be inserted\n");
}

void linear_search() 
{   
    int key, index, i, hkey;
 printf("\nEnter element to be searched:\n");
 scanf("%d", &key);
 hkey = key % SIZE;
 for(i = 0; i< SIZE; i++)
 {
    index=(hkey + i) % SIZE;
    if(hashtable[index] == key) {
      printf("Value at index %d", index);
      break;
    }
  }
  if(i == SIZE)
    printf("\n Value Not Found\n");
}

void display() {
    int i;
    printf("\nElements are \n");
    for (i = 0; i < SIZE; i++) {
        printf("\nIndex %d value = %d", i, hashtable[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    for(int i=0;i<SIZE;i++)
    {
        hashtable[i]=-1;
    }
    while (1) {
        printf("\n1. Linear Hash - Insert\n2. Linear Hash - Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linear_insert();
                break;
            case 2:
                linear_search();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice, try again\n");
        }
    }

    return 0;
}