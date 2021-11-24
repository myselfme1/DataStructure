import java.util.Scanner;
class Test
{
    static void merge(int arr[],int start,int mid,int end)
    {
        int i=start,j=mid+1,k=start;
        int arr2[]=new int[end+1];
        while(i<=mid&&j<=end)
        {
            if(arr[i]<arr[j])
            {
                arr2[k]=arr[i];
                i++;
            }
            else 
            {
                arr2[k]=arr[j];
                j++;
            }
            k++;
        }
        if(i>mid)
        {
            while(j<=end)
            {
                arr2[k]=arr[j];
                j++;
                k++;
            }
        }
        else
        {
            while(i<=mid)
            {
                arr2[k]=arr[i];
                i++;
                k++;
            }
        }
        for(i=start;i<k;i++)
        arr[i]=arr2[i];
    }
    static void mergesort(int arr[],int start,int end)
    {
        int mid;
        if(start<end)
        {
            mid=(start+end)/2;
            mergesort(arr,start,mid);
            mergesort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }
    static void show(int arr[])
    {
        for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]+" ");
        System.out.println();
    }
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Array Size: ");
        int size =sc.nextInt();
        int arr[]=new int[size];
        System.out.println("Enter "+size+" Elements");
        for(int i=0;i<size;i++)
        arr[i]=sc.nextInt();
        System.out.println("Elements are");
        show(arr);
        mergesort(arr,0,size-1);
        System.out.println("Elements after sorting are");
        show(arr);
    }
}