#include<iostream>
 using namespace std;
 int main()
 {
 int n,a[10],i,j,c,small,index,temp;
 cout<<"enter the size of the array";
 cin>>n;
 cout<<"enter the elements of the array";
 for(i=0;i<n;i++)
 cin>>a[i];
 for(i=0;i<n-1;i++)
 {
     c=0;
     small=a[i];
     for(j=i+1;j<n;j++)
     {
         if(small>a[j])
         {
             small=a[j];
             c++;
             index=j;
         }
     }
     if(c!=0)
     {
         temp=a[i];
         a[i]=small;
         a[index]=temp;
     }
 }
 cout<<"\n sorted array is:\n";
 for(i=0;i<n;i++)
    cout<<a[i]<<" ";
 return 0;
 }
