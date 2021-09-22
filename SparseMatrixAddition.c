#include<stdio.h>
#include<stdlib.h>
struct node
{
    int r,c,val;
    struct node *next;
};
struct node *create(struct node *head,int row,int col,int value)
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
        return head;
    }
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=curr;
    return head;
}
void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d %d %d\n",ptr->r,ptr->c,ptr->val);
        ptr=ptr->next;
    }
}
void input(int sp[50][50],int row,int col)
{
    int j,i;
    printf("Enter %d Elements\n",row*col);
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        scanf("%d",&sp[i][j]);
}
void Mdisplay(int sp[50][50],int row,int col)
{
 for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
        printf("%d ",sp[i][j]);
        printf("\n");
        }
}
struct node *cr(int sp[50][50],int row,int col,int nzero)
{
    int i,j;
    struct node *start=NULL;
    start=create(start,row,col,nzero);
    for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(sp[i][j]!='\0')
                create(start,i,j,sp[i][j]);
                return start;
};
struct node *add(struct node *s1,struct node *s2,struct node *s3)
{
    while(s1!=NULL&&s2!=NULL)
    {
        if(s1->r==s2->r)
        {
            if(s1->c==s2->c)
            {
                s3=create(s3,s1->r,s1->c,s1->val+s2->val);
                s1=s1->next;
                s2=s2->next;
            }
            else if(s1->c<s2->c)
            {
                s3=create(s3,s1->r,s1->c,s1->val);
                s1=s1->next;
            }
            else
            {
                s3=create(s3,s2->r,s2->c,s2->val);
                s2=s2->next;
            }
        }
        else if(s1->r<s2->r)
        {
            s3=create(s3,s1->r,s1->c,s1->val);
                s1=s1->next;
        }
        else
            {
                s3=create(s3,s2->r,s2->c,s2->val);
                s2=s2->next;
            }

    }
	while (s1!=NULL)
	{
		 s3=create(s3,s1->r,s1->c,s1->val);
		       s1=s1->next;
	}
	while(s2!=NULL)
	{
		s3=create(s3,s2->r,s2->c,s2->val);
		       s2=s2->next;
	}
    return s3;
};
int count(int sp[50][50],int row,int col)
{
    int i,j,nonzero=0;
    for(i=0;i<row;i++)
            for(j=0;j<col;j++)
            if(sp[i][j]!='\0')
            nonzero++;
        if(nonzero>row*col/2)
        {
            printf("Not Sparse Matrix\n");
            return 0;
        }

            return nonzero;
}
void main()
{
    int row,col,i,j;
    printf("Enter row and column\n");
    scanf("%d %d",&row,&col);
    int sp1[row][col],sp2[row][col];
    printf("For Ist Matrix ");
    input(sp1,row,col);
    printf("Elements in Ist Matrix are\n");
    Mdisplay(sp1,row,col);
     printf("For IInd Matrix ");
    input(sp2,row,col);
    printf("Elements in IInd Matrix are\n");
    Mdisplay(sp2,row,col);
    int nzero1=count(sp1,row,col);
    if(nzero1==0)
        exit(0);
    int nzero2=count(sp2,row,col);
    if(nzero2==0)
        exit(0);
        struct node *s1=cr(sp1,row,col,nzero1);
        printf("Sparse Matrix 1 representation in triplet format = \n");
        display(s1);
        struct node *s2=cr(sp2,row,col,nzero2);
        printf("Sparse Matrix 2 representation in triplet format = \n");
        display(s2);
                struct node *s3=NULL;
                s3=add(s1->next,s2->next,s3);
            printf("Sparse Matrix Representation after addition: \n");
            display(s3);

}
