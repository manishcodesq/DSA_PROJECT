#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int V; 
    list<int>* adj; 

public:
    Graph(int V); 
    void addEdge(int u, int v); 
    void BFS(int start_node); 
    void DFS(int start_node); 
    void DFSUtil(int node, vector<bool>& visited); // Utility function for DFS
    void menu(); 
};


Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V]; // Create adjacency lists
}

// Function to add an edge to the graph
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v); // Add v to u's adjacency list
}

// BFS traversal starting from the given node
void Graph::BFS(int start_node) {
    vector<bool> visited(V, false); // Mark all nodes as not visited
    queue<int> q; // Queue for BFS

    // Mark the start node as visited and enqueue it
    visited[start_node] = true;
    q.push(start_node);

    cout << "\nBFS Traversal starting from node " << start_node << " is: ";

    while (!q.empty()) {
        // Dequeue a vertex and print it
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Get all adjacent vertices of the dequeued node
        // If an adjacent node has not been visited, mark it visited and enqueue it
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl; // New line after traversal
}

// Utility function for DFS
void Graph::DFSUtil(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // Recur for all adjacent vertices
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

// DFS traversal starting from the given node
void Graph::DFS(int start_node) {
    vector<bool> visited(V, false); // Mark all nodes as not visited

    cout << "\nDFS Traversal starting from node " << start_node << " is: ";
    DFSUtil(start_node, visited);
    cout << endl; // New line after traversal
}

// Menu function using switch-case for user interaction
void Graph::menu() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add edge\n";
        cout << "2. BFS Traversal\n";
        cout << "3. DFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int u, v;
            cout << "Enter source node: ";
            cin >> u;
            cout << "Enter destination node: ";
            cin >> v;
            addEdge(u, v);
            cout << "Edge added between " << u << " and " << v << ".\n";
            break;
        }
        case 2: {
            int start_node;
            cout << "Enter starting node for BFS: ";
            cin >> start_node;
            BFS(start_node);
            break;
        }
        case 3: {
            int start_node;
            cout << "Enter starting node for DFS: ";
            cin >> start_node;
            DFS(start_node);
            break;
        }
        case 4:
            cout << "Exiting program.\n";
            return;
        default:
            cout << "Invalid choice! Please choose a valid option.\n";
        }
    }
}

// Main driver code
int main() {
    int vertices;
    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;

    Graph g(vertices);
    g.menu();

    return 0;
}
