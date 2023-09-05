#include <iostream>
#include <ctime>
using namespace std;

void merge(int arr[], int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrayS
   for(i = 0; i<nl; i++)
      larr[i] = arr[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = arr[m+1+j];
   i = 0; j = 0; k = l;
   //merge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      arr[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      arr[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int arr[], int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      merge(arr, l, m, r);
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
            mergeSort(arr, 0, n - 1);
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
                    // Using random number generator to fill the array
                    arr[i] = rand() % 10000; // Generates random numbers in the range [0, 9999]
                }
                start = clock();
                mergeSort(arr, 0, n - 1);
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
