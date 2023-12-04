#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <unistd.h>

using namespace std;

// Structure for an item which stores weight and corresponding value of Item
struct Item {
    int profit, weight;

    // Constructor
    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

// Comparison function to sort Item according to profit/weight ratio
static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

// Main greedy function to solve the problem
double fractionalKnapsack(int W, vector<Item>& arr) {
    // Sorting Item on the basis of ratio
    sort(arr.begin(), arr.end(), cmp);

    double finalValue = 0.0;

    // Looping through all items
    for (const auto& item : arr) {
        // If adding Item won't overflow, add it completely
        if (item.weight <= W) {
            W -= item.weight;
            finalValue += item.profit;
        } else {
            // If we can't add the current Item, add the fractional part of it
            finalValue += item.profit * ((double)W / (double)item.weight);
            break;
        }
        usleep(1000);
    }

    // Returning final value
    return finalValue;
}

int main() {
    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter profit and weight for each item:\n";
    for (int i = 0; i < n; ++i) {
        int profit, weight;
        cout << "Item " << i + 1 << " - Profit: ";
        cin >> profit;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weight;
        items.emplace_back(profit, weight);
    }

    // Function call
    clock_t start_time = clock();
    double result = fractionalKnapsack(W, items);
    clock_t end_time = clock();

    cout << "Maximum value in Knapsack = " << result << endl;

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time taken by fractional knapsack: " << time_taken << " seconds" << endl;

    return 0;
}
