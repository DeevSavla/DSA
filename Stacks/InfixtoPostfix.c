#include<conio.h>
#include<stdio.h>
# define SIZE 50
int top=-1;
char stack[SIZE];
char a;
char infix[SIZE];
char postfix[SIZE];
int priority(char a)
{
    if(a=='/' || a=='*' || a=='%')
        return 3;
    else if(a=='-' || a=='+')
        return 2;
    else
        return 1;
}
void push(char val)
{
    top++;
    stack[top]=val;
}
char pop(char a)
{
    a=-1;
    a=stack[top];
    top--;    
    return a;
}
void main()
{
    char y,z;
    int a=0,j=0;
    printf("Enter an infix expression:");
    scanf("%s",&infix);
    while(infix[a]!='\0')
    {
        y=infix[a];
        if(y=='(')
        {
            push(y);
        }    
        else if((y>='A' && y<='Z') || (y>='a' && y<='z') || (y>='0' && y<='9'))
        {
            postfix[j]=y;
            j++;
        }
        else if(y=='+' || y=='-' || y=='/' || y=='*' || y=='%')
        {
            if(top==-1 || priority(y)>priority(stack[top]))
            {
                push(y);
            }
            else
            {
                while(top!=-1 || priority(y)<=priority(stack[top]))
                {
                    z=pop(y);
                    postfix[j]=z;
                    j++;
                }
                push(y);
            }
        }
        else if (y == ')')
        {
            while (stack[top] != '(')
            {
                z = pop(y);
                postfix[j] = z;
                j++;
            }
            z = pop(y);
        }
        a++;
    }
    while(top!=-1)
    {
        z=pop(y);
        postfix[j]=z;
        j++;
    }
    printf("The Postfix Expression is:%s",postfix);
}