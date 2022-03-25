//
import java.util.Scanner;
class LongestCommonSubsequenceDynamicPro
{
    int LCS(String s1,String s2)
    {
        int arr[][]=new int[s1.length()+1][s2.length()+1];
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[i].length;j++)
            {
                if(i==0||j==0)
                    arr[i][j]=0;
                else if(s1.charAt(i-1)==s2.charAt(j-1))
                    arr[i][j]=1+arr[i-1][j-1];
                else
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[s1.length()][s2.length()];
    }   
    int max(int h,int k)
    {
        if(h>k)
        return h;
        else
        return k;
    }
    public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        String s1,s2;
        System.out.println("Enter Ist String");
        s1=sc.nextLine();
        System.out.println("Enter 2nd String");
        s2=sc.nextLine();
        LongestCommonSubsequenceDynamicPro ob=new LongestCommonSubsequenceDynamicPro();
        System.out.println("LCS length = "+ob.LCS(s1,s2));
        //System.out.println(s1+s2);
    }
}