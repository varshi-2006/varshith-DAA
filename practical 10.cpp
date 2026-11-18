
#include <iostream>    // For input and output
#include <algorithm>   // For sorting edges

using namespace std;

// Structure to store edge information
struct Edge
{
    int u, v, weight; // Starting vertex, ending vertex and weight
};

// Function to compare edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight; // Sort in ascending order
}

int parent[10]; // Array to store parent of each vertex

// Find the parent of a vertex
int find(int x)
{
    // If vertex is its own parent, return it
    if (parent[x] == x)
        return x;

    // Recursively find the root parent
    return find(parent[x]);
}

// Function to combine two sets
void unionSet(int u, int v)
{
    int rootU = find(u); // Find root of first vertex
    int rootV = find(v); // Find root of second vertex

    parent[rootV] = rootU; // Join both sets
}

// Main function
int main()
{
    int n, e;

    // Get number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    // Get number of edges
    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20]; // Array to store edges

    // Read edge details
    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Initialize each vertex as its own parent
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    // Sort all edges by increasing weight
    sort(edges, edges + e, compare);

    int totalCost = 0; // Store total MST cost
    int count = 0;     // Count selected edges

    // Display Minimum Spanning Tree
    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    // Select edges until MST contains n-1 edges
    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u; // First vertex
        int v = edges[i].v; // Second vertex

        // Check whether adding edge creates a cycle
        if (find(u) != find(v))
        {
            // Print selected edge and its weight
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            // Add edge weight to total cost
            totalCost += edges[i].weight;

            // Combine the two sets
            unionSet(u, v);

            // Increase selected edge count
            count++;
        }
    }

    // Display minimum spanning tree cost
    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0; // End program
}
