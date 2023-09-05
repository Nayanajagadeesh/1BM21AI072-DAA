#include <iostream>
#include <ctime>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // If right child is larger than root
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // If root is not largest
    if (largest != i) {
        // Swap a[i] with a[largest]
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

// Function to implement heap sort
void heapSort(int a[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root element to end
        // Swap a[0] with a[i]
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
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
            int a[15000];
            cout << "Enter array elements: ";
            for (int i = 0; i < n; i++)
                cin >> a[i];

            start = clock();
            heapSort(a,n);
            end = clock();

            cout << "Sorted array is: ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";

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
                heapSort(a,n);
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
