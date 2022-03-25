#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int status;
    char ch;
};
struct adjs
{
    int adj;
};
struct graph
{
    struct node nodes[50];
    struct adjs adjc[50][50];
}g;
int n=0;
void dfs(char);
void main()
{
    char ch='y',ch1;
    int i=0,j;
    while(ch=='y')
    {
        printf("\nEnter the vertices: ");
        //fflush(stdin);
        ch1=getche();
        n++;
        g.nodes[i++].ch=ch1;
        printf("\nEnter (y/n) for another node: ");
        fflush(stdin);
        ch=getche();
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\n D you want to connect %c and %c press (y/n): ",g.nodes[i].ch,g.nodes[j].ch);
            fflush(stdin);
            ch1=getche();
            if(ch1=='y')
            {
                g.adjc[i][j].adj=1;
            }
            else
                g.adjc[i][j].adj=0;
        }
    }
    printf("Adjacent Matrix\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",g.adjc[i][j].adj);
        }
        printf("\n");
    }
    printf("\nEnter a node for traversing: ");
    ch1=getche();
    dfs(ch1);
}
void dfs(char ch)
{
    char ch1,stack[30];
    int i,j,top=0;
    for(i=0;i<n;i++)
    {
        g.nodes[i].status=1;
    }
    stack[top]=ch;
    top=top+1;
    while(top!=-1)
    {
        ch1=stack[top];
        top--;
        i=0;
        while(g.nodes[i].ch!=ch1)
        {
            i++;
        }
        printf(" %c",ch1);
        g.nodes[i].status=3;
        for(j=0;j<n;j++)
        {
            if((g.nodes[j].status==1)&&(g.adjc[i][j].adj==1))
            {
                top=top+1;
                stack[top]=g.nodes[j].ch;
                g.nodes[j].status=2;
            }
        }
    }
}