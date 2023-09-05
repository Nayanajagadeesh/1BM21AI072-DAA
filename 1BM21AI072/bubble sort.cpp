#include <iostream>
#include <ctime>
using namespace std;

void bubblesort(int n, int arr[]) {
  int temp;
  for(int i=0;i<n-1;i++)
  {

      for(int j=0;j<n-i-1;j++)
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

int main() {
    int n, ch;
    clock_t start, end;

    while (true) {
        cout << "1: For manual entry of N value and array elements\n";
        cout << "2: To display time taken for sorting number of elements N in the range 500 to 14500\n";
        cout << "3: To exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter the number of elements: ";
            cin >> n;
            int arr[15000];
            cout << "Enter array elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            start = clock();
            bubblesort(n, arr);
            end = clock();

            cout << "Sorted array is: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

            cout << "\nTime taken to sort " << n << " numbers is " << ((double)(end - start) / CLOCKS_PER_SEC) << " seconds\n";
            break;

        case 2:
            n = 500;
            while (n <= 14500) {
                int arr[15000];
                for (int i = 0; i < n; i++) {
                    arr[i] = n - i;
                }
                start = clock();
                bubblesort(n, arr);
                end = clock();

                cout << "Time taken to sort " << n << " numbers is " << ((double)(end - start) / CLOCKS_PER_SEC) << " seconds\n";
                n += 1000;
            }
            break;

        case 3:
            exit(0);

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
