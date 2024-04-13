class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>x;
        int s=0;
        int f=n;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
            x.push_back(nums[s]);
            s++;
            }
            else{
            x.push_back(nums[f]);
                f++;
            }
        }
        return x;
    }
};
