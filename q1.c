#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void traversal(struct Node *head)
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
}
void min(struct Node *head)
{
struct Node *ptr=head;
while(ptr!=NULL)
{
    int min=ptr->data;
    if(ptr->next->data<min)
    {
        min=ptr->next->data;
    }
}
struct Node *p=head;
while((p->next)->data!=min && p!=NULL)
{
p=p->next;
}
struct Node *t1=p->next;
p->next=t1->next;
int a=t1->data;
free(t1);
struct Node *t2=head;
struct Node *new=(struct Node*)malloc(sizeof(struct Node));
new->data=a;
head=new;
new->next=t2;

}
int main(){
int n,i,index;
 struct Node *head,*new,*ptr;
    char c;
    // Allocate memory for nodes in the linked list in Heap
    new=(struct Node *)malloc(sizeof(struct Node));
    head=NULL;
    printf("Enter the value : ");
    scanf("%d",&new->data);
    fflush(stdin);
    new->next=NULL;
    head=new;
    ptr=head;
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
    ptr->next=new;
    ptr=ptr->next;
    printf("Do you want to add another Node ?  ");
    scanf("%c",&c);
    fflush(stdin);
    }
    if(c=='N' || c=='n')
    {
     ptr->next=NULL;   
    }
printf("The Original linked list is :\n");
traversal(head);
printf("The linked list after :\n");
min(head);
return 0;
}