// File Name: ContainsDuplicateII.cpp

/*
 * Problem Statement:
 * Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array
 * such that nums[i] == nums[j] and the absolute difference between i and j is at most k.
 * Otherwise, return false.
 * 
 * Example:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * Explanation: nums[0] == nums[3] and |0 - 3| <= 3.
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 * - 0 <= k <= nums.length
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Hash map to store the last seen index of each number
        unordered_map<int, int> indexMap; 
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current number has been seen before
            if (indexMap.find(nums[i]) != indexMap.end()) {
                // If the difference in indices is at most k, return true
                if (i - indexMap[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the last seen index of the current number
            indexMap[nums[i]] = i;
        }
        
        // No such pair found, return false
        return false;
    }
};
