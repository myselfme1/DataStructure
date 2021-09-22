#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int size)
{
    int j,temp;
    for(int i=1;i<size;i++)
    {
        temp=arr[i];
        for( j=i-1;j>=0,arr[j]>temp;j--)
           arr[j+1]=arr[j];
        arr[j+1]=temp;
    }
}
int main()
{
    int size;
    cout<<"Enter Array Size: ";
    cin>>size;
    int arr[size];
    cout<<"Enter Array Elements\n";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Elements in array are\n";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    insertionsort(arr,size);
    cout<<"Elements after insertion sorting in array are\n";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}