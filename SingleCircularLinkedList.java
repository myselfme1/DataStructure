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
class SingleCircularLinkedList
{
	public node head;
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
		if(head==null)
		{
			head=curr;
		}
		else
		{
			temp.next=curr;
			curr.next=head;
		}
		temp=curr;
		System.out.print("To Continue press y: ");
		ch=sc.next().charAt(0);
	}while(ch=='y');
	}
	void display()
	{
        if(head==null)
        System.out.println("No Element to Display");
		node temp=head;
		do
		{
			temp.dispdata();
			temp=temp.next;
		}while(temp!=head);
	}
	void insertatbegin(int ele)
	{
		node curr=new node();
		curr.data=ele;
		if(head==null)
		{
			curr.next=curr;
			head=curr;
			return;
		}
		curr.next=head;
		node temp=head;
		while(temp.next!=head)
		temp=temp.next;
		temp.next=curr;
		head=curr;
	}
	void insertatlast(int ele)
	{
		node curr=new node();
		curr.data=ele;
		if(head==null)
		{
			curr.next=curr;
			head=curr;
			return;
		}
        node temp=head;
		curr.next=head;
		while(temp.next!=head)
		temp=temp.next;
		temp.next=curr;
		
	}
	void Deletefrombegin()
	{
		if(head==null)
		{
			System.out.println("No Element in List to Delete");
			return;
		}
		System.out.println("Deleted Element = "+head.data);
		if(head==head.next)
		{
			head=null;
			return;
		}
		node temp=head;
		while(temp.next!=head)
		temp=temp.next;
		head=head.next;
		temp.next=head;

	}
	void DeletefromEnd()
	{
		if(head==null)
		{
			System.out.println("No Element in List to Delete");
			return;
		}
		if(head==head.next)
		{
			System.out.println("Deleted Element = "+head.data);
			head=null;
			return;
		}
		node prev=null;
        node temp=head;
		while(temp.next!=head)
		{
			prev=temp;
			temp=temp.next;
		}
		prev.next=head;
		System.out.println("Deleted Element = "+temp.data);
		temp=null;
	}
}
class Test
{
	public static void main(String[] arg)
	{
		SingleCircularLinkedList ob=new SingleCircularLinkedList();
		ob.create();
		int ele,ch;
		Scanner sc=new Scanner(System.in);
		do
		{
			System.out.print("\nEnter 1.insertBegin 2.InsertEnd 3.DeleteBegin 4.DeleteEnd 5.display 6.exit: ");
			ch=sc.nextInt();
            switch(ch)
			{
                case 1:System.out.print("Enter Element to Insert: ");
			ele=sc.nextInt();
			ob.insertatbegin(ele);break;
			case 2:System.out.print("Enter Element to Insert: ");
			ele=sc.nextInt();
			ob.insertatlast(ele);break;
			case 3:ob.Deletefrombegin();break;
			case 4:ob.DeletefromEnd();break;
			case 5:ob.display();break;
			case 6:System.exit(0);break;
			default:System.out.println("Invalid Choice,Enter your choice again");
            }
		}while(ch>0);
	}
}