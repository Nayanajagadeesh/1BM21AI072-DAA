#include <iostream>
using namespace std;

void nqueens(int n);
int place(int x[], int k);

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;
    nqueens(n);
    return 0;
}

void nqueens(int n) {
    int k, x[20], count = 0;
    k = 1;
    x[k] = 0;

    while (k != 0) {
        x[k]++;
        while (place(x, k) != 1 && x[k] <= n) {
            x[k]++;
        }

        if (x[k] <= n) {
            if (k == n) {
                cout << "\nSolution " << ++count << endl;
                cout << "Queen\tPosition" << endl;
                for (k = 1; k <= n; k++) {
                    cout << k << "\t" << x[k] << endl;
                }
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
}

int place(int x[], int k) {
    for (int i = 1; i <= k - 1; i++) {
        if (i + x[i] == k + x[k] || i - x[i] == k - x[k] || x[i] == x[k]) {
            return 0;
        }
    }
    return 1;
}
