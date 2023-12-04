#include <iostream>
#include <climits>  // Include this header for INT_MAX
#include <vector>
#include <ctime>
#include <unistd.h>
using namespace std;

#define INF INT_MAX  // Define INF as INT_MAX

// Function to print the solution matrix
void printSolution(vector<vector<int>> &dist);

// Function to solve the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(vector<vector<int>> &dist)
{
    int V = dist.size();

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
            usleep(1000);
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

// Utility function to print the solution
void printSolution(vector<vector<int>> &dist)
{
    cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    int V = dist.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Function call
    clock_t start_time = clock();
    floydWarshall(graph);
    clock_t end_time = clock();

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by Floyd Warshall algorithm: " << time_taken << " seconds" << endl;

    return 0;
}
