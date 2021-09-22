#include<stdio.h>
#include<stdlib.h>
struct CQL
{
    int data;
    struct CQL *next;
};
struct CQL *front,*rear;
void insert(int element)
{
    if(rear==NULL)
    {
        rear=(struct CQL *)malloc(sizeof(struct CQL));
        if(rear==NULL)
        {
            printf("No Memory");
            return;
        }
        rear->data=element;
        rear->next=rear;
        front=rear;
        return;
    }
    rear->next=(struct CQL *)malloc(sizeof(struct CQL));
    if(rear->next==NULL)
        {
            printf("No Memory");
            return;
        }
    rear=rear->next;
    rear->data=element;
    rear->next=front;
}
void Delete()
{
    if(front==NULL)
    {
        printf("Circular Queue underflow\n");
        return;
    }
    struct CQL *temp=front;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        printf("Delete Element = %d\n",temp->data);
        free(temp);
        return;
    }
    front=front->next;
    rear->next=front;
     printf("Delete Element = %d\n",temp->data);
        free(temp);
}
void peek()
{
    if(front==NULL)
    {
        printf("Circular Queue underflow\n");
        return;
    }
    printf("Top Element = %d\n",front->data);
}
void display()
{
     if(front==NULL)
    {
        printf("Circular Queue underflow\n");
        return;
    }
    struct CQL *temp=front;
    printf("Elements are \n");
    do
    {
     printf("%d ",temp->data);
     temp=temp->next;
    }while(temp!=front);
}
void main()
{
    int ele,ch;
    while(1)
    {
        printf("Enter Your Choice 1.insert 2.Delete 3.peek 4.Display 5.exit : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter Element to push: ");
            scanf("%d",&ele);
            insert(ele); break;
            case 2:Delete();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);break;
            default:printf("Invalid Choice");
        }
    }
}
