#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <climits>

using namespace std;

int NO_PARENT = -1;

void printPath(int currentVertex, vector<int> parents) {
    if (currentVertex == NO_PARENT) {
        return;
    }
    printPath(parents[currentVertex], parents);
    cout << currentVertex << " ";
}

void printSolution(int startVertex, vector<int> distances, vector<int> parents) {
    int nVertices = distances.size();
    cout << "Vertex\t Distance\tPath";

    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
        if (vertexIndex != startVertex) {
            cout << "\n" << startVertex << " -> ";
            cout << vertexIndex << " \t\t ";
            cout << distances[vertexIndex] << "\t\t";
            printPath(vertexIndex, parents);
        }
    }
}

// void introduceDelay() {
//     usleep(1000);
// }

void dijkstra(vector<vector<int>> adjacencyMatrix, int startVertex) {
    int nVertices = adjacencyMatrix[0].size();

    vector<int> shortestDistances(nVertices);
    vector<bool> added(nVertices);

    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
        shortestDistances[vertexIndex] = INT_MAX;
        added[vertexIndex] = false;
    }

    shortestDistances[startVertex] = 0;

    vector<int> parents(nVertices);
    parents[startVertex] = NO_PARENT;

    for (int i = 1; i < nVertices; i++) {
        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
            if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance = shortestDistances[vertexIndex];
            }
        }

        added[nearestVertex] = true;

        usleep(1000);

        for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
            int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];

            if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
            }
        }
    }

    printSolution(startVertex, shortestDistances, parents);
}

int main() {
    int n;

    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjacencyMatrix[i][j];

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    clock_t start_time = clock();
    dijkstra(adjacencyMatrix, startVertex);
    clock_t end_time = clock();

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\nTime taken by Dijkstra's algorithm: " << time_taken << " seconds" << endl;

    return 0;
}
