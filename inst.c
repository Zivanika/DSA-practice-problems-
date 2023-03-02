#include <stdio.h>
struct Tree{
    struct Tree *lc;
    struct Tree *rc;
    int data;
}
struct Tree *stack[20];
int top=-1;
void InOrder(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        top++;
        stack[top]=ptr;
        ptr=ptr->lc;
    }

    while(top!=-1)
    {
        ptr=stack[top];
        printf("%d",ptr->data);
        top--;
        while(ptr->rc!=NULL)
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
void PreOrder(struct Node *ptr)
{
    top++;
    stack[top]=ptr;
    while(top!=-1)
    {
      ptr=stack[top];
      printf("%d",ptr->data);
      top--;
      if(ptr->rc!=NULL)
      {
        stack[++top]=ptr->rc;
      }
      if(ptr->lc!=NULL)
      {
        stack[++top]=ptr->rc;
      }
    }
    
}
struct Tree *stack1[20];
struct Tree *stack2[20];
void PostOrder(struct Node *ptr)
{
top1++;
stack1[top1]=ptr;
while(top1!=-1)
{
    ptr=stack1[top1];
    top1--;
    stack2[++top2]=ptr;
    if(ptr->lc!=NULL)
    {
        stack1[++top1]=ptr->lc;
    }
    if(ptr->rc!=NULL)
    {
        stack1[++top1]=ptr->rc;
    }
}

}
int main (void)
{
return 0;
}