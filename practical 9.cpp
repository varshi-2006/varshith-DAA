
#include <iostream>  // For input and output
#include <climits>   // For INT_MAX
using namespace std;

// Main function
int main()
{
    int n;

    // Get number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10]; // Adjacency matrix to store graph

    // Read adjacency matrix
    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j]; // Read edge weight
        }
    }

    int parent[10];  // Stores parent of each vertex
    int key[10];     // Stores minimum edge weight
    bool visited[10]; // Tracks visited vertices

    // Initialize all vertices
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;   // Set initial key to infinity
        visited[i] = false; // Mark all vertices unvisited
    }

    // Start Prim's algorithm from vertex 0
    key[0] = 0;
    parent[0] = -1; // Starting vertex has no parent

    // Find Minimum Spanning Tree
    for (int count = 0; count < n - 1; count++)
    {
        int min = INT_MAX;
        int u = -1;

        // Find unvisited vertex with minimum key value
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        // Mark selected vertex as visited
        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++)
        {
            // Check if edge exists and vertex is unvisited
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;        // Update parent vertex
                key[v] = graph[u][v]; // Update minimum edge weight
            }
        }
    }

    // Print Minimum Spanning Tree
    int totalCost = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    // Display selected edges and calculate total cost
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]]; // Add edge weight
    }

    // Display minimum total cost
    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0; // End program
}
