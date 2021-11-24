
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void insert(int ele)
{
    struct node *temp,*curr,*parent;
    temp=(struct  node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        curr=root;
        while(curr)
        {
            parent=curr;
            if(ele<curr->data)
                curr=curr->left;
            else
                curr=curr->right;
        }
        if(ele>parent->data)
        parent->right=temp;
        else
        parent->left=temp;
    }
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
void Delete(int ele)
{
    struct node *curr,*parent;
    int found=0;
    curr=root;
    while(curr)
    {
        if(curr->data==ele)
        {
            found++;
            break;
        }
        else
        {
            parent=curr;
            if(ele>curr->data)
            {
                curr=curr->right;
            }
            else if(ele<=curr->data)
                curr=curr->left;
        }
    }
    if(found==0)
    {
        printf("No Element to Delete\n");
        return;
    }
    if(curr->left==NULL&&curr->right==NULL)
    {
        if(parent->left==curr)
            parent->left=NULL;
        else if(parent->right==curr)
            parent->right=NULL;
        free(curr);
    }
    else if(curr->left!=NULL&&curr->right==NULL||curr->left==NULL&&curr->right!=NULL)
    {
        if(curr->left==NULL&&curr->right!=NULL)
        {
            if(parent->left=curr)
                parent->left=curr->right;
            else if(parent->right=curr)
                parent->right=curr->right;
            curr->right=NULL;
            free(curr);
        }
        else if(curr->left!=NULL&&curr->right==NULL)
        {
            if(curr==parent->right)
                parent->right=curr->left;
            else if(curr==parent->left)
                parent->left=curr->left;
            curr->left=NULL;
            free(curr);
        }
    }
    else if(curr->left!=NULL&&curr->right!=NULL)
    {
        struct node *temp1,*temp2;
        temp1=curr->right;
        if(temp1->right==NULL&&temp1->left==NULL)
        {
            curr->data=temp1->data;
            curr->right=NULL;
            free(temp1);
        }
        else if(temp1->right!=NULL&&temp1->left==NULL)
        {
            curr->data=temp1->data;
            curr->right=temp1->right;
            temp1->right=NULL;
            free(temp1);
        }
        else if(temp1->left!=NULL)
        {
            temp2=temp1->left;
            while(temp2->left)
            {
                temp1=temp1->left;
                temp2=temp2->left;
            }
            curr->data=temp2->data;
            temp1->left=temp2->right;
            temp2->right=NULL;
            free(temp2);
        }
    }

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
            insert(ele); break;
            case 2:printf("Enter Element to Delete: ");
            scanf("%d",&ele);
            Delete(ele);break;
            case 3:printInorder();break;
            case 4:printPreorder();break;
            case 5:printPostorder();break;
            case 6:exit(0);
            default:printf("Invalid Choice,enter choice again");
      }

    }while(ch);
}
