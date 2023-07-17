#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[100],n,st,mid,tgt,last,i;
    cout<<"enter the no of elements: ";
    cin>>n;
    cout<<"enter the elements of array : ";
    for(i=0;i<n;i++)
    {
        cout<<"array ["<<i<<"]=";
        cin>>a[i];
    }
    st=0;
    last=n-1;
    cout<<"enter the elements to be search :";
    cin>>tgt;
    while(st<=last)
    {
        mid=(st+last)/2;
        if(a[mid]==tgt)
        {
            cout<<"element is found at position"<<(mid+1);
            exit(0);
        }
        else if(tgt>a[mid])
        {
            st=mid+1;
        }
        else if(tgt<a[mid])
        {
            last=mid-1;
        }
    }
    cout<<"number is not found"<<endl;
    return 0;
}
