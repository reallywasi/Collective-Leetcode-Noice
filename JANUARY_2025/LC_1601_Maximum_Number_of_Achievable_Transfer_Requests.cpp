class Solution {
public:
int result=0;
void solve(vector<int>&resultant,vector<vector<int>>& requests,int i,int count,int m)
{
    int allzero=true;
  if (i==m)
    {       for(int x:resultant){
            if(x!=0) { allzero=false; break;}
    }
if(allzero){     result=max(result,count);   }
return;
}
int from=requests[i][0];
int to =requests[i][1];
resultant[from]--;
resultant[to]++;
solve(resultant,requests,i+1,count+1,m);
resultant[from]++;
resultant[to]--;
solve(resultant,requests,i+1,count,m);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>resultant(n);
        int m=requests.size();
        solve(resultant,requests,0,0,m);
        return result;
    }
};
