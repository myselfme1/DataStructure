#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int coeff,exp;
    struct node *next;
};
struct node *create()
{
    struct node *curr=(struct node *)malloc(sizeof(struct node));
    char str[5];
    if(curr==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    printf("Enter the Coefficient: ");
    scanf("%d",&curr->coeff);
    printf("Enter the exponent: ");
    scanf("%d",&curr->exp);
    struct node *head=curr;
    while(1)
    {
        fflush(stdin);
        printf("Do yoy want to continue yes/no: ");
        gets(str);
        if(strcmp(str,"no")==0)
            break;
        curr->next=(struct node *)malloc(sizeof(struct node));
        if(curr->next==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        curr=curr->next;
        printf("Enter the Coefficient: ");
    scanf("%d",&curr->coeff);
    printf("Enter the exponent: ");
    scanf("%d",&curr->exp);

    }
    curr->next=NULL;
    return head;
};
void display(struct node *ptr)
{
        while(ptr!=NULL)
        {
            printf("%dx^%d + ",ptr->coeff,ptr->exp);
            ptr=ptr->next;
        }
}
struct node *addnode(struct node *start,int coeff,int exp)
{
    struct node *curr=(struct node *)malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("No Memory");
        return curr;
    }
    curr->coeff=coeff;
    curr->exp=exp;
    curr->next=NULL;
    if(start==NULL)
        return curr;
    struct node *ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=curr;
    return start;
};
void removeduplicates(struct node *start)
{
    struct node *ptr1,*ptr2,*duplicate;
    ptr1=start;
    while(ptr1!=NULL&&ptr1->next!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->exp==ptr2->next->exp)
            {
                ptr1->coeff=ptr1->coeff+ptr2->next->coeff;
                duplicate=ptr2->next;
                ptr2->next=ptr2->next->next;
                free(duplicate);
            }
            else
                ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}
struct node *multiply(struct node*p1,struct node *p2,struct node *p3)
{
        struct node *ptr1=p1,*ptr2=p2;
        int c,p;
        while(ptr1!=NULL)
        {
            while(ptr2!=NULL)
            {
                c=ptr1->coeff*ptr2->coeff;
                p=ptr1->exp+ptr2->exp;
                p3=addnode(p3,c,p);
                ptr2=ptr2->next;
            }
            ptr2=p2;
            ptr1=ptr1->next;
        }
        removeduplicates(p3);
        return p3;
}
int main()
{
    struct node *p1,*p2,*p3=NULL;
    printf("For 1st Polynomial\n");
    p1=create();
    printf("Ist Polynomial is: ");
    display(p1);
    printf("\nFor 2nd Polynomial\n");
    p2=create();
    printf("2nd Polynomial is: ");
    display(p2);
    p3=multiply(p1,p2,p3);
    printf("\nAfter Multiplication\n");
    display(p3);
}
