import java.util.*;
class node
{
    int data;
    node next;
    node(int data)
    {
        this.data=data;
    }
}
class Stack
{
    private node top;
    void push(int ele)
    {
        if(top==null)
        {
            top=new node(ele);
           // top.data=ele;
            top.next=null;
            return;
        }
        node curr=new node(ele);
        //curr.data=ele;
        curr.next=top;
        top=curr;
    }
    void pop()
    {
        if(top==null)
        {
            System.out.println("Stack Underflow,no Element to delete");
            return;
        }
        System.out.println("Delete Element = "+top.data);
        top=top.next;
    }
    void peek()
    {
        if(top==null)
        {
            System.out.println("Stack Underflow,no Element");
            return;
        }
        System.out.println("top Element = "+top.data);
    }
    void display()
    {
        if(top==null)
        {
            System.out.println("Stack Underflow,no Element to display");
            return;
        }
        System.out.print("Elements are = ");
        node temp=top;
        while(temp!=null)
        {
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
    }
    void size()
    {
        int c=0;
         if(top==null)
        { 
            c=0;
        }   
        node temp=top;
        while(temp!=null)
        {
           c++;
            temp=temp.next;
        }
        System.out.println("No of Elements = "+c);
      //  return c;
    }
}
class demo
{
    public static void main(String ar[])
    {
        Scanner sc=new Scanner(System.in);
        Stack s=new Stack();
        int ch;
         do
        {
            System.out.println("Enter choice 1.push 2.pop 3.display 4.size 5.peek 8.exit");
             ch=sc.nextInt();
            switch(ch)
            {
                case 1:System.out.print("ENter Element to push:");
                s.push(sc.nextInt());break;
                case 2:s.pop();break;
                case 3:s.display();
                break;
                case 5:s.peek();break;
                case 4:s.size();break;
                case 8:System.exit(0);
                default:System.out.println("Invalid Choice, Enter your choice again");
            }
        }while(ch>0);
    }
}