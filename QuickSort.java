import java.util.*;
class Test
{
	void swap(int a,int b)
	{
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
	int partition(int arr[],int start,int end)
	{
		int j=start,i=j-1,pivot=arr[end],temp;
		while(j<end)
		{
			if(arr[j]<pivot)
			{
				i++;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				//swap(t1,t2);
			}
			j++;
		}
		temp=arr[i+1];
		arr[i+1]=arr[end];
		arr[end]=temp;
		//swap(t1,t2);
		return i+1;
	}
 	void show(int arr[])
	{
		for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]+" ");
        System.out.println();
	}
	void quicksort(int arr[],int start,int end)
	{
		int position;
		if(start<end)
		{
			position=partition(arr,start,end);
			quicksort(arr,start,position-1);
			quicksort(arr,position+1,end);
		}
	}
	public static void main(String arg[])
	{
		Scanner sc=new Scanner(System.in);
        System.out.print("Enter Array Size: ");
        int size =sc.nextInt();
        int arr[]=new int[size];
        System.out.println("Enter "+size+" Elements");
        for(int i=0;i<size;i++)
        arr[i]=sc.nextInt();
        System.out.println("Elements are");
		Test t=new Test();
        t.show(arr);
        t.quicksort(arr,0,size-1);
        System.out.println("Elements after sorting are");
        t.show(arr);
	}
}