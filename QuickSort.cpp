#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high],i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void QuickSort(int arr[],int low,int high)
{
    if(low<high)
    {
    int PartitionIndex=partition(arr,low,high);
    QuickSort(arr,low,PartitionIndex-1);
    QuickSort(arr,PartitionIndex+1,high);
    }
}
int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    cin>>arr[i];
    QuickSort(arr,0,N-1);
    cout<<"After Quick Sorting\n";
    for(int i=0;i<N;i++)
    cout<<arr[i]<<" "<<endl;
}