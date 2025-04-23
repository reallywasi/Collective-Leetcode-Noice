//brute force
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {

int msum=INT_MIN;
int n=arr.size();
for(int i=0;i<=n-k;i++)
{
    int csum=0;
    for(int j=i;j<i+k;j++)
    {
        csum+=arr[j];
    }
    msum=max(msum,csum);
}

return msum;
    }
};
