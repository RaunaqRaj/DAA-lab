#include <iostream>
#include <ctime>
#include <unistd.h> // Include the unistd.h header for sleep

using namespace std;

void insertion(int arr[], int n) {
    int key;
    for (int j = 1; j < n; j++) {
        key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            usleep(1000);
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

int main() {
    int n;

    cout << "Enter the number of elements of the array: ";
    cin >> n;
    cout << "Enter the array: ";

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    clock_t start_time = clock(); // Start measuring time

    insertion(arr, n);

    clock_t end_time = clock(); // Stop measuring time

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Calculate time taken in milliseconds
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by insertion sort: " << time_taken << endl;

    // Introduce a delay of 2 seconds (2000 milliseconds) before exiting

    return 0;
}
