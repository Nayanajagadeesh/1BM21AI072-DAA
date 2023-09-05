#include <iostream>
using namespace std;

int a[10][10], n;

void bfs(int);
int main()
{
    int i, j, src;
    cout << "\nEnter the number of nodes:\t";
    cin >> n;
    cout << "\nEnter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\nEnter the source node:\t";
    cin >> src;
    bfs(src);
    return 0;
}

void bfs(int src)
{
    int q[10], f = 0, r = -1, vis[10], i, j;
    for (j = 1; j <= n; j++)
    {
        vis[j] = 0;
    }
    vis[src] = 1;
    r = r + 1;
    q[r] = src;
    while (f <= r)
    {
        i = q[f];
        f = f + 1;
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] == 1 && vis[j] != 1)
            {
                vis[j] = 1;
                r = r + 1;
                q[r] = j;
            }
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (vis[j] != 1)
        {
            cout << "\nNode " << j << " is not reachable\n";
        }
        else
        {
            cout << "\nNode " << j << " is reachable\n";
        }
    }
}
