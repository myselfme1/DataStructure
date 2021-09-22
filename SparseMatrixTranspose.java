import java.util.*;
class test
{
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        int row,col,i,j,k=0,nonzero=0;
        System.out.println("Enter Number of Rows and Columns");
        row=sc.nextInt();
        col=sc.nextInt();
        int sp[][]=new int[row][col],tp[][]=new int[row*col+1][3];
        System.out.println("ENter "+row*col+" Elements");
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        sp[i][j]=sc.nextInt();
        System.out.println("Elements in Matrix are");
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            System.out.print(sp[i][j]+" ");
            System.out.println();
        }
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        if(sp[i][j]!=0)
        nonzero++;
        if(nonzero>row*col/2)
        {
            System.out.println("The above Matrix is not Sparse Matrix");
            System.exit(0);
        }
        tp[0][0]=row;
        tp[0][1]=col;
        tp[0][2]=nonzero;
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            if(sp[i][j]!=0)
            {
                k++;
                tp[k][0]=i;
                tp[k][1]=j;
                tp[k][2]=sp[i][j];
            }
        }
        System.out.println("Sparse Matrix is represented as");
       for(i=0;i<=nonzero;i++)
        {
         for(j=0;j<3;j++)
        System.out.print(tp[i][j]+" ");
        System.out.println();
        }
        int temp;
        for(i=1;i<=nonzero;i++)
        {
            temp=tp[i][0];
            tp[i][0]=tp[i][1];
            tp[i][1]=temp;
        }
        System.out.println("Transponse of Sparse Matrix :");
         for(i=0;i<=nonzero;i++)
        {
         for(j=0;j<3;j++)
        System.out.print(tp[i][j]+" ");
        System.out.println();
        }
    }
}
