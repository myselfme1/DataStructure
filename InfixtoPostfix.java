import java.util.*;
class node
{
    char data;
    node next;
    node(char data)
    {
        this.data=data;
    }
}
class Stack
{
    private node top;
    void push(char ele)
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
    char pop()
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
    char peek()
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
        System.out.print("Enter Infix Expression: ");
        String post="",infix=sc.next();
        infix="("+infix+")";
        int no1,no2,no;
        for(int i=0;i<infix.length();i++)
        {
           
           char item,ch=infix.charAt(i);
           if(infix.charAt(i)>='a'&&infix.charAt(i)<='z')
           post+=infix.charAt(i);
           else if(infix.charAt(i)=='(')
           s.push('(');
           else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
            {
                item=s.pop();
                while((item=='+'||item=='-'||item=='*'||item=='/'||item=='^')&&precdenece(item)>=precdenece(ch))
                {
                     post+=item;
                     item=s.pop();
                }
                //else
                    s.push(item);
                s.push(ch);
            } 
            else if(ch==')')
            {
                item=s.pop();
                while(item!='(')
                {
                    post+=item;
                    item=s.pop();
                }
            }           
          // s.display();
        }
        System.out.println("\n Postfix Expression = "+post);
    }
     static int precdenece(char ch)
		{
                  if(ch=='^')
					  return 3;
				  else if(ch=='*'||ch=='/')
					  return 2;
				  else if(ch=='+'||ch=='-')
					  return 1;
				  else
					  return 0;
		}
}