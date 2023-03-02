#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
void degree(struct Tree *root)
{
    struct Tree * ptr=root;
    if(ptr)
    {
        degree(ptr->lc);
        if(ptr->lc!=NULL && ptr->rc!=NULL)
        {
            printf("The degree of node %d is 2\n",ptr->data);
        }
        if(ptr->rc==NULL && ptr->lc==NULL)
        {
            printf("The degree of node %d is 0\n",ptr->data);
        }
        else
        {
            printf("The degree of the node %d is 1\n",ptr->data);
        }
        degree(ptr->rc);
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
degree(root);
return 0;
}