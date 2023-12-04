#include <iostream>
#include <climits>
#include <vector>
#include <ctime>
#include <unistd.h>

using namespace std;

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(vector<int>& key, vector<bool>& mstSet)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < key.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(vector<int>& parent, vector<vector<int>>& graph)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(vector<vector<int>>& graph)
{
    // Array to store constructed MST
    vector<int> parent(graph.size());

    // Key values used to pick the minimum weight edge in cut
    vector<int> key(graph.size());

    // To represent the set of vertices included in MST
    vector<bool> mstSet(graph.size(), false);

    // Initialize all keys as INFINITE
    for (int i = 0; i < graph.size(); i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include the first vertex in MST.
    // Make key 0 so that this vertex is picked as the first vertex.
    key[0] = 0;

    // First node is always the root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < graph.size() - 1; count++) {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < graph.size(); v++){

            // graph[u][v] is non zero only for adjacent
            // vertices of u mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        usleep(1000);
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Driver's code
int main()
{
    int n;

    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    // Print the solution
    clock_t start_time = clock();
    primMST(graph);
    clock_t end_time = clock();

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by Prim's algorithm: " << time_taken << endl;

    return 0;
}
