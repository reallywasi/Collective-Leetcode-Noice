MaxProductSubarray:
  description: |
    Finds the maximum product subarray in an integer array (may include negatives and zeros).
    This is a classic problem involving dynamic tracking of current max and min products due to sign flips.
  
  problem: |
    Given an array of integers (positive, negative, or zero), find the contiguous subarray that has the largest product.

 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  intuition: |
    - Products behave differently from sums because of negative numbers.
    - A negative number flips the sign of a product.
    - Hence, the max product at the current index may come from:
      1. The current number alone.
      2. The product of the current number and the previous max.
      3. The product of the current number and the previous min.
    - So, track both current max and current min.
    - If a negative number comes, swap them to reflect the flipped sign.


 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    
  approach:
    - Initialize:
        currmax: maximum product ending at current index
        currmin: minimum product ending at current index
        prod: global maximum product
    - Iterate from index 1 to end:
        If current number < 0 → swap currmax and currmin
        currmax = max(nums[i], nums[i] * currmax)
        currmin = min(nums[i], nums[i] * currmin)
        Update prod = max(prod, currmax)

  code_flow:
    initial_values:
      currmax: nums[0]
      currmin: nums[0]
      prod: nums[0]
    for_each_element_from_1_to_end:
      if_negative:
        swap currmax and currmin
      update:
        currmax = max(nums[i], nums[i] * currmax)
        currmin = min(nums[i], nums[i] * currmin)
      update_global_max:
        prod = max(prod, currmax)

  dry_run:
    input: [2, 3, -2, 4]
    step_by_step:
      - i = 1:
          nums[i]: 3
          currmax = max(3, 2*3) = 6
          currmin = min(3, 2*3) = 3
          prod = max(2, 6) = 6
      - i = 2:
          nums[i]: -2
          swap currmax and currmin
          currmax = max(-2, 3*(-2)) = max(-2, -6) = -2
          currmin = min(-2, 6*(-2)) = min(-2, -12) = -12
          prod = max(6, -2) = 6
      - i = 3:
          nums[i]: 4
          currmax = max(4, -2*4) = 4
          currmin = min(4, -12*4) = -48
          prod = max(6, 4) = 6
    output: 6

  edge_cases:
    - input: [0, 2] → Output: 2
    - input: [-2, 0, -1] → Output: 0
    - input: [-2, 3, -4] → Output: 24

  points_to_remember:
    - Products need both min and max tracking due to negative flips.
    - Swapping before multiplying with a negative number is critical.
    - Initialize with `nums[0]` instead of 0 because arrays might have all negatives.

  time_complexity: O(n)
  space_complexity: O(1)

 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    
  learning_outcomes:
    - Understand how signs affect product logic differently from sums.
    - Recognize when to track multiple states (like min and max) for dynamic problems.
    - Learn the importance of swapping and state resetting when signs matter.


 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


    class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax=nums[0];
        int currmin=nums[0];
        int prod=nums[0];

        for(int i=1;i<nums.size();i++)
            {
                if(nums[i]<0) swap(currmax,currmin);

                currmax=max(nums[i],nums[i]*currmax);
                currmin=min(nums[i],nums[i]*currmin);

                prod=max(prod,currmax);

            }
return prod;
    }
};


