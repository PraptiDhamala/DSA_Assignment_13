#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct stack{
    char item[MAX];
    int top;
};
int isempty(struct stack *s)
{
     if(s->top==-1)
    {
       return 1;
    }
    return 0;
}
void push (struct stack *s,char p)
{
    if(s->top!=MAX-1)
    {
        s->top++;
        s->item[s->top]=p;
    }
    else
    {
        printf("stack is full");
    }
}
char pop(struct stack *s)
{
    if(s->top!=-1)
    {
char x= s->item[s->top];
s->top--;
return x;
    }
    else{
return '\0';   
 }
}
int matchingparenthesis(char openparanthesis, char closeparanthesis)
{
    if(openparanthesis=='('&& closeparanthesis==')') return 1;
     if(openparanthesis=='['&& closeparanthesis==']') return 1;
    if(openparanthesis=='{'&& closeparanthesis=='}') return 1;
    return 0;
}
int parenthesismatch(struct stack *s,char dsa[])
{
    s->top=-1;
    for(int i=0; dsa[i]!='\0';i++)
    {
        char ch=dsa[i];
        if (ch=='('||ch=='['||ch=='{')
        {
            push(s,ch);
        }
          else if (ch==')'||ch==']'||ch=='}')
        {
            if(isempty(s))
            {
                return 0;
            }
            else{
            char popp=pop(s);
            if(!matchingparenthesis(popp,ch)){
                return 0;
            }
            }
          
        }
    }
    return isempty(s);
}
int main()
{
    char dsa[MAX];
struct stack s;
printf("Enter expression: ");
fgets(dsa,MAX,stdin);
if(parenthesismatch(&s,dsa))
{
printf("balanced expression");
}
else{
    printf("unbalanced expression");
}
return 0;
}