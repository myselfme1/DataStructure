#include<stdio.h>
#include<stdlib.h>
#define max 5
struct Queue
{
    int arr[max];
int front,rear;
};
struct Queue Q;
void create()
{
    Q.rear=-1;
    Q.front=-1;
}
void insert(int ele)
{
    if(Q.rear==max-1)
    {
        printf("Queue Overflow\n");
        return ;
    }
    if(Q.front==-1)
        Q.front=0;
    Q.rear++;
    Q.arr[Q.rear]=ele;
}
void Delete()
{
    if(Q.front==-1)
    {
        printf("No element to Delete OR Queue Underflow\n");
        return ;
    }
    printf("Delete Element = %d\n",Q.arr[Q.front]);
    if(Q.front==Q.rear)
    {
        Q.front=-1;
        Q.rear=-1;
        return ;
    }
    Q.front++;
}
void peek()
{
    if(Q.front==-1)
    {
        printf("No element Present,Queue Underflow\n");
        return ;
    }
    printf("Top Element = %d\n",Q.arr[Q.front]);
}
void Display()
{
    if(Q.front==-1)
    {
        printf("No element Present,Queue Underflow\n");
        return ;
    }
    printf("Elements in Queue are\n");
    int i;
    for(i=Q.front;i<=Q.rear;i++)
        printf("%d ",Q.arr[i]);
}
void main()
{
    create();
    int ele,ch;
    while(1)
    {
        printf("\nEnter Your Choice 1.Insert 2.Delete 3.peek 4.Display 5.exit : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter Element to Insert: ");
            scanf("%d",&ele);
            insert(ele); break;
            case 2:Delete();break;
            case 3:peek();break;
            case 4:Display();break;
            case 5:exit(0);break;
            default:printf("Invalid Choice\n");
        }
    }
}
