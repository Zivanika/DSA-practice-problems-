#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
int max(struct Tree *ptr)
{
if(ptr!=NULL)
{
    ptr=ptr->rc;
}
return ptr->data;
}
struct Tree *create(int value)
{
    struct Tree *new=(struct Tree*)malloc(sizeof(struct Tree));
    new->lc=NULL;
    new->rc=NULL;
    new->data=value;
    return new;
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
struct Tree *delete(struct Tree *ptr,int key)
{
 if (ptr==NULL)
  return NULL;
  if(ptr->data<key)
  {
   ptr->rc=delete(ptr->rc,key);
  }
  if(ptr->data>key)
  {
    ptr->lc=delete(ptr->rc,key);
  }
  if(ptr->data==key)
  {
    struct Tree *inPre=max(ptr);
    ptr->data=inPre->data;
    ptr->lc=delete(ptr->lc,inPre->data);
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