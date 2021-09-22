#include<stdio.h>
#include<stdlib.h>
#define max 5
struct Queue
{
    int data;
    struct Queue *next;
};
struct Queue *front,*rear;
void insert(int ele)
{
    struct Queue *current=(struct Queue *)malloc(sizeof(struct Queue));
    if(current==NULL)
    {
        printf("Queue Overflow\n");
    }
    current->data=ele;
    current->next=NULL;
    if(front==NULL)
    {
        front=current;
    }
    else
     {
         rear->next=current;
     }
    rear=current;
}
void Delete()
{
    if(front==NULL)
     {
        printf("No element Present,Queue Underflow\n");
        return ;
    }
    printf("Delete Element = %d\n",front->data);
    struct Queue *temp=front;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        free(temp);
        return;
    }
    front=front->next;
    free(temp);
}
void peek()
{
    if(front==NULL)
    {
        printf("No element Present,Queue Underflow\n");
        return ;
    }
    printf("Top Element = %d\n",front->data);
}
void Display()
{
    if(front==NULL)
    {
        printf("No element Present,Queue Underflow\n");
        return ;
    }
    printf("Elements in Queue are\n");
   struct Queue *ptr=front;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void main()
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
            default:printf("Invalid Choice\n");
        }
    }
}
