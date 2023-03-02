#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void display(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
int main (void)
{
int n,ch;
printf("Enter the number of nodes :\n");
scanf("%d",&n);
struct Node *vert[n];
for(int i=0;i<n;i++)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value of the node:\n");
    scanf("%d",&new->data);
    new->next=NULL;
    vert[i]=new;
}
for(int i=0;i<n;i++)
{
    struct Node *ptr=vert[i];
    printf("Is there any node connected to %d ?\n",ptr->data);
    scanf("%d",&ch);
    while(ch==1)
    {
        struct Node *new=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data :");
        scanf("%d",&new->data);
        ptr->next=new;
        new->next=NULL;
        ptr=ptr->next;
        printf("Is there any node connected to %d ?\n",ptr->data);
        scanf("%d",&ch);
    }
}
for(int i=0;i<n;i++)
{
    display(vert[i]);
    printf("\n");
}
return 0;
}