
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

    int graph[10][10]; // Adjacency matrix

    // Read adjacency matrix
    cout << "Enter the adjacency matrix:\n";
    cout << "Enter 0 for no edge (except diagonal):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j]; // Read edge weight

            // Replace 0 with infinity if no edge exists
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall Algorithm
    // Find shortest paths between all pairs of vertices
    for (int k = 0; k < n; k++)
    {
        // Select source vertex
        for (int i = 0; i < n; i++)
        {
            // Select destination vertex
            for (int j = 0; j < n; j++)
            {
                // Check whether both paths exist
                if (graph[i][k] != INT_MAX &&
                    graph[k][j] != INT_MAX &&

                    // Check if new path is shorter
                    graph[i][k] + graph[k][j] < graph[i][j])
                {
                    // Update shortest distance
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Display shortest distance matrix
    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Display INF if no path exists
            if (graph[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }

        cout << endl; // Move to next row
    }

    return 0; // End program
}
