class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> in_degree(V, 0);
        
        // Calculate in-degrees
        for (int i = 0; i < V; i++)
            for (int neighbor : adj[i])
                in_degree[neighbor]++;
        
        queue<int> q;
        // Enqueue vertices with in-degree 0
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
                q.push(i);
        
        int count = 0; // Counter for the number of vertices processed
        
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            count++;
            
            // Decrease the in-degree of adjacent vertices
            for (int neighbor : adj[node]) 
            {
                in_degree[neighbor]--;
                // If in-degree becomes 0, add to queue
                if (in_degree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // If count of processed vertices is less than the total number of vertices, the graph has a cycle
        return count != V;
    }
};
