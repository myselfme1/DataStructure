import java.util.*;
class Q
{
    int front,rear,arr[],max;
    Q()
    {
        front=-1;
        rear=-1;
        max=5;
        arr=new int[max];
    }
    void insert(int ele)
    {
        if(isfull())
        {
            System.out.println("Queue Overflow");
            return;
        }
        if(front==-1)
        {
            front=0;
        }
        rear++;
        arr[rear]=ele;
    }
    void delete()
    {
        if(isempty())
        {
            System.out.println("Queue unserflow,no Element to Delete");
            return;
        }
        System.out.println("Delete Element = "+arr[front]);
        arr[front]=0;
        if(rear==front)
        {
            front=-1;
            rear=-1;
            return;
        }
        front++;
    }
    void peek()
    {
        if(isempty())
        {
            System.out.println("Queue unserflow");
            return;
        }
        System.out.println("Top Element = "+arr[front]);
    }
    boolean isempty()
    {
        if(front==-1)
        return true;
        else 
        return false;
    }
    boolean isfull()
    {
        if(rear==max-1)
        return true;
        else
        return false;
    }
    int size()
    {
        if (isempty())
        return 0;
        else
        return rear-front+1;
    }
    void display()
    {
         if(isempty())
        {
            System.out.println("Queue unserflow,no Element to Delete");
            return;
        }
        System.out.println("ELements are");
        for(int i=front;i<=rear;i++)
        System.out.print(arr[i]+" ");
    }
}
class demo
{
    public static void main(String ar[])
    {
        Scanner sc=new Scanner(System.in);
        Q s=new Q();
         while(true)
        {
            System.out.println("Enter choice 1.insert 2.delete 3.display 4.size 5.peek 8.exit");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1:System.out.print("ENter Element to push:");
                s.insert(sc.nextInt());break;
                case 2:s.delete();break;
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