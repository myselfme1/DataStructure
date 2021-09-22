#include<stdio.h>
#include<stdlib.h>
#define max 5
int arr[max];
int rear=-1,front=-1;
void enqueue_rear(int ele)
{
    if((front==0&&rear==max-1)||(front==rear+1))
    {
        printf("Dequeue overflow\n");
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
    arr[rear]=ele;
}
void enqueue_front(int ele)
{
  if((front==0&&rear==max-1)||(front==rear+1))
    {
        printf("Dequeue overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
        front=max-1;
    else
        front--;
    arr[front]=ele;
}
void dequeue_front()
{
    if(front==-1)
    {
        printf("Dequeue underflow\n");
        return;
    }
    printf("Remove Element = %d\n",arr[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
        return;
    }
    else if(front==max-1)
    {
        front=0;
    }
    else
        front++;
}
void dequeue_rear()
{
    if(front==-1)
    {
        printf("Dequeue underflow\n");
        return;
    }
    printf("Remove Element = %d\n",arr[rear]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
        return;
    }
    else if(rear==0)
    {
        rear=max-1;
    }
    else
        rear--;
}
void display()
{
     if(front==-1)
    {
        printf("Dequeue underflow\n");
        return;
    }
    int i;
    printf("Elements are\n");
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for(i=front;i<max;i++)
            printf("%d ",arr[i]);
        for(i=0;i<rear;i++)
            printf("%d ",arr[i]);
    }
    printf("\n");
}
void input_restricted_dequeue()
{
    int ch,ele;
    while(1)
    {
        printf("Enter Choice:\n");
        printf("1. Insert in rear or enqueue rear\n");
         printf("2. Delete from front or dequeue front\n");
         printf("3. Delete from rear or dequeue rear\n");
         printf("4. display\n");
         printf("5. back to main\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:printf("Enter Element: ");
             scanf("%d",&ele);
             enqueue_rear(ele);break;
             case 2: dequeue_front();break;
             case 3:dequeue_rear();break;
             case 4:display();break;
             case 5:return;
             default: printf("Invalid choice\n");
         }
    }
}
void output_restricted_dequeue()
{
    int ch,ele;
    while(1)
    {
        printf("Enter Choice:\n");
        printf("1. Insert in rear or enqueue rear\n");
         printf("2. Insert in front or enqueue front\n");
         printf("3. Delete from front or dequeue front\n");
         printf("4. display\n");
         printf("5. back to main\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:printf("Enter Element: ");
             scanf("%d",&ele);
             enqueue_rear(ele);break;
             case 3: dequeue_front();break;
             case 2:printf("Enter Element: ");
             scanf("%d",&ele);
             enqueue_front(ele);break;
             case 4:display();break;
             case 5:return;
             default: printf("Invalid choice\n");
         }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("Enter Your Choice\n");
        printf("1. input_restricted_dequeue\n");
        printf("2. output_restricted_dequeue\n");
        printf("3. exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:input_restricted_dequeue();break;
            case 2:output_restricted_dequeue();break;
            case 3:exit(0);
            default :printf("Invalid choice\n");
        }
    }
}
