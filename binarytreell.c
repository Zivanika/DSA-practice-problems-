#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *stack[20];
int top=-1;
struct Tree *buildtree(struct Tree *root)
{
   struct Tree *ptr=root;
   ptr->lc=NULL;
   ptr->rc=NULL;
   printf("Enter value: ");
   scanf("%d",&ptr->data);
   printf("Do you want to add the left child of %d ?",&ptr->data);
   scanf("%d",&ch);
   if(ch==1)
   {
    struct Tree *new=(struct Tree*)malloc(sizeof(struct Tree));
    ptr->lc=new;
    buildtree(new);
   }
   printf("Do you want to add the left child of %d",ptr->data);
   scanf("%d",&ch);
   if(ch==1)
   {
    struct Tree *new=(struct Tree*)malloc(sizeof(struct Tree));
    ptr->rc=new;
    buildtree(new);
   }
}
struct Tree *InOrder(struct Tree *root)
{
    struct Tree *ptr=root;
    while(ptr!=NULL)
    {
        top++;
        stack[top]=ptr;
        ptr=ptr->lc;
    }
    while(top!=-1)
    {
        ptr=stack[top];
        top--;
        printf("%d",ptr->data);
        if(ptr->rc!=NULL)
        {
            ptr=ptr->rc;
            while(ptr!=NULL)
            {
                top++;
                stack[top]=ptr;
                ptr=ptr->lc;
            }
        }
    }

}
int main (void)
{
struct Tree *root=(struct Tree*)malloc(sizeof(struct Tree));
buildtree(root);
return 0;
}