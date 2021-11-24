import java.util.*;
class node
{
    node left;
       
    int data;
    node right;
    node(int data)
    {
        this.data=data;
    }
}
class bst
{
    static node root;
            void insert(int ele)
        {
            node parent=null,curr=null,temp=null;
             temp=new node(ele);
            temp.left=null;
            temp.right=null;
            if(root==null)
                root=temp;
            else 
            {
                curr=root;
                while(curr!=null)
                {
                    parent=curr;
                    if(ele<curr.data)
                        curr=curr.left;
                    else
                        curr=curr.right;
                }
                if(ele>parent.data)
                parent.right=temp;
                else
                parent.left=temp;
            }
        }
        void delete(int ele)
        {
            int found=0;
            node curr=root,parent=null;
            while(curr!=null)
            {
                if(curr.data==ele)
                {
                    found++;
                    break;
                }
                else
                {
                    parent=curr;
                    if(ele>curr.data)
                     curr=curr.right;
                    else if(ele<=curr.data)
                    curr=curr.left;
                }
            }
            if(found==0)
            {
                System.out.println("No Element to Delete");
                return;
            }
            if(curr.left==null&&curr.right==null)
            {
                if(curr==parent.right)
                    parent.right=null;
                else if(curr==parent.left)
                    parent.left=null;
            }
            else if((curr.left!=null&&curr.right==null)||(curr.left==null&&curr.right!=null))
            {
                if(curr.left!=null&&curr.right==null)
                {
                    if(curr==parent.right)
                    {
                        parent.right=curr.left;
                    }
                    else if(curr==parent.left)
                    {
                        parent.left=curr.left;
                    }
                    curr.left=null;
                }
                else if(curr.left==null&&curr.right!=null)
                {
                    if(curr==parent.right)
                    {
                        parent.right=curr.right;
                    }
                    else if(curr==parent.left)
                    {
                        parent.left=curr.right;
                    }
                    curr.right=null;
                }
            }
            else if(curr.left!=null&&curr.right!=null)
            {
                node temp1,temp2;
                temp1=curr.right;
                if(temp1.right==null&&temp1.left==null)
                {
                    curr.data=temp1.data;
                    curr.right=null;
                }
                else if(temp1.right!=null&&temp1.left==null)
                {
                    curr.data=temp1.data;
                    curr.right=temp1.right;
                    temp1.right=null;
                }
                else if(temp1.left!=null)
                {
                    temp2=temp1.left;
                    while(temp2.left!=null)
                    {
                        temp2=temp2.left;
                        temp1=temp1.left;
                    }
                    curr.data=temp2.data;
                    temp1.left=temp2.right;
                    temp2.right=null;
                }
            }
        }
        void inorder(node temp)
        {
        if(temp.left!=null)
            inorder(temp.left);
        System.out.println(temp.data);
        if(temp.right!=null)
            inorder(temp.right);
        }
        void printInorder()
        {
            if(root==null)
                System.out.println("Tree is Empty");
            else
                inorder(root);
        }
        void preorder(node temp)
        {
            System.out.println(temp.data);
        if(temp.left!=null)
            preorder(temp.left);
        if(temp.right!=null)
            preorder(temp.right);
        }
        void printPreorder()
        {
            if(root==null)
                System.out.println("Tree is Empty");
            else
                preorder(root);
        }
        void postorder(node temp)
        {
            
        if(temp.left!=null)
            postorder(temp.left);
        if(temp.right!=null)
            postorder(temp.right);
            System.out.println(temp.data);
        }
        void printPostorder()
        {
            if(root==null)
                System.out.println("Tree is Empty");
            else
                postorder(root);
        }

}
class demo
{
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
         int ch,ele;
         bst ob=new bst();
    do
    {
        System.out.println("Enter your choice: 1.Insert 2.delete 3.Traverse in Inorder 4.PreOrder 5.Postorder 6.exit: ");
        ch=sc.nextInt();
        switch(ch)
        {
            case 1:System.out.println("Enter Element to Insert: ");
            ele=sc.nextInt();
            ob.insert(ele); break;
            case 2:System.out.println("Enter Element to delete: ");
            ele=sc.nextInt();
            ob.delete(ele); break;
            case 3:ob.printInorder();break;
            case 4:ob.printPreorder();break;
            case 5:ob.printPostorder();break;
            case 6:System.exit(0);
            default:System.out.println("Invalid Choice,enter choice again");
      }

    }while(ch>0);
    }
}