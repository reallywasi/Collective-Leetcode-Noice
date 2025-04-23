problem:
  name: "Count Number of Nice Subarrays"
  id: 1248
  difficulty: Medium
  input:
    - An array of integers `nums`
    - An integer `k` (number of odd numbers required in the subarray)
  output:
    - The count of subarrays with exactly `k` odd numbers

//=========================================================================================================================================

approach:
  strategy: "Prefix Sum + HashMap"
  description: |
    Convert the problem into a prefix sum problem by converting the array into a binary representation 
    of whether an element is odd or even (odd = 1, even = 0). 
    Then, the task becomes: find the number of subarrays where the sum of this binary version is exactly `k`.
    
    Use a prefix sum array to count the total number of odd numbers up to each index.
    Then use a hashmap to count how often a particular count of odd numbers has occurred.

  why_prefix_sum: |
    - Prefix sums allow us to calculate subarray properties in O(1) using subtraction: 
      if we know total odds till i and j, then count between i and j is `prefix[j] - prefix[i]`.
    - With a map, we can quickly check how many times a prefix count has occurred and use that 
      to count subarrays with exactly `k` odd numbers.

//=========================================================================================================================================
variables:
  oddcnt:
    type: vector<int>
    purpose: Stores the cumulative number of odd numbers till index `i`
  freq:
    type: unordered_map<int, int>
    purpose: Maps odd count values to the number of times they’ve appeared in `oddcnt`
  cnt:
    purpose: Final answer — number of subarrays with exactly `k` odd numbers
//=========================================================================================================================================

code_steps:
  1. Initialize:
    - `oddcnt[0] = 0` (no odd numbers at the start)
    - `freq[0] = 1` (we've seen zero odd numbers one time)
  2. Fill `oddcnt`:
    - For each `i` from 1 to `n`, compute:
      `oddcnt[i] = oddcnt[i-1] + (nums[i-1] % 2)`
    - Meaning: at each step, count the number of odd numbers so far
  3. Count valid subarrays:
    - For each `i` in `oddcnt`:
      - Let `target = oddcnt[i] - k`
      - If `target` has been seen before in the hashmap, add `freq[target]` to count
    - Update the `freq` map: increment count for current `oddcnt[i]`
//=========================================================================================================================================

dry_run:
  input:
    nums: [1, 1, 2, 1, 1]
    k: 3
  oddcnt:
    - Index 0: 0
    - Index 1: 1 (1 is odd)
    - Index 2: 2 (1,1 are odd)
    - Index 3: 2 (1,1,2 — 2 is even)
    - Index 4: 3 (1,1,2,1 — now 3 odds)
    - Index 5: 4 (1,1,2,1,1 — now 4 odds)
  freq_map_updates_and_counting:
    - i = 1: oddcnt = 1; target = -2 → not found
    - i = 2: oddcnt = 2; target = -1 → not found
    - i = 3: oddcnt = 2; target = -1 → not found
    - i = 4: oddcnt = 3; target = 0 → freq[0] = 1 → cnt += 1
    - i = 5: oddcnt = 4; target = 1 → freq[1] = 1 → cnt += 1
  result: 2

complexity:
  time: "O(n)"
  space: "O(n)" for the prefix and hashmap

key_insights:
  - Transforming the problem into a prefix sum + hashmap makes counting efficient
  - The `oddcnt[i] - k` trick lets us know how many valid subarrays end at index `i`
  - Map stores counts of how many times a particular prefix sum has occurred

//=========================================================================================================================================
//=========================================================================================================================================
//=========================================================================================================================================


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>oddcnt(n+1);
        oddcnt[0]=0;
        for(int i=1;i<=n;i++)
        {
            oddcnt[i]=oddcnt[i-1]+nums[i-1]%2;
        }
       unordered_map<int,int>freq;
       freq[0]=1;
int cnt=0;
       for(int i=1; i<n+1;i++)
       {
        if(freq.find(oddcnt[i]-k)!=freq.end())
        {
cnt+=freq[oddcnt[i]-k];
        }
        freq[oddcnt[i]]++;
       }


        return cnt;
    }
};
