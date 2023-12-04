// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

        usleep(1000);
	// Sorting the right part
	quickSort(arr, p + 1, end);
}

int main()
{
    int n;

    cout << "Enter the number of elements of the array: ";
    cin >> n;
    cout << "Enter the array: ";

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    clock_t start_time = clock();

	quickSort(arr, 0, n - 1);

    clock_t end_time = clock();

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by quick sort: " << time_taken << endl;

	return 0;
}
