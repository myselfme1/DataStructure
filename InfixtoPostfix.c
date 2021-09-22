#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define max 100
char stack[max];
int top=-1;
void push(char ch)
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
        return ;
    }
    top++;
    stack[top]=ch;
}
char pop()
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    return stack[top--];
}
int is_operator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return 1;
    else
        return 0;
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^':return 3;break;
        case '/':case '*':return 2;break;
        case '+':case '-':return 1;break;
        default :return 0;
    }
}
int DigAlpha(char ch)
{
    if(ch>='0'&&ch<='9')
        return 1;
    else if(ch>=65&&ch<=90)
        return 1;
    else if(ch>='a'&&ch<='z')
        return 1;
    else return 0;
}
void infixtopostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    push('(');
    strcat(infix,")");
    char ch,item=infix[i];
    while(item!='\0')
    {
        if(item=='(')
            push(item);
        else if(DigAlpha(item)==1)
        {
            postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            ch=pop();
            while(is_operator(ch)==1&&precedence(ch)>=precedence(item))
            {
             postfix[j]=ch;
             j++;
             ch=pop();
            }
            push(ch);
            push(item);
        }
        else if(item==')')
        {
            ch=pop();
            while(ch!='(')
            {
                postfix[j]=ch;
                j++;
                ch=pop();
            }
        }
        i++;
        item=infix[i];
    }
    postfix[j]='\0';
}
int main()
{
    char infix[100],postfix[100];
    printf("Enter infix Expression: ");
    gets(infix);
    infixtopostfix(infix,postfix);
    printf("Postfix Expression: %s",postfix);
}
