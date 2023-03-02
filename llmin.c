#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void min(struct Node *head)
{
    struct Node *ptr=head;
    int  min=ptr->data;
    while(ptr!=NULL)
    {
        if(min>ptr->next->data)
        {
            min=ptr->next->data;
        }
        ptr=ptr->next;
    }
    printf("The minium element is %d ",min);
}

int main (void)
{
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
    min(head);

}
