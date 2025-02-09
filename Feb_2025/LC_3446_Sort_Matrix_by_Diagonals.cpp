class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>diag;
int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                diag[i-j].push_back(grid[i][j]);
            }
        }

        for(auto & c : diag)
        {
            if(c.first>=0) sort(c.second.begin(),c.second.end());
            else sort(c.second.begin(),c.second.end(),greater<int>());
        }
             for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=diag[i-j].back();
                diag[i-j].pop_back();
            }
        }   
return grid;

    }
};
