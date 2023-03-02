/*Suppose the student information i.e. <roll no, name, CGPA> are stored using binary
search tree. Write a function/pseudo code to delete all the information of a student with
CGPA < 5.0.*/
#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int rollno,cgpa;
    //char name[20];
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *max(struct Tree *ptr)
{
    while(ptr->rc!=NULL)
    {
        ptr=ptr->rc;
    }
    return ptr;
}
struct Tree *delete(struct Tree *root,int key)
{
    struct Tree *ptr=root;
    if(ptr->cgpa<key)
    {
        ptr->lc=delete(ptr->lc,key);
    }
    if(ptr->cgpa>key)
    {
        ptr->rc=delete(ptr->rc,key);
    }
    if(ptr->cgpa==key)
    {
        
        if(ptr->rc==NULL && ptr->lc!=NULL)
        {
            struct Tree *temp=ptr->lc;
            free(ptr);
            return temp;
        }
        if(ptr->lc==NULL && ptr->rc!=NULL)
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
            temp->cgpa=ptr->cgpa;
            ptr->lc=delete(ptr->lc,temp->cgpa);
            return temp;
        }
    }
}
void traversal(struct Tree *root)
{
    struct Tree *ptr=root;
    if(ptr)
    {
        traversal(ptr->lc);
        if(ptr->cgpa<5)
        {
            int value=ptr->cgpa;
            delete(root,value);
        }
        traversal(ptr->rc);
    }
}
void inOrder(struct Tree *ptr)
{
    if(ptr)
    {
        inOrder(ptr->lc);
        printf("%d %d\n",ptr->rollno,ptr->cgpa);
        inOrder(ptr->rc);
    }
}
int main (void)
{
struct Tree *root=(struct Tree *)malloc(sizeof(struct Tree));
struct Tree *l1=(struct Tree*)malloc(sizeof(struct Tree));
struct Tree *r1=(struct Tree*)malloc(sizeof(struct Tree));
root->rollno=1;
// root->name="Ravi";
root->cgpa=8;
root->lc=l1;
root->rc=r1;
l1->rollno=2;
// l1->name="Neha";
l1->cgpa=4;
l1->lc=NULL;
l1->rc=NULL;
r1->rollno=3;
// r1->name="Isha";
r1->cgpa=10;
r1->lc=NULL;
r1->rc=NULL;
inOrder(root);
traversal(root);
inOrder(root);

return 0;
}