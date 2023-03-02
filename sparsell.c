#include <stdio.h>
#include<stdlib.h>
struct Node{
    int row;
    int column;
    int data;
    struct Node *next;
};
void traversal(struct Node *head)
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data!=0)
        {
           printf("%d %d %d\n",ptr->row,ptr->column,ptr->data);  
        }
           ptr=ptr->next;
    }
}

int main (void)
{
int ch;
struct Node *head,*ptr;
head=NULL;
struct Node *new=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the row:");
scanf("%d",&new->row);
printf("Enter the column:");
scanf("%d",&new->column);
printf("Enter value:");
scanf("%d",&new->data);
new->next=NULL;
head=new;
ptr=head;
printf("Do you want to add another node ?");
scanf("%d",&ch);
while(ch==1)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the row:");
    scanf("%d",&new->row);
    printf("Enter the column: ");
    scanf("%d",&new->column);
    printf("Enter the value: ");
    scanf("%d",&new->data);
    ptr->next=new;
    new->next=NULL;
    printf("Do you want to add another node ?");
    scanf("%d",&ch);
}
traversal(head);
return 0;
}