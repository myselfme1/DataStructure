//Error in program
class Test
{
    void Merge(int arr[],int start,int mid,int end)
    {
        int A[]=new int[mid-start+1];
        int B[]=new int[end-mid];
        for(int i=0;i<A.length;i++)
            A[i]=arr[start+i];
        for(int i=0;i<B.length;i++)
            B[i]=arr[mid+1+i];
            int i=0,j=0,k=1;
			while(i<A.length&&j<B.length)
		{
			if(A[i]<=B[j])
			{
                arr[k]=A[i];
				i++;
			}
			else
			{
				arr[k]=B[j];
				j++;
			}
			k++;
		}
		for(;i<A.length;i++)
		{
            arr[k]=A[i];
            k++;
        }
		for(;j<B.length;j++)
		{
            arr[k]=B[j];
            k++;
        }
    }
    void sort(int arr[],int start,int end)
    {
        if(start<end)
        {
            int mid=start+end/2;
            sort(arr,start,mid);
            sort(arr,mid+1,end);
            Merge(arr,start,mid,end);
        }
    }
     void show(int arr[])
    {
        for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]+" ");
        System.out.print("\n");
    }
    public static void main(String arg[])
    {
        int arr[]={12,11,13,5,6,7};
         System.out.println("Array is");
        Test t=new Test();
        t.show(arr);
        t.sort(arr,0,arr.length-1);
        System.out.println("After Sorting");
        t.show(arr);
    }
}
