#include<iostream>
using namespace std;
int main()
{
    int arr[10], i, num, index,n;
    cout<<"Enter n Numbers: ";
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nEnter a Number to Search: ";
    cin>>num;
    for(i=0; i<n; i++)
    {
        if(arr[i]==num)
        {
            index = i;
            break;
        }
    }
    cout<<"\nFound at Index No."<<index;
    cout<<endl;
    return 0;
}
