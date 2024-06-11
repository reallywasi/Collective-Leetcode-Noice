#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> shortestPath(vector<int> adj[], int V, int s, int e) {
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto i : adj[front]) {
            if(!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
                // Early exit if we reach the end node
                if(i == e) break;
            }
        }
    }

    // If the end node is not reachable
    if(!visited[e]) {
        cout << "No path exists between " << s << " and " << e << "." << endl;
        return {};
    }

    // Reconstruct the path from end to start using parent map
    vector<int> path;
    for(int at = e; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int V = 8; // Number of vertices
    vector<int> adj[V];

    // Add edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[0].push_back(3);
    adj[3].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    adj[4].push_back(5);
    adj[5].push_back(4);
    
    adj[5].push_back(6);
    adj[6].push_back(5);
    
    adj[6].push_back(7);
    adj[7].push_back(6);
    
