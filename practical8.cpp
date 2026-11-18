
#include <iostream>   // For input and output
#include <vector>     // For storing graph connections
#include <queue>      // For BFS queue
#include <chrono>     // For measuring execution time

using namespace std;
using namespace chrono;

// Class to represent a Graph
class Graph {
    int V;                  // Number of vertices
    vector<vector<int>> adj; // Adjacency list to store edges

public:
    // Constructor to initialize the graph
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);      // Create space for all vertices
    }

    // Function to add an edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Makes the graph undirected
    }

    // Recursive function for DFS traversal
    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;  // Mark current vertex as visited
        cout << v << " ";   // Print current vertex

        // Visit all adjacent vertices
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited); // Recursive DFS call
            }
        }
    }

    // Function to start DFS traversal
    void DFS(int start) {
        vector<bool> visited(V, false); // Initially all vertices are unvisited
        DFSUtil(start, visited);        // Call recursive DFS
    }

    // Function to perform BFS traversal
    void BFS(int start) {
        vector<bool> visited(V, false); // Initially all vertices are unvisited
        queue<int> q;                   // Create a queue

        visited[start] = true;          // Mark starting vertex visited
        q.push(start);                  // Insert starting vertex into queue

        // Continue until the queue becomes empty
        while (!q.empty()) {
            int node = q.front();       // Get front vertex
            q.pop();                    // Remove it from queue

            cout << node << " ";        // Print current vertex

            // Visit all adjacent vertices
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark as visited
                    q.push(neighbor);          // Add to queue
                }
            }
        }
    }
};

// Main function
int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;                           // Read number of vertices

    Graph g(V);                          // Create graph object

    cout << "Enter number of edges: ";
    cin >> E;                           // Read number of edges

    cout << "Enter edges (u v):\n";

    // Read all edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);                // Add edge to graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;                       // Read starting vertex

    // Measure DFS execution time
    auto startTime = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    g.DFS(start);                       // Perform DFS

    auto endTime = high_resolution_clock::now();

    // Calculate DFS time in nanoseconds
    auto dfsTime = duration_cast<nanoseconds>(
        endTime - startTime).count();

    // Measure BFS execution time
    startTime = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    g.BFS(start);                       // Perform BFS

    endTime = high_resolution_clock::now();

    // Calculate BFS time in nanoseconds
    auto bfsTime = duration_cast<nanoseconds>(
        endTime - startTime).count();

    // Display execution times
    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime << " ns";
    cout << "\nBFS: " << bfsTime << " ns";

    return 0;                           // End program
}
