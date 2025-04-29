Problem:
  Title: "Count Subarrays Where Max Element Appears at Least K Times"
  Difficulty: Medium
  Input:
    nums: List of integers
    k: Positive integer
  Goal: Count the number of subarrays where the maximum element of the entire array appears at least k times

Approach:
  - Step 1: Identify the maximum element in the array
  - Step 2: Use a sliding window technique (two pointers: left and right)
  - Step 3: Track frequency of each element using a hash map (unordered_map)
  - Step 4: Expand window to the right until the max element appears k times
  - Step 5: When condition is satisfied (max element frequency >= k):
      - Count all subarrays starting at current `l` and ending from `r` to `n-1`, which is (n - r)
      - Move left pointer to shrink window and continue checking
  - Step 6: Return the total count

Code:
  Language: C++
  Sliding Window: Used for efficient subarray counting
  Hash Map: Used to count frequencies of elements in the current window

Dry_Run:
  Input: [1, 3, 2, 3, 3], k = 2
  max_element: 3
  n: 5
  l: 0, r: 0
  freq: {}
  cnt: 0

  Iteration_1:
    r = 0, nums[r] = 1
    freq = {1: 1}
    freq[3] < 2 → nothing added
    r++

  Iteration_2:
    r = 1, nums[r] = 3
    freq = {1: 1, 3: 1}
    freq[3] < 2 → nothing added
    r++

  Iteration_3:
    r = 2, nums[r] = 2
    freq = {1: 1, 2: 1, 3: 1}
    freq[3] < 2 → nothing added
    r++

  Iteration_4:
    r = 3, nums[r] = 3
    freq = {1: 1, 2: 1, 3: 2}
    freq[3] >= 2 → valid
    → Add (5 - 3) = 2 to cnt
    → cnt = 2
    Shrink window:
      Remove nums[0] = 1 → freq[1]--
      l = 1
      freq[3] still >= 2 → add (5 - 3) = 2 → cnt = 4
      Remove nums[1] = 3 → freq[3]--, freq = 1
      l = 2
    r++

  Iteration_5:
    r = 4, nums[r] = 3
    freq = {2: 1, 3: 2}
    freq[3] >= 2 → valid
    → Add (5 - 4) = 1 → cnt = 5
    Shrink window:
      Remove nums[2] = 2 → freq[2]--
      l = 3
      freq[3] still >= 2 → add (5 - 4) = 1 → cnt = 6
      Remove nums[3] = 3 → freq[3]--, freq = 1
      l = 4
    r++

  Final Result: 6

Learnings:
  Sliding_Window:
    - Powerful tool for counting subarrays with a condition
    - Time-efficient: O(n) traversal using two pointers
  Counting_Subarrays:
    - If a subarray [l...r] satisfies a condition,
      then all super-subarrays [l...r+1], [l...r+2], ..., [l...n-1] also satisfy it
    - Hence, add (n - r) to total count
  Optimization:
    - Frequency tracking can be optimized to O(1) space by only tracking frequency of the max element
  Key_Takeaway:
    - When looking for conditions in subarrays related to counts (like "at least k times"),
      the idea of extending right and shrinking left while counting is often optimal
    - Understanding the "window saturation point" is critical (when the condition becomes true)

Complexity:
  Time: O(n)
  Space: O(n)  # can be optimized to O(1) if we track only the count of max element



class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i: nums) maxi=max(maxi,i);
        unordered_map<int,int>freq;
        int l=0;
        int r=0; long long  cnt=0;

        while(r<n)
        {
            freq[nums[r]]++;
            while(freq[maxi]>=k && r<n)
            {
                freq[nums[l]]--;
                l++;
                cnt=cnt+n-r;
            }
            r++;
        }
        return cnt;
    }
};








