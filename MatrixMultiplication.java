import java.util.Scanner;
class demo
{
    public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Order of both Matrix: ");
        int order=sc.nextInt();
        int A[][]=new int[order][order];
        int B[][]=new int[order][order];
        System.out.println("Enter Array A Elements");
        for(int i=0;i<A.length;i++)
            for(int j=0;j<A.length;j++)
                A[i][j]=sc.nextInt();
        System.out.println("Enter Array B Elements");
        for(int i=0;i<B.length;i++)
            for(int j=0;j<B.length;j++)
                B[i][j]=sc.nextInt();
        int C[][]=new int[order][order];
        for(int i=0;i<A.length;i++)
            for(int j=0;j<B.length;j++)
            {
                C[i][j]=0;
                for(int k=0;k<A.length;k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        System.out.print("Their Multiplication =\n");
        for(int i=0;i<A.length;i++)
            {
                for(int j=0;j<A.length;j++)
            {
                System.out.print(C[i][j]+" ");
            }
            System.out.println();
            }
    }
}