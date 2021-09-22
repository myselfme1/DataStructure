#include<bits/stdc++.h>
using namespace std;
void display(int arr[],int size)
{
    
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
void bubblesort(int arr[],int size)
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    display(arr,size);
    bubblesort(arr,size);
    cout<<"Elements after bubble sorting in array are\n";
    display(arr,size);
}