problem:
  title: "Largest Sub‑array With Sum 0"
  difficulty: "Medium"
  statement: |
    Given an integer array **arr** (values may be positive, negative, or zero),
    return the length of the *longest* contiguous sub‑array whose elements sum to **0**.
examples:
  - input:  [15, -2, 2, -8, 1, 7, 10, 23]
    output: 5
    reason:  [-2, 2, -8, 1, 7] has length 5 and sums to 0.
  - input:  [2, 10, 4]
    output: 0
    reason:  No contiguous segment sums to 0.
  - input:  [1, 0, -4, 3, 1, 0]
    output: 5
    reason:  [0, -4, 3, 1, 0] has length 5 and sums to 0.
constraints:
  n: 1 ≤ n ≤ 1 000 000
  arr[i]: -1 000 ≤ arr[i] ≤ 1 000
  time_expected: O(n)
  extra_space_expected: O(n)

//########################################################################################################
//########################################################################################################

  
  
intuition:
  - |
    **Prefix‑sum insight**  
    If two prefix sums are equal, the elements *between* those prefixes sum to 0
    (because their difference cancels).  
    Therefore, to find the longest zero‑sum stretch we only need to know
    the *first* index where each prefix sum appears.


//########################################################################################################
//########################################################################################################

  
approach:
  algorithm: |
    1. Compute running/prefix sums while scanning the array.
    2. Maintain a hash‑map `firstIndex` that stores, for each prefix‑sum value,
       the earliest index where it occurred.
    3. For each index `i`
       - If `prefixSum == 0`, a sub‑array from **0‥i** sums to 0 → length = i + 1.
       - Else if `prefixSum` has been seen before at `j`, then
         sub‑array **(j+1)‥i** sums to 0 → length = i − j.
       - Update the answer with the maximum of these lengths.
       - If the current `prefixSum` has **not** been recorded yet,
         record `firstIndex[prefixSum] ← i` (earliest occurrence).
  complexity:
    time:  O(n)  # single pass
    space: O(n)  # hash‑map may store up to n distinct prefix sums


//########################################################################################################
//########################################################################################################

  
dry_run:
  with_input: [15, -2, 2, -8, 1, 7, 10, 23]
  table:
    - i: 0
      arr[i]: 15
      prefixSum: 15
      firstIndex: {15:0}
      size: 0
    - i: 1
      arr[i]: -2
      prefixSum: 13
      firstIndex: {15:0, 13:1}
      size: 0
    - i: 2
      arr[i]: 2
      prefixSum: 15
      seen_before_at: 0
      new_size: 2  # i - 0
      size: 2
    - i: 3
      arr[i]: -8
      prefixSum: 7
      firstIndex: {15:0, 13:1, 7:3}
      size: 2
    - i: 4
      arr[i]: 1
      prefixSum: 8
      firstIndex: {..., 8:4}
      size: 2
    - i: 5
      arr[i]: 7
      prefixSum: 15
      seen_before_at: 0
      new_size: 5  # i - 0
      size: 5
    - i: 6,7 ...
      (no longer sub‑arrays beat length 5)
  answer: 5
learning_points:
  - Prefix sums convert a sub‑array‑sum problem into a “duplicate value” detection problem.
  - Hash‑maps let us store *earliest occurrence* in O(1) average time.
  - Always check `prefixSum == 0` explicitly: handles zero‑sum from index 0.
  - For longest/shortest sub‑array questions, think “record the first time you see something”.


  
//########################################################################################################
//########################################################################################################

  ```
extras:
  overflow_note: |
    With n ≤ 10^6 and |arr[i]| ≤ 10^3,
    max |prefixSum| ≤ 10^9 → still fits in 32‑bit *signed* int,
    but using `long long` is a safe habit.
  alternative:
    two_pointer: |
      Not applicable here because elements are not guaranteed positive.
    sorting: |
      If space is a concern, one could sort pairs (prefixSum,index)
      and scan, but that costs O(n log n) time.





//########################################################################################################
//########################################################################################################

  
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n=arr.size();
vector<int>presum(n);     presum[0]=arr[0];

    for(int i=1;i<n;i++){    presum[i]=presum[i-1]+arr[i];    }
    

    int size=0;
unordered_map<int,int>firstindex;    
    for(int i=0;i<presum.size();i++)
    {   
        if(presum[i] == 0) size=max(size,i+1);
        if(firstindex.find(presum[i])!=firstindex.end())
        {
            size=max(size,i-firstindex[presum[i]]);
        }else{
           firstindex[presum[i]]=i; 
        }
    }
    return size;
    
    }
};
