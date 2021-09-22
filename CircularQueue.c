#include<stdio.h>
#include<stdlib.h>
#define max 5
int arr[max];
int front=-1,rear=-1;
void insert(int element)
{
    if((rear==max-1&&front==0)||(front==rear+1))
    {
        printf("Circular Queue Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==max-1)
    {
        rear=0;
    }
    else
        rear++;
    arr[rear]=element;

}
void Delete()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Delete Element = %d\n",arr[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
        return;
    }
    else if(front==max-1)
    {
        front=0;
        return;
    }
    front++;
}
void peek()
{
     if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Top Element = %d\n",arr[front]);
}
void Display()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    int i;
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for(i=front;i<max;i++)
            printf("%d ",arr[i]);
        for(i=0;i<=rear;i++)
            printf("%d ",arr[i]);
    }
}
int main()
{
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
            default:printf("Invalid Choice");
        }
    }
}

