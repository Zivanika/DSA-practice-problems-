#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *stack[20];
int top=-1;
void preOrder(struct Tree *ptr)
{
   top++;
   stack[top]=ptr;
   while(top!=-1)
   {
    ptr=stack[top];
    top--;
    printf("%d ",ptr->data);
    if(ptr->rc!=NULL)
    {
       top++;
       stack[top]=ptr->rc;
    }
    if(ptr->lc!=NULL)
    {
        top++;
        stack[top]=ptr->lc;
    }
   }
}
void buildtree(struct Tree *ptr)
{
    struct Tree *New;
    int ch;
    printf("Enter value:\n");
    scanf("%d",&ptr->data);
    ptr->lc=NULL;
    ptr->rc=NULL;
    printf("Do you want to add left child of %d\n (1/0):",ptr->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        New=(struct Tree*)malloc(sizeof(struct Tree));
        ptr->lc=New;
        buildtree(New);
    }
    printf("Do you want to add the right child of %d\n (1/0):",ptr->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        New=(struct Tree*)malloc(sizeof(struct Tree));
        ptr->rc=New;
        buildtree(New);
    }
}
int main (void)
{
struct Tree *root=(struct Tree*)malloc(sizeof(struct Tree));
buildtree(root);
preOrder(root);
return 0;
}