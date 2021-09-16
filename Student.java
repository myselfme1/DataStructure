import java.util.*;
class node
{
    String name;
    int rollno;
    float mark;
    node next;
    void dispdata()
    {
        System.out.print(name+" "+rollno+" "+mark);
    }
}
class Student
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
            System.out.print("Enter Student "+c+" Name: ");
            curr.name=sc.next();
             System.out.print("Enter Student "+c+" Rollno: ");
             curr.rollno=sc.nextInt();
              System.out.print("Enter Student "+c+" Mark: ");
              curr.mark=sc.nextFloat();
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
    }
}
class demo
{
    public static void main(String[] arg)
    {
        Student ob=new Student();
        ob.create();
        System.out.println("Student Details are");
        ob.display();
    }
}