import java.util.Scanner;
class node
{
    int data;
    node next;
    node(int data)
    {
        this.data=data;
    }
}
class CQL
{
    private node front,rear;
    void insert(int ele)
    {
        if(front==null)
        {
            rear=new node(ele);
            front=rear;
            rear.next=front;
            return;
        }
        node curr=new node(ele);
        curr.next=front;
        rear.next=curr;
        rear=curr;
    }
    void display()
    {
        if(front==null)
        {
            System.out.println("Queue Underflow");
            return;
        }
        System.out.println("Elements are: ");
        node temp=front;
        do
        {
            System.out.println(temp.data);
            temp=temp.next;
        }while(temp!=front);
    }
    int size()
    {
        int c=0;
        if(front==null)
        {
            System.out.println("Queue Underflow");
            return c;
        }
        //System.out.println("Elements are: ")
        node temp=front;
        do
        {
            c++;
            //System.out.println(temp.data);
            temp=temp.next;
        }while(temp!=front);
        return c;
    }
    void peek()
    {
        if(front==null)
        {
            System.out.println("Queue Underflow");
            return ;
        }
        System.out.println("Top Data = "+front.data);
    }
    void Delete()
    {
        
        if(front==null)
        {
            System.out.println("Queue Underflow");
            return ;
        }
        System.out.println("Delete Element = "+front.data);
        if(front==rear)
        {
            front=null;
            rear=null;
            return;
        }
        front=front.next;
        rear.next=front;
    }
    void inputfromBegin(int ele)
    {
        if(front==null)
        {
            rear=new node(ele);
            front=rear;
            rear.next=front;
            return;
        }
        node curr=new node(ele);
        rear.next=curr;
        curr.next=front;
        front=curr;
    }
    void DeletefromEnd()
    {
         if(front==null)
        {
            System.out.println("Queue Underflow");
            return ;
        }
        System.out.println("Delete Element = "+rear.data);
        if(front==rear)
        {
            front=null;
            rear=null;
            return;
        }
        node temp=front,tem=null;
        while(temp.next!=front)
        {
            tem=temp;
            temp=temp.next;
        }
        tem.next=front;
        rear=tem;
    }

}
class Test
{
    public static void main(String ar[])
    {
        Scanner sc=new Scanner(System.in);
        CQL s=new CQL();
         while(true)
        {
            System.out.println("Enter choice 1.insert 2.delete 3.display 4.size 5.peek 8.exit");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1:System.out.print("ENter Element to insert:");
                s.insert(sc.nextInt());break;
                case 2:s.Delete();break;
                case 3:s.display();
                break;
                case 5:s.peek();break;
                case 4:System.out.println("No of Elements = "+s.size());break;
                case 8:System.exit(0);
                default:System.out.println("Invalid Choice, Enter your choice again");
            }
        }
    }
}