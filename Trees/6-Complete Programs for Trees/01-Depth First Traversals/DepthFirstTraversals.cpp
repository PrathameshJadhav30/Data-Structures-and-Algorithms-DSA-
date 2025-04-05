#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V); // Resize adjacency list to hold V vertices
    }

    // Function to add an edge to the graph (undirected by default)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For directed graphs, remove this line
    }

    // Recursive function for DFS
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true; // Mark the current node as visited
        cout << v << " ";  // Print the current node

        // Recur for all adjacent vertices
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS traversal starting from a given vertex
    void DFS(int start) {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        cout << "DFS starting from vertex " << start << ":\n";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);  // Create a graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    // Perform DFS traversal
    g.DFS(0);

    return 0;
}
