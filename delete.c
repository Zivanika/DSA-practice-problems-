#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *create(int value)
{
    struct Tree *new=(struct Tree*)malloc(sizeof(struct Tree));
    new->lc=NULL;
    new->rc=NULL;
    new->data=value;
    return new;
}
struct Tree *max(struct Tree *root)
{
    struct Tree *ptr=root;
    while(ptr!=NULL)
    {
        ptr=ptr->rc;
    }
    return ptr;
}
struct Tree *delete(struct Tree *root,int key)
{
    struct Tree *ptr=root;
    if(ptr->data>key)
    {
     ptr->lc=delete(ptr->lc,key);
    }
    if(ptr->data<key)
    {
        ptr->rc=delete(ptr->rc,key);
    }
    if(ptr->data==key)
    {
        if(ptr->lc!=NULL && ptr->rc==NULL)
        {
            struct Tree *temp=ptr->lc;
            free(ptr);
            return temp;
        }
        if(ptr->rc!=NULL && ptr->lc==NULL)
        {
            struct Tree *temp=ptr->rc;
            free(ptr);
            return temp;
        }
        if(ptr->rc==NULL && ptr->lc==NULL)
        {
            struct Tree *temp=ptr;
            free(temp);
        }
        if(ptr->rc!=NULL && ptr->lc!=NULL)
        {
            struct Tree *temp=max(ptr->lc);
            ptr->data=temp->data;
            ptr->lc=delete(ptr->lc,temp->data);
            return temp;
        }
    }
}
struct Tree *insert(struct Tree *ptr,int value)
{
if(ptr==NULL)
return create(value);
else if(ptr->data>value)
{
    ptr->lc=insert(ptr->lc,value);
}
else
{
    ptr->rc=insert(ptr->rc,value);
}
}
void traversal(struct Tree *root)
{
    struct Tree *ptr=root;
    if(ptr)
    {
      traversal(ptr->lc);
      printf("%d ",ptr->data);
      traversal(ptr->rc);
    }
}
int main (void)
{
int data,value;
struct Tree *root;
root=NULL;
char ch;
printf("Enter a value:\n");
scanf("%d",&data);
fflush(stdin);
root=insert(root,data);
printf("Do you want to add another node:\n");
scanf("%c",&ch);
fflush(stdin);
while(ch=='y'|| ch=='Y')
{
    printf("Enter a value:\n");
    scanf("%d",&data);
fflush(stdin);
    insert(root,data);
    printf("Do you want to add another node:\n");
    scanf("%c",&ch);
    fflush(stdin);
}
printf("Enter the node you want to delete: ");
scanf("%d",&value);
root=delete(root,value);
traversal(root);

return 0;
}