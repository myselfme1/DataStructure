#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*current,*ptr;
void create()
{
    char ch;
    int c=0;
    do
        {
            c++;
    current=(struct node *)malloc(sizeof(struct node));
    if(current==NULL)
    {
        printf("No Memory");
        exit(0);
    }
    printf("Enter node %d Data: ",c);
    scanf("%d",&current->data);
    current->next=NULL;
    if(head==NULL)
            head=current;
        else
        {
            ptr->next=current;
        }
        ptr=current;
        printf("Do you want to continue Press y/n :");
        scanf(" %c",&ch);
        }while(ch=='y');

}
void Display()
{
    printf("Elements are\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void DeletefromEnd()
{
    if(head==NULL)
    {
        printf("No List\n");
        return;
    }
    current=head;
    while(current->next!=NULL)
    {
        ptr=current;
        current=current->next;
    }
    printf("\nAfter Deleting %d list is\n",current->data);
    current=ptr;
    current->next=NULL;
}
void main()
{
    create();
    Display();
    DeletefromEnd();
    Display();
}
