#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *insertAtFirst(struct Node *head)
{
    struct Node *ptr=head;
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->next=ptr;
    ptr->prev=new;
    head=new;
}
int main (void)
{

return 0;
}