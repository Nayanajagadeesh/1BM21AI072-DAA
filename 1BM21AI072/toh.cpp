#include <iostream>
using namespace std;
void TOH(int n,char s,char a,char d);
int main()
{
    int n;
    cout<<"Enter the number of discs";
    cin>>n;
    TOH(n,'A','B','C');
}
void TOH(int n,char s,char a,char d)
{
    if(n==1)
    {
        cout<<"move disc "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    TOH(n-1,s,d,a);
    cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<endl;
    TOH(n-1,a,s,d);
}
