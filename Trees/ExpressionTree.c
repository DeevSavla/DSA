#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

struct node{
    char a;
    struct node *left, *right;
} *root;

char postfix[100];
struct node *stack1[10];
int top1 = -1;

void push1(struct node *nn){
    if(root==NULL)
    root = nn;
    top1++;
    stack1[top1] = nn;
    
}

struct node *pop1(){
    struct node *temp;
    if(top1 == -1){
        root = NULL;
        temp = NULL;
    }
    else {
        temp = stack1[top1];
        top1--;
    }
        return temp;
}


void create(char x){
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn -> a = x;
    nn -> left = nn -> right = NULL;
    push1(nn);
    root = nn;
}

void createNode(char x){

    struct node *nn, *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    nn -> a = x;
    temp = pop1();
    nn -> right = temp;
    temp = pop1();
    nn -> left = temp;
    push1(nn);
    root = nn;

}

void expression_tree() {
    int i = 0;
    char x;

    while(postfix[i] != '\0'){
        x = postfix[i];
        if(isalnum(x))
            create(x);
        
        else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
            createNode(x);

        else {
            printf("Expression incorrect");
            break;
        }
        i++;
    }    
}

void inorder(struct node *temp){
    if (temp!=NULL) {
        inorder(temp -> left);
        printf("%c ", temp -> a);
        inorder(temp -> right);
    }
}


int main(){
    printf("Enter the Postfix expression:\n");
    scanf("%s", postfix);
    expression_tree();
    inorder(root);
    return 0;
}