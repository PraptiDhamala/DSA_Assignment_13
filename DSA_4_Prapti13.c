#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;

};
void linkedlistTraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr=ptr->next;
    }
}
struct node * insertafternode (struct node * head, struct node * prevnode,int val)
{
struct node * n=(struct node *)malloc(sizeof(struct node));
n->data=val;
n->next=prevnode->next;
n->prev=prevnode;
prevnode->next=n;
return head;
}
struct node * deleteatgivennode (struct node * head,int val)
{
struct node * n= head;
struct node * p= head->next;
while(p->data!=val && p->next!=NULL )
{
    n=n->next;
    p=p->next;

}
if(p->data==val)
{
    n->next=p->next;
    p->next->prev=n;
    p->prev=NULL;
    free(p);
}
return head;
}
int main()
{
    struct node * head=(struct node *)malloc(sizeof(struct node));
    struct node * second=(struct node *)malloc(sizeof(struct node));
    struct node * third=(struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    head->prev=NULL;
    second->data=72;
    second->next=third;
    second->prev=head;
    third->data=67;
    third->prev=second;
    third->next=NULL;
    linkedlistTraversal(head);
    insertafternode(head,second,83);
    printf("The element after insertion\n");
    linkedlistTraversal(head);
    insertafternode(head,third,90);
    printf("The element after insertion\n");
    linkedlistTraversal(head);
    deleteatgivennode(head,83);
    printf("The element after deletion\n");
    linkedlistTraversal(head);


}