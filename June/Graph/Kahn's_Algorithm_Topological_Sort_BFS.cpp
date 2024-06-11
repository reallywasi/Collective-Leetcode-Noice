class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
vector<int>indegree(V,0);
vector<int>topoorder;
queue<int>q;

for(int i=0;i<V;i++)
{
    for(auto it:adj[i])
    {
        indegree[it]++;
    }
}
for(int i=0;i<V;i++)
{
    if(indegree[i]==0) q.push(i);
}

while(!q.empty())
{
    int node=q.front();
    q.pop();
    topoorder.push_back(node);
    for(auto neighbour:adj[node])
    {
        indegree[neighbour]--;
        if(indegree[neighbour]==0) q.push(neighbour);
    }
}
return topoorder;

	}
};
