/*************************************************
            This program was creted
            and     verified     by
                AKASH  ANAND
*************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char stack[1000];
int top=-1;
int priority(char e)
{
    if (e=='+' || e=='-')
    return 1;
    else if (e=='*' || e=='/')
    return 2;
    else if (e=='^')
    return 3;
    else if (e=='(' || e=='{' || e=='[')
    return 0;// inki pri 0 isliye rakhi taki inke aage vale sare sign push ho jaye 
    else return -1;
}
char pop()
{
    if (top==-1)
    {
        printf("Underflow\n");
        exit(0);
    }
    char temp=stack[top];
    top--;
    return temp;
}
void push(char e)
{
    if (top==999)
    {
        printf("Overflow\n");
        exit(0); 
    }
    top++;
    stack[top]=e;
}
int main(void)
{
    char exp[1000];
    scanf("%s",exp);
    int len=strlen(exp),e,temp;
    for (int i=0;i<len;i++)
    {
        e=exp[i];
        int pr=priority(e);
        if (e=='(' || e=='{' || e=='[')push(e);
        else if (e==')' || e=='}' || e==']')
        {
            while(1){
                temp=pop();
                if (temp=='(' || temp=='{' || temp=='[')
                break;
                printf ("%c",temp);
            }
        }
        else if (pr!=-1)
        {
            while(top!=-1 && pr<=priority(stack[top]))
            {
                printf("%c",pop());
            }
            push(e);
        }
        else
        printf ("%c",e);
    }
    while(top!=-1)
    printf("%c",stack[top--]);
}
