#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * insertatend(struct node *head,int val)
{
    struct node * n= (struct node *)malloc(sizeof(struct node));
    struct node * p= head;
    n->data=val;
    n->next=NULL;
     if(head==NULL)
    {
      return n;
    }
    while(p->next != NULL)
    {
        p=p->next;
    }

    p->next=n;
    return head;
}
void reversetraversal(struct node * head)
{
    if(head==NULL)
    {
        return;
    }
    reversetraversal(head->next);
    printf("%d\n", head->data );
}
int main()
{
    struct node *head =NULL;
    head=insertatend(head,12 );
    head= insertatend(head,23 );
     head=insertatend(head,155 );
     head=insertatend(head,89 );
    printf("Reverse Traversal of linked list \n");
    reversetraversal(head);
}