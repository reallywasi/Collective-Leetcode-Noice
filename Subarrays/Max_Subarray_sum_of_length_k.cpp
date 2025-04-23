problem:
  title: Maximum Sum Subarray of Size K
  description: >
    Given an integer array and an integer k, find the maximum sum of any contiguous subarray of size k.

    
//________________________________________________________________________________________________

approach:
  name: Sliding Window using Queue
  explanation: >
    We use a fixed-size sliding window approach with a queue to maintain the elements of the current window.
    The sum of the current window is updated by removing the front (oldest) element and adding the new element.
    This allows calculating each window's sum in constant time after the first window.

  time_complexity: O(n)
  space_complexity: O(k)  # due to the queue storing k elements

variables:
  - nums: input array of integers
  - windowSize: the size k of the window
  - windowQueue: queue maintaining the current window elements
  - currentSum: sum of the elements in the current window
  - maxSum: tracks the maximum window sum seen so far


//________________________________________________________________________________________________
code_cpp_with_better_names:
  cpp: |
    class Solution {
    public:
        int maximumSumSubarray(vector<int>& nums, int windowSize) {
            queue<int> windowQueue;
            int currentSum = 0;
            int maxSum = INT_MIN;

            // Initialize the first window
            for (int i = 0; i < windowSize; i++) {
                windowQueue.push(nums[i]);
                currentSum += nums[i];
            }
            maxSum = currentSum;

            // Slide the window
            for (int i = windowSize; i < nums.size(); i++) {
                int elementToRemove = windowQueue.front();
                windowQueue.pop();
                currentSum -= elementToRemove;

                int elementToAdd = nums[i];
                windowQueue.push(elementToAdd);
                currentSum += elementToAdd;

                maxSum = max(maxSum, currentSum);
            }

            return maxSum;
        }
    };


//________________________________________________________________________________________________

dry_run:
  input:
    nums: [1, 4, 2, 10, 2, 3, 1, 0, 20]
    k: 4
  step_by_step:
    - Window: [1, 4, 2, 10] -> Sum: 17 -> maxSum: 17
    - Window: [4, 2, 10, 2] -> Sum: 18 -> maxSum: 18
    - Window: [2, 10, 2, 3] -> Sum: 17 -> maxSum: 18
    - Window: [10, 2, 3, 1] -> Sum: 16 -> maxSum: 18
    - Window: [2, 3, 1, 0] -> Sum: 6 -> maxSum: 18
    - Window: [3, 1, 0, 20] -> Sum: 24 -> maxSum: 24

  final_output: 24

concepts:
  - Sliding Window
  - Queue (FIFO)
  - Subarray
  - Contiguous Sums

similar_questions:
  - LeetCode 239: Sliding Window Maximum
  - LeetCode 209: Minimum Size Subarray Sum
  - LeetCode 1004: Max Consecutive Ones III












//________________________________________________________________________________________________

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
