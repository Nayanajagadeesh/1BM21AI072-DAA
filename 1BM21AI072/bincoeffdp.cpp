#include<iostream>
using namespace std;
int binomialcoeff(int n,int k);
int main()
{

    int n,k;
    cout<<"enter the value of n";
    cin>>n;
    cout<<"enter the value of k";
    cin>>k;
    cout<<"the binomial coeff of C["<<n<<"]["<<k<<"] is "<< binomialcoeff(n,k);
}
int binomialcoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}
int min(int a,int b)
{
    return (a<b)? a:b;
}
