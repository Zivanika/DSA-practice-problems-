#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *insertAtFirst(struct Node *head)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value:\n");
    scanf("%d",&new->data);
    struct Node *temp=head;
    head=new;
    new->next=temp;
    return head;

 /*struct Node *new,*ptr;
    new=(struct Node*)malloc(sizeof(struct Node));
    new->data=value;
    ptr=head;
    head=new;
    new->next=ptr;
    return head;*/

}
struct Node *insertAtIndex(struct Node *head)
{
    int i;
    int count=0;
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    printf("Enter the index and the value:\n");
    scanf("%d %d",&i,&new->data);
    while(count!=i-1)
    {
        ptr=ptr->next;
        count++;
    }
    new->next=ptr->next;
    ptr->next=new;
    return head;
}
struct Node *insertAtEnd(struct Node *head)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value:\n");
    scanf("%d",&new->data);
    
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
struct Node *head, *new, *ptr1;
    char c;
    // Allocate memory for nodes in the linked list in Heap
    new = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    printf("Enter the value : ");
    scanf("%d", &new->data);
    fflush(stdin);
    new->next = NULL;
    head = new;
    ptr1 = head;
    printf("Do you want to add another Node ?");
    scanf("%c", &c);
    fflush(stdin);
    while (c == 'Y' || c == 'y')
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the value :");
        scanf("%d", &new->data);
        fflush(stdin);
        new->next = NULL;
        ptr1->next = new;
        ptr1 = ptr1->next;
        printf("Do you want to add another Node ?  ");
        scanf("%c", &c);
        fflush(stdin);
    }
    if (c == 'N' || c == 'n')
    {
        ptr1->next =NULL;
    }
    printf("Linked list before operation");
    traversal(head);

    printf("\nInsert At first--->\n");
    head=insertAtFirst(head);
    traversal(head);
    printf("\nInsert At index--->\n");
    head=insertAtIndex(head);
    traversal(head);
    return 0;
}