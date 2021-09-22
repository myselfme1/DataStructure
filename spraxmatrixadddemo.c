//row  spraxmatrixadd
#include <stdio.h>
#include<stdlib.h>
struct Link
{
	int r;
	int c;
	int v;
	struct Link *next;
};
struct	Link * create(struct	Link *head,int row,int col,int value)
{
	struct Link *cur=(struct Link *)malloc(sizeof(struct Link ));
	if(cur==NULL)
	{
		printf("no memory ");
		return ;
	}
	cur->r=row;
	cur->c=col;
	cur->v=value;
	cur->next=NULL;
	if(head==NULL)
	{
		head=cur;
		return head;
	}
	struct Link *ptr=head;
	while(ptr->next!=NULL)
	{
      ptr=ptr->next;
	}
	ptr->next=cur;
	return head;
}
void display(struct	Link *head)
{
	struct	Link *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d %d %d\n",ptr->r,ptr->c,ptr->v);
		ptr=ptr->next;
	}
}
void input(int spr[30][30],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&spr[i][j]);
		}
	}
}
void displaya(int spr[30][30],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",spr[i][j]);
		}
		printf("\n");
	}
}
int count(int spr[30][30],int r,int c)
{
	int nzero=0,i,j;
	 for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(spr[i][j]!=0)
				{
					nzero++;
				}
			}
		}
	if(nzero>(r*c)/2)
	{
		printf("not sparse matrix");
		return 0;
	}
	return nzero;
}
 struct Link * cr(int spr[30][30],int r1,int c1,int nzero)
{
   struct Link *start=NULL;
   int i,j;
	start=create(start,r1,c1,nzero);
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
              if(spr[i][j]!=0)
			{
				  create(start,i,j,spr[i][j]);
			}
		}
	}
	return start;
}
struct	Link *add(struct	Link *s1,struct	Link *s2,struct	Link *s3)
{

	while(s1!=NULL&&s2!=NULL)
	{
		if((s1->r==s2->r))
		{
			if(s1->c==s2->c)
			{
               s3=create(s3,s1->r,s1->c,s1->v+s2->v);
		      s1=s1->next;
		      s2=s2->next;
			}
		   else if(s1->c<s2->c)
			{
                s3=create(s3,s1->r,s1->c,s1->v);
		         s1=s1->next;
			}
			else
			{
				s3=create(s3,s2->r,s2->c,s2->v);
		         s2=s2->next;
			}
		}
         else if(s1->r<s2->r)
		{
			 s3=create(s3,s1->r,s1->c,s1->v);
		       s1=s1->next;
		   
		}
		else 
		{
		   s3=create(s3,s2->r,s2->c,s2->v);
		   s2=s2->next;
		}
	}

	while (s1!=NULL)
	{
		 s3=create(s3,s1->r,s1->c,s1->v);
		       s1=s1->next;
	}
	while(s2!=NULL)
	{
		s3=create(s3,s2->r,s2->c,s2->v);
		       s2=s2->next;
	}
     return s3;
}
void main()
{
	
	int r1,c1,r2,c2;
	printf("enter row and col of sparsh matrix 1\n");
	scanf("%d %d",&r1,&c1);
	printf("enter row and col of sparsh matrix 2\n");
	scanf("%d %d",&r2,&c2);
	if((r1!=r2)||(c1!=c2))
	{
		printf("add not posible");
		exit(0);
	}
	int  spr1[30][30],spr2[30][30],i,j;
	printf("enter first sparsh matrix %d elements\n",r1*c1);
	//input  for sparsh matrix
	input(spr1,r1,c1);
	//display  sparsh matrix
	printf("\nfirst sparsh matrix \n");
	displaya(spr1,r1,c1);
     //check spar matrix
	 int nzero=count(spr1,r1,c1);
      if(nzero==0)
	{
		  exit(0);
	}
	printf("enter second sparsh matrix %d elements\n",r2*c2);
	//input  for sparsh matrix
	input(spr2,r2,c2);
	//display  sparsh matrix
	int nzero1=count(spr2,r2,c2);
      if(nzero1==0)
	{
		  exit(0);
	}
	printf("\nsecond sparsh matrix \n");
	displaya(spr2,r2,c2);
     //check spar matrix
	/* conversion first sparmatrix  tript  format row  */
	struct Link *s1=cr(spr1,r1,c1,nzero);
	/*  display triplet  matrix;  */
	printf("values of  sparse  matrix1 tript  format \n");
	display(s1);
	/* conversion second spamatrix  tript  format row  */
	struct Link *s2=cr(spr2,r2,c2,nzero);
	/*  display triplet  matrix;  */
	printf("values of  sparse  matrix2 tript  format \n");
	display(s2);

	struct Link *s3=NULL;
	s3=add(s1->next,s2->next,s3);
	printf("values of result  sparse  matrix tript  format \n");
	display(s3);

}