problem:
  name: "Longest Subarray with Sum Equal to k"
  description: |
    Given an array of integers, you need to find the length of the longest subarray whose sum equals `k`. 
    A subarray is a contiguous part of the array.


//===============================================================================
//===============================================================================

approach:
  explanation: |
    The approach utilizes the concept of prefix sum combined with a hashmap (unordered_map) to store the indices of prefix sums. 
    The idea is to keep track of the cumulative sum at each index, and then check if a subarray with sum equal to `k` can be formed. 
    If the difference between the current prefix sum and `k` is found in the hashmap, it means there is a subarray ending at the current index whose sum is equal to `k`. 
    We keep track of the maximum length of such a subarray.
  steps:
    1. Initialize a prefix sum array to store the cumulative sum of the array at each index.
    2. Use an unordered map (`mp`) to store the first occurrence of each prefix sum.
    3. Traverse through the array and for each element, calculate the current prefix sum.
    4. For each prefix sum, check if the difference between the current prefix sum and `k` exists in the map.
    5. If the difference exists, update the maximum length of the subarray.
    6. If the prefix sum is not found in the map, store its index as the first occurrence.
    7. Return the maximum length of the subarray found.


//===============================================================================
//===============================================================================
  
  
dry_run:
  input: 
    arr: [1, 2, 3, 4, 5]
    k: 9
  steps:
    - Initialize the prefix sum array: [1, 3, 6, 10, 15]
    - Initialize the map: mp = {0: -1}
    - Start iterating over the array:
      1. For i=0, prefix sum = 1, map does not have 1-9=-8, so add {1: 0}
      2. For i=1, prefix sum = 3, map does not have 3-9=-6, so add {3: 1}
      3. For i=2, prefix sum = 6, map does not have 6-9=-3, so add {6: 2}
      4. For i=3, prefix sum = 10, map has 10-9=1 at index 0, subarray from 1 to 3 (size = 3)
      5. For i=4, prefix sum = 15, map has 15-9=6 at index 2, subarray from 3 to 4 (size = 2)
  result:
    longest subarray length: 3


//===============================================================================
//===============================================================================



intuition:
  explanation: |
    The intuition behind the approach is based on the prefix sum concept. As we keep adding elements to the array, we are maintaining the cumulative sum (prefix sum). The key observation is that if the difference between the current prefix sum and `k` exists in the hashmap, then a subarray from that index to the current index has a sum of `k`. 
    By storing the first occurrence of each prefix sum, we can efficiently find subarrays that satisfy the condition in constant time using the hashmap. This reduces the problem from a brute force O(n^2) approach to a linear time O(n) solution.

similar_problems:
  - "Subarray Sum Equals K"
  - "Maximum Size Subarray Sum Equals k"
  - "Subarray Product Less Than K"
  - "Find Subarray with Given Sum"
  - "Subarray with Sum Divisible by K"


//===============================================================================
//===============================================================================





class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
int n=arr.size();
vector<int>presum(n);
presum[0]=arr[0];
for(int i=1;i<n;i++) presum[i]=presum[i-1]+arr[i];
unordered_map<int,int>mp;
mp[0]=-1;
int size=0;

for(int i=0;i<n;i++)
{
    if(mp.find(presum[i]-k)!=mp.end()) size=max(size,i-mp[presum[i]-k]);
    if(mp.find(presum[i])==mp.end()) mp[presum[i]]=i;
}
return size;
    }
};
