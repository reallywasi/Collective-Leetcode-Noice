
class Solution {
  public:
  
  // Helper function to perform DFS and check for a cycle in the graph
  bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, int parent) {
      // Mark the current node as visited
      visited[u] = true;
      
      // Iterate through all the adjacent vertices of the current node
      for(int &v : adj[u]) {
          // If the adjacent node is the parent of the current node, skip it
          if(v == parent) continue;
          
          // If the adjacent node is already visited, a cycle is detected
          if(visited[v])
              return true;
          
          // Recursively perform DFS on the adjacent node
          if(isCycleDFS(adj, v, visited, u)) {
              return true;
          }
      }
      
      // If no cycle is detected, return false
      return false;
  }

  // Function to detect cycle in an undirected graph
  bool isCycle(int V, vector<int> adj[]) {
      // Initialize a visited array to keep track of visited nodes
      vector<bool> visited(V, false);
      
      // Iterate through all vertices in the graph
      for(int i = 0; i < V; i++) {
          // If the vertex is not visited, perform DFS to check for a cycle
          if(!visited[i] && isCycleDFS(adj, i, visited, -1)) {
              return true; // Cycle detected
          }
      }
      
      // If no cycle is detected in the graph, return false
      return false;
  }
};
