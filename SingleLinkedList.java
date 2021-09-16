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
    void InsertatBegin(int ele)
    {
        node curr=new node();
        curr.data=ele;
        curr.next=head;
        head=curr;
    }
    void InsertatEnd(int ele)
    {
        node curr=new node();
        curr.data=ele;
        curr.next=null;
        node temp=head;
        while(temp.next!=null)
        {
            temp=temp.next;
        }
        temp.next=curr;
    }
    void DeletefromBegin()
    {
        if(head==null)
        {
            System.out.println("No Element present");
            return;
        }
        System.out.println("Deleted Element ="+head.data);
        head=head.next;
    }
    void DeletefromEnd()
    {
        if(head==null)
        {
            System.out.println("No Element present");
            return;
        }
        node prev=null,temp=head;
        while(temp.next!=null)
        {
            prev=temp;
            temp=temp.next;
        }
        System.out.println("Deleted Element ="+temp.data);
        if(prev==null)
        head=null;
        else
        prev.next=null;
        temp=null;
    }
    void InsertatanyPosition(int ele)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Position: ");
        int pos=sc.nextInt();
        if(pos<1||pos>count()+1)
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(pos==1)
        {
            InsertatBegin(ele);
            return;
        }
        else if(pos==count()+1)
        {
            InsertatEnd(ele);
            return;
        }
        node curr=new node();
        curr.data=ele;
        node temp=head;
        int c=1;
        while(c<pos-1)
        {
            ++c;
            temp=temp.next;
        }
        curr.next=temp.next;
        temp.next=curr;
    }
    int count()
    {
        node temp=head;
        int c=0;
        while(temp!=null)
        {
            ++c;
            temp=temp.next;
        }
        return c;
    }
    void InsertafterElement(int ele)
    {
        node temp=head;
        if(temp==null)
        {
            System.out.println("No ELement in List");
            return;
        }
        while(temp!=null)
        {
            if(temp.data==ele)
            break;
            temp=temp.next;
        }
        if(temp==null)
        {
            System.out.println("No ELement in List");
            return;
        }
        node curr=new node();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter new node Data: ");
        curr.data=sc.nextInt();
        curr.next=temp.next;
        temp.next=curr;
    }
    void search(int ele)
    {
         node temp=head;
        if(temp==null)
        {
            System.out.println("No ELement in List");
            return;
        }
        int c=0;
        while(temp!=null)
        {
            if(temp.data==ele)
            break;
            c++;
            temp=temp.next;
        }
        if(temp==null)
        System.out.println("Element not present in List");
        else
        System.out.println(ele+" found at "+c+" position");
    }
    void reverse()
    {
        node h=head;
        node temp=null,curr=head.next,prev=head;
        h.next=null;
        while(curr.next!=null)
        {
            temp=curr.next;
            curr.next=prev;
            prev=curr;
            curr=temp;
        }
        curr.next=prev;
        head=curr;
    }
}
class demo
{
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        SingleLinkedList ob=new SingleLinkedList();
        ob.create();
        
        
        
        int ch;
        do
        {
System.out.println("Enter your choice: 1.InsertatBegin 2.InsertatEnd 3.DeletefromBegin 4.DeletefromEnd 5.Display 6.CountElements 7.InsertatanyPosition 8.Search anElement 9.InsertafteranElement 10.ReverseLinkedList 11.exit");
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
            case 6:System.out.println("Total nodes are = "+ob.count());break;
            case 5:System.out.println("Elements are");ob.display();break;
            case 7:System.out.print("Enter Element to Insert: ");
            ele=sc.nextInt();
            ob.InsertatanyPosition(ele);break;
            case 8:System.out.print("Enter Element to Search: ");
            ele=sc.nextInt();
            ob.search(ele);break;
            case 9:System.out.print("Enter Element in list after which you want to Insert: ");
            ele=sc.nextInt();
            ob.InsertafterElement(ele);break;
            case 10:ob.reverse();break;
            case 11:System.exit(0);
            default:System.out.println("Invalid choice and your choice ends here");
            }
        }while(ch<=10);
    }
}