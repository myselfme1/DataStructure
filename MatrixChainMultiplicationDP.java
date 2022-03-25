import java.util.Scanner;
class demo
{
     int dp[][]=new int[50][50];
    int MatrixChain(int arr[],int i,int j)
    {
        if(i==j)
            return 0;
         dp[i][j]=98656;
            for(int k=i;k<j;k++)
            {
                int c[][]=new int[50][50];
                c[i][j]=MatrixChain(arr,i,k)+MatrixChain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
                if(c[i][j]<dp[i][j])
                dp[i][j]=c[i][j];
            }
            return dp[i][j];
    }
    public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        int size=sc.nextInt();
        int arr[]=new int[size];
        for(int i=0;i<arr.length;i++)
        arr[i]=sc.nextInt();
        demo ob=new demo();
        System.out.println("Minimum Multiplications needed = "+ob.MatrixChain(arr,1,arr.length-1));
    }
}