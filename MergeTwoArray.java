import java.util.*;
class Test
{
	static void merge(int A[],int B[])
	{
		int i=0,j=0,k=0,C[]=new int[A.length+B.length];
			while(i<A.length-1&&j<B.length-1)
		{
			if(A[i]>B[j])
			{
				C[k]=B[j];
				j++;
			}
			else
			{
				C[k]=A[i];
				i++;
			}
			k++;
		}
		for(;i<A.length-1;i++)
		C[k++]=A[i];
		for(;j<B.length-1;j++)
		C[k++]=B[j];

		for( k=0;k<C.length-1;k++)
		System.out.print(C[k]+" ");
		/*for(int k=0;k<4;k++)
		{
			System.out.print(A[k]+" ");
		}
		for(int k=0;k<4;k++)
		{
			System.out.print(B[k]+" ");
		}*/
	}
	public static void main(String[] arg) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		//System.out.println("Enter A");
		int A[]={2,8,15,18};
		int B[]={5,9,12,17};
		merge(A,B);
	}
}
