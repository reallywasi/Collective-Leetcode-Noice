/*
Question: Ways to Split Array into Two Valid Parts

You are given an integer array `nums` of length `n`. Your task is to count the number of ways to split the array into two non-empty parts 
such that the sum of the left part is greater than or equal to the sum of the right part.

- The left part of the array consists of the elements `nums[0]` to `nums[i]`.
- The right part of the array consists of the elements `nums[i + 1]` to `nums[n - 1]`.

For each valid split index `i` (where 0 <= i < n - 1):
    - Left sum = sum of elements from `nums[0]` to `nums[i]`.
    - Right sum = sum of elements from `nums[i + 1]` to `nums[n - 1]`.
Count the number of indices `i` where `Left sum >= Right sum`.

Constraints:
- 2 <= nums.length <= 10^5
- -10^7 <= nums[i] <= 10^7

Input Example:
nums = [10, 4, -8, 7]

Output Example:
2
Explanation:
- Split at i = 0: Left sum = 10, Right sum = 3 → Valid.
- Split at i = 1: Left sum = 14, Right sum = -1 → Valid.
- Split at i = 2: Left sum = 6, Right sum = 7 → Not valid.
Result: 2
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        vector<long long> presum(n); // Use long long to handle potential overflow in sums
        presum[0] = nums[0]; // Initialize the first element of prefix sum
        int cnt = 0; // Counter to track the number of valid splits

        // Compute the prefix sum array
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] + nums[i]; // Add current element to the sum of previous elements
        }

        // Iterate through the array to count valid splits
        for (int i = 0; i < n - 1; i++) {
            // Left sum: presum[i]
            // Right sum: presum[n - 1] - presum[i]
            if (presum[i] >= presum[n - 1] - presum[i]) {
                cnt++; // Increment counter if the condition is met
            }
        }

        return cnt; // Return the total number of valid splits
    }
};
