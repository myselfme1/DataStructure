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
void DeletefromMiddle()
{
    int pos;
    printf("\nEnter Position to Delete: ");
    scanf("%d",&pos);
    if(pos<1||pos>count())
    {
        printf("Invalid Position");
        return ;
    }
    ptr=head;
    int i=1;
    while(i<pos)
    {
     current=ptr;
     ptr=ptr->next;
     i++;
    }
    current->next=ptr->next;
    free(ptr);
    printf("After Deleting New List is\n");
}
int count()
{
    int c=0;
    ptr=head;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
void main()
{
    create();
    Display();
    DeletefromMiddle();
   // printf("%d",count());
    Display();
}

