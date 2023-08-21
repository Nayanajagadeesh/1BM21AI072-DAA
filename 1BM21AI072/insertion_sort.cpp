#include <bits/stdc++.h>
using namespace std;
void display(int *arr,int size);
void insertionsort(int arr[],int size);
 int main()
 {
    int n;
    cout<<"enter the number of elements";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"array before sorting :";
    display(arr,n);
    insertionsort(arr,n);
    cout<<"array after sorting :";
    display(arr,n);
 }
 void insertionsort(int arr[],int size)
 {
     int key,j;
     for(int i=1;i<size;i++)
     {
        key=arr[i];
        j=i;
        while(j>0 && arr[j-1]>key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
     }
 }
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
