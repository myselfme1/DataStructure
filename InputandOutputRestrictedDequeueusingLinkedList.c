#include<stdio.h>
#include<stdlib.h>
#define max 5
struct dequeue
{
    int data;
    struct dequeue *next;
};
struct dequeue *front,*rear;
void enqueue_front(int ele)
{
    struct dequeue *temp=(struct dequeue *)malloc(sizeof(struct dequeue));
    if(temp==NULL)
    {
        printf("No Memory");
        return;
    }
    temp->data=ele;
    temp->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=temp;
        rear=temp;
        return;
    }
    temp->next=front;
    front=temp;
}
void enqueue_rear(int ele)
{
    struct dequeue *temp=(struct dequeue *)malloc(sizeof(struct dequeue));
    if(temp==NULL)
    {
        printf("No Memory");
        return;
    }
    temp->data=ele;
    temp->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=temp;
        rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
 void dequeue_front()
 {
     if(front==NULL)
     {
         printf("Queue underflow\n");
         return;
     }
     printf("Delete Element = %d\n",front->data);
     struct dequeue *ptr=front;
     if(front==rear)
     {
         front=NULL;
         rear=NULL;
         free(ptr);
     }
     front=front->next;
     free(ptr);
 }
 void dequeue_rear()
 {
     if(front==NULL)
     {
         printf("Queue underflow\n");
         return;
     }
     printf("Delete Element = %d\n",rear->data);
     struct dequeue *temp=rear;
     if(front==rear)
     {
         front=NULL;
         rear=NULL;
         free(temp);
     }
     struct dequeue *ptr;
     temp=front;
     while(temp->next!=NULL)
     {
         ptr=temp;
         temp=temp->next;
     }
     rear=ptr;
     rear->next=NULL;
     free(temp);

 }
 void display()
 {
      if(front==NULL)
     {
         printf("Queue underflow\n");
         return;
     }
     printf("Elements are\n");
     struct dequeue *temp=front;
     while(temp!=NULL)
     {
         printf("%d ",temp->data);
         temp=temp->next;
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
