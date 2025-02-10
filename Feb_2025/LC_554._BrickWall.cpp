class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int>coordfreq;
int maxcoord=0;
        for(auto & a : wall)
        {
            long long  sum=0;
            for(int i=0;i<a.size()-1;i++)
            {
sum=a[i]+sum;
coordfreq[sum]++;
maxcoord=max(maxcoord,coordfreq[sum]);

            }
        }return wall.size()-maxcoord;;

    }
};
