//Only Condition not written nonzero in sp should be equal to nonzero2 in sp2
import java.util.*;
class test
{
    //static void disp(int sp[50][50],int row,int col)
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        int row,col,i,j,k=0,nonzero=0,nonzero2=0;
        System.out.println("Enter Number of Rows and Columns");
        row=sc.nextInt();
        col=sc.nextInt();
        int sp[][]=new int[row][col],tp[][]=new int[row*col+1][3];
        int sp2[][]=new int[row][col],tp2[][]=new int[row*col+1][3];
        System.out.println("ENter "+row*col+" Elements for sp");
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        sp[i][j]=sc.nextInt();
        System.out.println("ENter "+row*col+" Elements for sp2");
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        sp2[i][j]=sc.nextInt();
        System.out.println("Elements in sp Matrix are");
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            System.out.print(sp[i][j]+" ");
            System.out.println();
        }
        System.out.println("Elements in sp2 Matrix are");
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            System.out.print(sp2[i][j]+" ");
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
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        if(sp2[i][j]!=0)
        nonzero2++;
        if(nonzero2>row*col/2)
        {
            System.out.println("The above Matrix is not Sparse Matrix");
            System.exit(0);
        }
        tp[0][0]=row;
        tp[0][1]=col;
        tp[0][2]=nonzero;
        tp2[0][0]=row;
        tp2[0][1]=col;
        tp2[0][2]=nonzero2;
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
        k=0;
        for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            if(sp2[i][j]!=0)
            {
                k++;
                tp2[k][0]=i;
                tp2[k][1]=j;
                tp2[k][2]=sp2[i][j];
            }
        }
        System.out.println("Sparse Matrix sp is represented as");
       for(i=0;i<=nonzero;i++)
        {
         for(j=0;j<3;j++)
        System.out.print(tp[i][j]+" ");
        System.out.println();
        }
         System.out.println("Sparse Matrix sp2 is represented as");
       for(i=0;i<=nonzero2;i++)
        {
         for(j=0;j<3;j++)
        System.out.print(tp2[i][j]+" ");
        System.out.println();
        }
        int temp;
        for(i=1;i<=nonzero;i++)
        {
            temp=tp[i][0];
            tp[i][0]=tp[i][1];
            tp[i][1]=temp;
        }
        System.out.println("Transponse of Sparse Matrix sp :");
         for(i=0;i<=nonzero;i++)
        {
         for(j=0;j<3;j++)
        System.out.print(tp[i][j]+" ");
        System.out.println();
        }
        int temp1,temp2;
        System.out.println("After Sorting of Sparse Matrix sp");
        for(i=1;i<=nonzero-1;i++)
        {
                for(j=i+1;j<=nonzero;j++)
                {
                    if(tp[i][0]>tp[j][0]||(tp[i][0]==tp[j][0]&&tp[i][1]>tp[j][1]))
                    {
                        temp=tp[i][0];
                        tp[i][0]=tp[j][0];
                        tp[j][0]=temp;
                        temp1=tp[i][1];
                        tp[i][1]=tp[j][1];
                        tp[j][1]=temp1;
                        temp2=tp[i][2];
                        tp[i][2]=tp[j][2];
                        tp[j][2]=temp2;
                    }
                }
        }
        for(i=0;i<=nonzero;i++)
        {
         for(j=0;j<3;j++)
        System.out.print(tp[i][j]+" ");
        System.out.println();
        }
        int product[][]=new int[30][4];
        k=0;
        for(i=1;i<=nonzero2;i++)
        {
            for(j=1;j<=nonzero;j++)
            {
                if(tp2[i][1]==tp[j][1])
                {
                    product[k][0]=tp2[i][0];
                    product[k][1]=tp[j][0];
                    product[k][2]=tp[j][2]*tp2[i][2];
                    k++;
                }
            }
        }
        System.out.println("Sparse Matrix Multiplication is\n");
        for(i=0;i<k;i++)
        {
            for(j=0;j<3;j++)
            {
                System.out.print(product[i][j]+" ");
            }
            System.out.println();
        }
    }
}