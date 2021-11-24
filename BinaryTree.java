import java.util.*;
class node
{
    node left;
    int data;
    node right;
}
class BinaryTree
{
    static Scanner sc=new Scanner(System.in);
    static node create()
    {
        System.out.print("Enter Data(Press -1  for no Data): ");
        int no=sc.nextInt();
        if(no==-1)
            return null;
        else
        {
            node curr=new node();
            curr.data=no;
            System.out.println("Enter Left child of "+no);
            curr.left=create();
            System.out.println("Enter right child  of"+no);
            curr.right=create();
            return curr;
        }
    }
    static void preorder(node root)
    {
        if(root!=null)
        {
            System.out.println(root.data);
            preorder(root.left);
            preorder(root.right);
        }
    }
    static void inorder(node root)
    {
        if(root!=null)
        {
            inorder(root.left);
            System.out.println(root.data);
            inorder(root.right);
        }
    }
    static void postorder(node root)
    {
        if(root!=null)
        {
            postorder(root.left);
            postorder(root.right);
            System.out.println(root.data);
        }
    }
}
class driver
{
    public static void main(String arg[])
    {
        node root=BinaryTree.create();
        System.out.println("Inorder traversal =");
        BinaryTree.inorder(root);
         System.out.println("Preorder traversal =");
        BinaryTree.preorder(root);
         System.out.println("Postorder traversal =");
        BinaryTree.postorder(root);
    }
}