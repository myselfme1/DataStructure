import java.util.*;
class node
{
    int data;
    node next;
    void dispdata()
    {
        System.out.print(data+" ");
    }
}
class SingleLinkedList
{
    public node head;
    void create()
    {
        Scanner sc=new Scanner(System.in);
        node curr=null,temp=null;
        int c=0;
        char ch;
        do 
        {
            curr=new node();
            if(curr==null)
            return;
            c++;
            System.out.print("Enter node"+c+"Data: ");
            curr.data=sc.nextInt();
            curr.next=null;
            if(head==null)
            head=curr;
            else
            temp.next=curr;
            temp=curr;
            System.out.print("If you want to continue press y: ");
            ch=sc.next().charAt(0);
        }while(ch=='y');
    }
    void display()
    {
        node temp=head;
        if(temp==null)
        System.out.println("No Data to display");
        while(temp!=null)
        {
            temp.dispdata();
            temp=temp.next;
        }
        System.out.println();
    }
    void merge(SingleLinkedList s2)
    {
        node temp=this.head;
        while(temp.next!=null)
        temp=temp.next;
        temp.next=s2.head;
    }
    SingleLinkedList merge2(SingleLinkedList s1,SingleLinkedList s2)
    {
        node temp=null;
        node f=s1.head;
        node l=s2.head;
        if(temp==null)
        {
            this.head=new node();
            temp=this.head;
        }
        while(f!=null&&l!=null)
        {
            if(f!=null)
            {
                temp.data=f.data;
                f=f.next;
                temp.next=new node();
                temp=temp.next;
            }
            if(l!=null)
            {
                temp.data=l.data;
                l=l.next;
                temp.next=new node();
                temp=temp.next;
            }
        }
        while(f!=null)
        {
            temp.data=f.data;
                f=f.next;
            if(f!=null)
            {
                temp.next=new node();
                temp=temp.next;    
            }
            
            
        }
        while(l!=null)
        {
             temp.data=l.data;
                l=l.next;
            if(l!=null)
                {
                 temp.next=new node();
                temp=temp.next;  
                }
                 
        }
        return this;
    }
    
}      
class demo
{
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("For First Linked List Enter Data");
        SingleLinkedList s1=new SingleLinkedList();
        SingleLinkedList s2=new SingleLinkedList();
        s1.create();
        System.out.println("For Second Linked List Enter Data");
        s2.create();
        System.out.println("First Linked List is");
        s1.display();
    System.out.println("Second Linked List is");
        s2.display();
        /*System.out.println("After Merging Data = ");
        s1.merge(s2);
        s1.display();*/
        SingleLinkedList s3=new SingleLinkedList();
         System.out.println("After Merging one by one Data = ");
        s3.merge2(s1,s2);
        s3.display();
    }
}