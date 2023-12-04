#include <algorithm>
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

struct Job {
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
            usleep(1000);
        }
    }

    cout << "Following is the maximum profit sequence of jobs:\n";
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << "Job " << arr[result[i]].id << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter job details (id, deadline, profit) for each job:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ":\n";
        cout << "Enter job id: ";
        cin >> arr[i].id;
        cout << "Enter job deadline: ";
        cin >> arr[i].dead;
        cout << "Enter job profit: ";
        cin >> arr[i].profit;
    }

    clock_t start_time = clock();
    printJobScheduling(arr, n);
    clock_t end_time = clock();

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by the job scheduling algorithm: " << time_taken << " seconds" << endl;

    return 0;
}
