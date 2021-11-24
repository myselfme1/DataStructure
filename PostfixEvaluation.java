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
    int pop()
    {
        if(top==null)
        {
            System.out.println("Stack Underflow,no Element to delete");
           // return;
        }
        //System.out.println("Delete Element = "+top.data);
        node ptr=top;
        top=top.next;
        return ptr.data;
    }
    int peek()
    {
        if(top==null)
        {
            System.out.println("Stack Underflow,no Element");
            //return;
        }
        //System.out.println("top Element = "+top.data);
        return top.data;
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
}
class demo
{
    public static void main(String ar[])
    {
        Scanner sc=new Scanner(System.in);
        Stack s=new Stack();
        System.out.print("Enter Expression: ");
        String exp=sc.next();
        int no1,no2,no;
        for(int i=0;i<exp.length();i++)
        {
           //System.out.println(exp.charAt(i));
            if(exp.charAt(i)>='1'&&exp.charAt(i)<='9')
            {
               // no=Integer.parseInt(exp.charAt(i));
                s.push(exp.charAt(i)-'0');
            }
           
           else if(exp.charAt(i)=='+'||exp.charAt(i)=='-'||exp.charAt(i)=='*'||exp.charAt(i)=='/')
            {
                no2=s.pop();
                no1=s.pop();
                if(exp.charAt(i)=='+')
                s.push(no1+no2);
                else if(exp.charAt(i)=='-')
                s.push(no1-no2);
                else if(exp.charAt(i)=='*')
                s.push(no1*no2);
                else if(exp.charAt(i)=='/')
                s.push(no1/no2);
            }
            s.display();
        }
        System.out.println("\n Postfix Expression Value = "+s.peek());
    }
}