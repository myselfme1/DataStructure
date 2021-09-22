#include<stdio.h>
#include<stdlib.h>
struct node
{
    int r,c,val;
    struct node *next;
};
struct node *head,*curr,*ptr;
void create(int row,int col,int value)
{
    struct node *curr=(struct node *)malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("No memory\n");
        return;
    }
    curr->r=row;
    curr->c=col;
    curr->val=value;
    curr->next=NULL;
    if(head==NULL)
    {
        head=curr;
        return;
    }
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=curr;
}
void display()
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d %d %d\n",ptr->r,ptr->c,ptr->val);
        ptr=ptr->next;
    }
}
void main()
{
    int row,col,i,j,k=0,nonzero=0;
    printf("Enter row and column\n");
    scanf("%d %d",&row,&col);
    int sp[row][col];
    printf("Enter %d Elements\n",row*col);
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        scanf("%d",&sp[i][j]);
    printf("Elements are\n");
    for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
        printf("%d ",sp[i][j]);
        printf("\n");
        }
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
            if(sp[i][j]!='\0')
            nonzero++;
        if(nonzero>row*col/2)
        {
            printf("Not Sparse Matrix\n");
            return;
        }
        create(row,col,nonzero);
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(sp[i][j]!='\0')
                create(i,j,sp[i][j]);
            printf("Sparse Matrix Representation: \n");
            display();

}
