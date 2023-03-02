#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *insertAtFirst(struct Node *head)
{
    struct Node *new=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value :\n");
    scanf("%d",&new->data);
    struct Node *temp=head;
    head=new;
    new->next=temp;
    return head;
}
struct Node *insertAtIndex(struct Node *head)
{
    struct Node *ptr=head;
    int count,index;
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value and index:\n");
    scanf("%d %d",&new->data,&index);
    while(count!=index-1)
    {
        ptr=ptr->next;
        count++;
    }
    new->next=ptr->next;
    ptr->next=new;
    return head;   
}
struct Node *deleteAtFront(struct Node *head)
{
    struct Node *ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}
struct Node *deleteAtindex(struct Ncde *head)
{
    struct Node *ptr=head;
    int index,count;
    printf("Enter the index you want to delete: ");
    scanf("%d",&index);
    while(count!=index-1)
    {
        ptr=ptr->next;
        count++;
    }
    struct Node *temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return head;
}
struct Node *delAtEnd(struct Node *head)
{
    struct Node *ptr=head;
    while(ptr->next->next!=NULL)
    {
       ptr=ptr->next;
    }
    struct Node *temp=ptr->next;
    ptr->next=NULL;
    free(temp);
    return head;
}
void traversal(struct Node *ptr)
{
while(ptr!=NULL)
{
    printf("%d->",ptr->data);
    ptr=ptr->next;
}
}
int main (void)
{
int ch;
struct Node *head,*ptr;
struct Node *new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the value:\n");
scanf("%d",&new->data);
head=new;
ptr=head;
new->next=NULL;
printf("Do you want to add another node ?\n");
scanf("%d",&ch);
while(ch==1)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value:\n");
    scanf("%d",&new->data);
    ptr->next=new;
    new->next=NULL;
    ptr=ptr->next;
    printf("Do you want to add another node ?\n");
    scanf("%d",&ch);  
}
head=insertAtFirst(head);
traversal(head);
head=insertAtIndex(head);
traversal(head);
return 0;
}