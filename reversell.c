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
}
void traversal(struct Node *head)
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
}
int main (void)
{
int ch;
struct Node *ptr;
struct Node *head=NULL;
struct Node *new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter value: ");
scanf("%d",&new->data);
new->next=NULL;
head=new;
ptr=head;
printf("Do you want to add another node ?");
scanf("%d",&ch);
while(ch==1)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d",&new->data);
    ptr->next=new;
    new->next=NULL;
    ptr=ptr->next;
    printf("Do you want to add another node ?");
    scanf("%d",&ch);
}
printf("Linked list before reversal: ");
traversal(head);
printf("Linked list after reversal: ");
head=reverse(head);
traversal(head);
return 0;
}