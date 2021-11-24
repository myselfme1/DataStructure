#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *create()
{
    struct node *ptr;
    int x;
    printf("Enter Data(press -1 for no data): ");
        scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=x;
    printf("Enter Left child of %d\n",x);
    ptr->left=create();
    printf("Enter Right child of %d\n",x);
    ptr->right=create();
    return ptr;
};
void preorder(struct node *ptr)
{
    if(ptr!=NULL)
   { printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
   }
}
void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
}
int c=0,s=0,leafnode=0;
int sum(struct node *ptr)
{

    if(ptr!=NULL)
   {
       if(ptr->left==NULL&&ptr->right==NULL)
        leafnode++;
       c++;
       s+=ptr->data;
    sum(ptr->left);
    sum(ptr->right);
   }
   return s;
}
void DisplayLeafnode(struct node *ptr)
{
    if(ptr!=NULL)
    {
        if(ptr->left==NULL&&ptr->right==NULL)
            printf("%d ",ptr->data);
        DisplayLeafnode(ptr->left);
        DisplayLeafnode(ptr->right);
    }
}
void DisplayNonLeafnode(struct node *ptr)
{
    if(ptr!=NULL)
    {
        if(ptr->left!=NULL||ptr->right!=NULL)
            printf("%d ",ptr->data);
        DisplayNonLeafnode(ptr->left);
        DisplayNonLeafnode(ptr->right);
    }
}
void main()
{
    struct node *root;
    root=create();
    printf("Elements in preorder are: ");
    preorder(root);
    printf("\nElements in inorder are: ");
inorder(root);
    printf("\nTotal Elements = %d\nSum of Elements = %d\n",c,sum(root));
    printf("Total number of Leaf nodes =%d\n",leafnode);
    printf("Leaf Nodes are: ");
    DisplayLeafnode(root);
    printf("\nNon-Leaf Nodes are: ");
    DisplayNonLeafnode(root);
//    printf("Elements in inorder are: \n",);
}
