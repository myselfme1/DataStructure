#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *ptr,int ele)
{
   if(ptr==NULL)
   {
       ptr=(struct node *)malloc(sizeof(struct node));
       ptr->left=NULL;
       ptr->data=ele;
       ptr->right=NULL;
   }
    if(ele<ptr->data)
        ptr->left=insert(ptr->left,ele);
    if(ele>ptr->data)
        ptr->right=insert(ptr->right,ele);
    return ptr;
}
void inorder(struct node *temp)
{
 if(temp->left)
    inorder(temp->left);
 printf("%d ",temp->data);
 if(temp->right)
    inorder(temp->right);
}
void printInorder()
{
    if(root==NULL)
        printf("Tree is Empty\n");
    else
        inorder(root);
}
void preorder(struct node *temp)
{
    printf("%d ",temp->data);
    if(temp->left)
    preorder(temp->left);
    if(temp->right)
    preorder(temp->right);
}
void printPreorder()
{
    if(root==NULL)
    printf("Tree is Empty\n");
    else
    preorder(root);
}
void postorder(struct node *temp)
{
    if(temp->left)
        postorder(temp->left);
    if(temp->right)
        postorder(temp->right);
        printf("%d ",temp->data);
}
void printPostorder()
{
    if(root==NULL)
    printf("Tree is Empty\n");
    else
    postorder(root);
}
int main()
{
    int ch,ele;
    do
    {
        printf("Enter your choice: 1.Insert 2.Delete 3.Traverse in Inorder 4.PreOrder 5.Postorder 6.exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter Element to Insert: ");
            scanf("%d",&ele);
            root=insert(root,ele); break;
            case 2:
            case 3:printInorder();break;
            case 4:printPreorder();break;
            case 5:printPostorder();break;
            case 6:exit(0);
            default:printf("Invalid Choice,enter choice again\n");
      }

    }while(ch);
}