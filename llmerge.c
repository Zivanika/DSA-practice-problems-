#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *merge(struct Node *head1,struct Node *head2)
{
    struct Node *ptr1=head1;
    struct Node *ptr2=head2;
    struct Node *temp1,*temp2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
     temp1=ptr1->next;
     temp2=ptr2->next;
     ptr2->next=temp1; 
     ptr1->next=ptr2;
     ptr1=temp1;
     ptr2=temp2;   
    }
    printf("Program reached here");
    return head1;
}
    
void traversal(struct Node *head1)
{
    struct Node *p=head1;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main (void)
{
struct Node *head1=NULL;
struct Node *head2=NULL;
int n,i,index;
 struct Node *new,*p1,*p2;
    char c;
    // Allocate memory for nodes in the linked list in Heap
    printf("Enter values for the first linked list:\n");
    new=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value : ");
    scanf("%d",&new->data);
    fflush(stdin);
    new->next=NULL;
    head1=new;
    p1=head1;
    printf("Do you want to add another Node ?");
    scanf("%c",&c);
    fflush(stdin);
    while(c=='Y' || c=='y')
    {
    new=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value :");
    scanf("%d",&new->data);
    fflush(stdin);
    new->next=NULL;
    p1->next=new;
    p1=p1->next;
    printf("Do you want to add another Node ?  ");
    scanf("%c",&c);
    fflush(stdin);
    }
    if(c=='N' || c=='n')
    {
     p1->next=NULL;   
    }
    printf("Enter values for the second linked list:\n");
    new=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value : ");
    scanf("%d",&new->data);
    fflush(stdin);
    new->next=NULL;
    head2=new;
    p2=head2;
    printf("Do you want to add another Node ?");
    scanf("%c",&c);
    fflush(stdin);
    while(c=='Y' || c=='y')
    {
    new=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value :");
    scanf("%d",&new->data);
    fflush(stdin);
    new->next=NULL;
    p2->next=new;
    p2=p2->next;
    printf("Do you want to add another Node ?  ");
    scanf("%c",&c);
    fflush(stdin);
    }
    if(c=='N' || c=='n')
    {
     p2->next=NULL;   
    }
    head1=merge(head1,head2);
    traversal(head1);
return 0;
}