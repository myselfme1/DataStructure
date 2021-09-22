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
void add(struct node*p1,struct node *p2,struct node *p3)
{
        while(p1&&p2)
        {
            if(p1->exp>p2->exp)
            {
                p3->coeff=p1->coeff;
                p3->exp=p1->exp;
                p1=p1->next;
            }
            else if(p1->exp<p2->exp)
            {
                p3->coeff=p2->coeff;
                p3->exp=p2->exp;
                p2=p2->next;
            }
            else
            {
                p3->coeff=p1->coeff+p2->coeff;
                p3->exp=p1->exp;
                p1=p1->next;
                p2=p2->next;
            }
            if(p1&&p2)
            {
                p3->next=(struct node *)malloc(sizeof(struct node));
                p3=p3->next;
                p3->next=NULL;
            }
        }
        while(p1||p2)
        {
            p3->next=(struct node *)malloc(sizeof(struct node));
                p3=p3->next;
                p3->next=NULL;
                if(p1)
                {
                    p3->coeff=p1->coeff;
                    p3->exp=p1->exp;
                    p1=p1->next;
                }
                if(p2)
                {
                    p3->coeff=p2->coeff;
                    p3->exp=p2->exp;
                    p2=p2->next;
                }
        }
}
int main()
{
    struct node *p1,*p2,*p3;
    printf("For 1st Polynomial\n");
    p1=create();
    printf("Ist Polynomial is: ");
    display(p1);
    printf("\nFor 2nd Polynomial\n");
    p2=create();
    printf("2nd Polynomial is: ");
    display(p2);
    p3=(struct node *)malloc(sizeof(struct node));
    add(p1,p2,p3);
    printf("\nAfter adding\n");
    display(p3);
}
