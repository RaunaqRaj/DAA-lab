#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than Knapsack capacity W,
    // then this item cannot be included in the optimal solution
    if (wt[n - 1] > W){
         usleep(1000);
        return knapSack(W, wt, val, n - 1);
    }

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else{
         usleep(1000);
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
    }
}

int main() {
    int n;

    cout << "Enter the number of items: ";
    cin >> n;

    int *profit = new int[n];
    int *weight = new int[n];

    cout << "Enter the profits for each item: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter the weights for each item: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    // // Measure time without usleep
    // clock_t start_time = clock();
    // int result = knapSack(W, weight, profit, n);
    // clock_t end_time = clock();
    // double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    // cout << "\nMaximum profit without delay: " << result << endl;
    // cout << "Time taken without delay: " << time_taken << " seconds" << endl;

    // Introduce a delay of 1000 microseconds (1 millisecond) for each recursive call
    clock_t start_time = clock();
    int result = knapSack(W, weight, profit, n);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nMaximum profit with delay: " << result << endl;
    cout << "Time taken with delay: " << time_taken << " seconds" << endl;

    // Clean up dynamic memory
    delete[] profit;
    delete[] weight;

    return 0;
}
