#include<stdio.h>
#include<conio.h>
# define SIZE 50
float stack[50];
char postfix[50];
float result,y;
int top=-1;
void push(int a)
{
    top++;
    stack[top] = a;
}
float pop()
{
    float a = -1;
    a = stack[top];
    top--;
    return a;
}
void main()
{
    char x;
    int i=0;
    int op1,op2;
    printf("Enter postfix expression:");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        x=postfix[i];
        if(x>='0' && x<='9')
        {
            y=(float)(x-'0');
            push(y);
        }
        else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%')
        {
            op2=pop();
            op1=pop();
            if(x=='+')
            {
                result=(op1+op2);
            }
            else if(x=='-')
            {
                result=(op1-op2);
            }
            else if(x=='*')
            {
                result=(op1*op2);
            }
            else if(x=='/')
            {
                result=(op1/op2);
            }
            else if(x=='%')
            {
                result=(int)(op1%op2);
            }
            push(result);
        }
        
        i++;
    }
    printf("%.1f",stack[top]);
}