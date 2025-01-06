class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort the array to simplify duplicate handling
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first number
            
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers and skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++; // Increase the sum
                } else {
                    right--; // Decrease the sum
                }
            }
        }

        return ans;
    }
};
