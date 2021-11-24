#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Bsearch(int arr[],int size,int ser)
{
    int l=0,h=size-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(ser==arr[mid])
            return mid+1;
        else if(ser<arr[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int main()
{
    int ser,size;
    cout<<"Enter Array Size: ";
    cin>>size;
    int i,arr[size];
    cout<<"Enter "<<size<<" Elements\n";
    for(i=0;i<size;i++)
        cin>>arr[i];
    cout<<"Enter Element to search: ";
    cin>>ser;
    if(Bsearch(arr,size,ser)==-1)
        cout<<ser<<" not found";
    else
        cout<<ser<<" found at "<<Bsearch(arr,size,ser)<<" position";
}
