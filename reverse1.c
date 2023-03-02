#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *reverse(struct Node *head)
{
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    struct Node *ptr3=head->next->next;
    ptr1->next=NULL;
    while(ptr3!=NULL)
    {
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr3;
        ptr3=ptr3->next;
    }
    ptr2->next=ptr1;
    head=ptr2;
    return head;

}
int main (void)
{
return 0;
}