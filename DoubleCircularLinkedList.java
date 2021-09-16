import java.util.*;
class node
{
    node prev;
    int data;
    node next;
    void dispdata()
    {
        System.out.println(data+" ");
    }
}
class DL
{
    private node head;
    void create()
    {
        node curr=null,temp=null;
        int c=0;
        Scanner sc=new Scanner(System.in);
        char ch;
        do
        {
           curr=new node();
           if(curr==null)
           {
               System.out.println("Node can't be created");
               return;
           }
           c++;
           System.out.print("Enter node "+c+" Data: ");
           curr.data=sc.nextInt();
           curr.next=curr;
           curr.prev=curr;
           if(head==null)
           head=curr;
           else
           {
               curr.next=head;
               curr.prev=temp;
               head.prev=curr;
               temp.next=curr;
           }
           temp=curr;
           System.out.print("To continue press y");
           ch=sc.next().charAt(0);
        }while(ch=='y');
    }
    void displayfromfront()
    {
        node temp=head;
        if(temp==null)
        {
            System.out.println("No ELement in List");
            return;
        }
        do
        {
            temp.dispdata();
            temp=temp.next;
        }while(temp!=head);
    }
    void displayfromback()
    {
        node temp=head;
        if(temp==null)
        {
            System.out.println("No ELement in List");
            return;
        }
        while(temp.next!=head)
        temp=temp.next;
        while(temp!=head)
        {
            temp.dispdata();
            temp=temp.prev;
        }
        temp.dispdata();
    }
    void InsertatBegin(int ele)
    {
        node curr=new node();
        curr.data=ele;
        if(head==null)
        {
            curr.next=curr;
            curr.prev=curr;
            head=curr;
            return;
        }
        curr.next=head;
        head.prev=curr;
        node temp=head;
        while(temp.next!=head)
        temp=temp.next;
        curr.prev=temp;
        temp.next=curr;
        head=curr;
    }
    void InsertatEnd(int ele)
    {
         node curr=new node();
        curr.data=ele;
        if(head==null)
        {
            curr.next=curr;
            curr.prev=curr;
            head=curr;
            return;
        }
        head.prev=curr;
        node temp=head;
        while(temp.next!=head)
        temp=temp.next;
        temp.next=curr;
        curr.prev=temp;
        curr.next=head;
    }
    void DeletefromBegin()
    {
        if(head==null)
        {
            System.out.println("No Element in List to delete");
            return;
        }
        System.out.println("Delete Element = "+head.data);
        node temp=head;
        while(temp.next!=head)
        temp=temp.next;
        temp.next=head.next;
        head=head.next;
        head.prev=temp;
    }
    void DeletefromEnd()
    {
         if(head==null)
        {
            System.out.println("No Element in List to delete");
            return;
        }
        node temp=head,tem=null;
        while(temp.next!=head)
        {
            tem=temp;
            temp=temp.next;
        }
        System.out.println("Delete Element = "+temp.data);
        tem.next=head;
        head.prev=tem;
    }
}
class demo
{
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        DL ob=new DL();
        ob.create();
       /* ob.displayfromfront();
        System.out.println();
        ob.displayfromback();*/
        int ch;
        do
        {
System.out.println("Enter your choice: 1.InsertatBegin 2.InsertatEnd 3.DeletefromBegin 4.DeletefromEnd 5displayfromfront 6.Displayfromback");
            ch=sc.nextInt();
            int ele;
            switch(ch)
            {
            case 1:System.out.print("Enter Element to Insert: ");
            ele=sc.nextInt();
            ob.InsertatBegin(ele);break;
            case 2:System.out.print("Enter Element to Insert: ");
            ele=sc.nextInt();
            ob.InsertatEnd(ele);break;
            case 3:ob.DeletefromBegin();break;
            case 4:ob.DeletefromEnd();break;
            case 6:System.out.println("Elements from back are");ob.displayfromback();break;
            case 5:System.out.println("Elements from front are");ob.displayfromfront();break;
            default:System.out.println("Invalid choice");
            }
        }while(ch<=6);
    }
}