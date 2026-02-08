#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int stacktop(struct stack *n)
{
    return n->arr[n->top];
}
int isempty(struct stack *s)
{
     if(s->top==-1)
    {
       return 1;
    }
    return 0;
}
int isfull(struct stack *s)
{
     if(s->top==-1)
    {
       return 1;
    }
    return 0;
}
void push (struct stack *s,char val)
{
  if(isfull(s))
  {
    printf("Stack overflown");
  }
  else{
    s->top++;
    s->arr[s->top]=val;
  }
}
char pop(struct stack *s)
{
    if(isempty(s))
  {
    printf("Stack underflown");
  }
 else{
char x= s->arr[s->top];
s->top--;
return x;

}
}
int precedence(char ch){
    if(ch=='*' || ch=='/')
    return 3;
    else if(ch=='+' || ch=='-')
    return 2;
else
return 0;
}
int isoperator(char ch){
    if(ch=='*' || ch=='/'||ch=='+' || ch=='-')
    return 1;
else
return 0;
}
char* infixtopostfix(char* infix)
{
    struct stack * n=(struct stack *)malloc(sizeof(struct stack));
    n->size=10;
    n->arr= (char *)malloc(n->size * sizeof(char));
    char * postfix=(char * )malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
             if(precedence(infix[i])> precedence(stacktop(n))){
                push(n, infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(n);
                j++;
            }
        }
    }
    while(!isempty(n))
    {
        postfix[j]=pop(n);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
     char * infix = "x-y/z-k*d";
    printf("postfix is %s", infixtopostfix(infix));
    return 0;
}