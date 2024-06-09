
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool bfsCycleDetection(const vector<vector<int>>& graph, int start, vector<bool>& visited) {
    // Queue to store the vertex and its parent in the BFS
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int vertex = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, vertex});
            } else if (neighbor != parent) {
                // A visited neighbor that is not the parent indicates a cycle
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    // Check for cycles in each component of the graph
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (bfsCycleDetection(graph, i, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Example usage
    int n = 5; // Number of vertices
    vector<vector<int>> graph(n);
    
    // Add edges
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(0);
    graph[0].push_back(4);

    if (hasCycle(graph)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
