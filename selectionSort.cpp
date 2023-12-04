// C++ program for implementation of
// selection sort
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

// Function for Selection sort
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
            usleep(1000);
		}

		// Swap the found minimum element
		// with the first element
		if (min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
		cout << endl;
	}
}

// Driver program
int main()
{
	int n;

    cout << "Enter the number of elements of the array: ";
    cin >> n;
    cout << "Enter the array: ";

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

	// Function Call
    clock_t start_time = clock();
	selectionSort(arr, n);
    clock_t end_time = clock();
	cout << "Sorted array: \n";
	printArray(arr, n);

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by selection sort: " << time_taken << endl;
	return 0;
}

// This is code is contributed by rathbhupendra
