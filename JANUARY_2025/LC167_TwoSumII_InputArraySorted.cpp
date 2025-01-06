class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans(2);
        int l=0;
        int n=numbers.size();
        int r=n-1;

        while(l<n && r>0 && l<r){
            int num=numbers[l]+numbers[r];
            if(num==target) { ans[0]=l+1; ans[1]=r+1;  return ans;}  
         else{
            if(num>target)r--;
             else l++;
         }
        }
        return ans;
    }
};
