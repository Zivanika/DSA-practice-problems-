#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void traversal(struct Node *head,int count)
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
        count++;
    }
}
void Print_Value(struct Node *head,count)
{
struct Node *ptr=head;
int index=0;
while(index!=count-1)
{
    ptr=ptr->next;
}
printf("%d",ptr->next->data);
}
int main (void)
{
struct Node *head;

return 0;
}