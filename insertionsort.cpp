#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int size)
{
    int j,key,i;
    for(j=1;j<size;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>-1&&arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
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
