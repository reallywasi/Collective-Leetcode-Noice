class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>prod;

        for(int i=0;i<nums.size();i++)
        {
             for(int j=i+1;j<nums.size();j++)
        {
            int pdt=nums[i]*nums[j];
            prod[pdt]++;
        }
        }
        int result=0;
     for(auto p:prod)
     {
        if(p.second>1) {
result+=8*(p.second)*(p.second-1)/2;
        }
     }
     return result;
    }
};


