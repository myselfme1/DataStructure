//I think this program is wrong,
//This is for DFS
#include<stdio.h>
void BFS(int);
int graph[10][10],visited[10],total;
void main()
{
    int i,j;
    printf("Enter total no of Vertex: ");
    scanf("%d",&total);
    printf("Enter adjacent matrix:\n");
    for(i=0;i<total;i++)
    {
        for(j=0;j<total;j++)
        scanf("%d",&graph[i][j]);
    } 
    for(i=0;i<total;i++)
    visited[i]=0;
    BFS(0);
}
void BFS(int vertex)
{
    int j;
    printf("%d\t",vertex);
    visited[vertex]=1;
     for(j=0;j<total;j++)
     {
         if(!visited[j]&&graph[vertex][j]==1)
         BFS(j);
     }
}