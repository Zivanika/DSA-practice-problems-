#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int co;
    int ex;
    struct Node *next;
};
void traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%dx^%d+", ptr->co, ptr->ex);
        ptr = ptr->next;
    }
}
struct Node *create(struct Node *head)
{
    int ch;
    struct Node *ptr;
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter coefficient:");
    scanf("%d", &new->co);
    printf("Enter exponent:");
    scanf("%d", &new->ex);
        new->next = NULL;
    head = new;
    ptr = head;
    printf("Do you want to add another node ?");
    scanf("%d", &ch);
    while (ch == 1)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter coefficient: ");
        scanf("%d", &new->co);
        printf("Enter exponent:");
        scanf("%d", &new->ex);
        new->next = NULL;
        // ptr = new;
        ptr->next=new;
        ptr=ptr->next;
        printf("Do you want to add another node ?");
        scanf("%d", &ch);
    }
    return head;
}
struct Node *insert(struct Node *head, int c, int e)
{
    struct Node *ptr = head;
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->co = c;
        new->ex = e;
        new->next=NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}
int main(void)
{
    struct Node *head1, *head2, *head3, *PTR1, *PTR2, *PTR3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    printf("Enter the values for the first polynomial: \n");
    head1 = create(head1);
    PTR1 = head1;
    printf("Enter values for the second polynomial: \n");
    head2 = create(head2);
    PTR2 = head2;
    printf("\nThe first polynomial is: ");
    traversal(head1);
    printf("\nThe second polynomial is: ");
    traversal(head2);
    while (PTR1 != NULL && PTR2 != NULL)
    {
        if (PTR1->ex == PTR2->ex)
        {
            head3 = insert(head3, PTR1->co + PTR2->co, PTR1->ex);
            PTR1 = PTR1->next;
            PTR2 = PTR2->next;
        }
        if (PTR1->ex > PTR2->ex)
        {
            head3 = insert(head3, PTR1->co, PTR1->ex);
            PTR1 = PTR1->next;
        }
        if (PTR2->ex > PTR1->ex)
        {
            head3 = insert(head3, PTR2->co, PTR2->ex);
            PTR2 = PTR2->next;
        }
    }
    while (PTR1 != NULL)
    {
        head3 = insert(head3, PTR1->co, PTR1->ex);
        PTR1 = PTR1->next;
    }
    while (PTR2 != NULL)
    {
        head3 = insert(head3, PTR2->co, PTR2->ex);
        PTR2 = PTR2->next;
    }

    printf("\nThe Added polynomial is: ");
    traversal(head3);
    return 0;
}