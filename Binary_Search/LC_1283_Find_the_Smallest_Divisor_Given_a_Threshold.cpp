SmallestDivisorProblem:
  problem_statement: >
    Given an array `nums` of integers and a positive integer `threshold`, find the smallest 
    positive integer divisor such that when every element in the array is divided by this divisor, 
    and each result is rounded up (ceil), the total sum of these values is less than or equal to `threshold`.

  example:
    input:
      nums: [1, 2, 5, 9]
      threshold: 6
    output: 5
    explanation: >
      Using divisor = 5, we get:
        ceil(1/5) = 1,
        ceil(2/5) = 1,
        ceil(5/5) = 1,
        ceil(9/5) = 2.
      Sum = 1 + 1 + 1 + 2 = 5 <= threshold.

    
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  intuition: >
    - If the divisor is small, we divide less — each quotient becomes large, so the total sum becomes high.
    - If the divisor is large, each element becomes smaller when divided — the total sum becomes low.
    - This means the total sum is a **monotonic decreasing function** as divisor increases.
    - So, we can apply **binary search** over the range of divisors to find the smallest one that keeps the sum within the threshold.

  approach:
    - Set `lower = 1` (smallest possible divisor)
    - Set `upper = max(nums)` (no need to check beyond this; any larger divisor won't divide any number smaller)
    - Apply binary search:
      - Find `mid = (lower + upper) / 2`
      - Compute `sum = sum of ceil(nums[i] / mid)` for all `i`
      - If `sum > threshold`, it means `mid` is too small → search in higher half (`lower = mid + 1`)
      - Else, store `mid` as a potential answer, and try to minimize it → search in lower half (`upper = mid - 1`)
    - Return the smallest valid `mid`

  learning_outcomes:
    - Practice applying binary search on **answers** (search space is not array index, but values)
    - Understand **monotonicity** in problems to apply binary search efficiently
    - How to safely handle integer division with rounding using `ceil((double)x / y)`
    - Importance of choosing correct search space limits (`[1, max(nums)]`)
    - Difference between binary search patterns: `while (low < high)` vs `while (low <= high)` and how to update bounds accordingly




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


BRUTE FORCE 

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int divisor = 1;

        while (true) {
            int sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                sum += ceil((double)nums[i] / divisor);
            }
            if (sum <= threshold) return divisor;
            else divisor++;
        }

        return -1; // just in case, though the problem guarantees a solution
    }
};




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int upper = *max_element(nums.begin(), nums.end());
        int lower = 1;
        int n = nums.size();
        int ans = upper;
        while (lower <= upper) {
            int sum = 0;
            int mid = (lower + upper) / 2;
            for (int i = 0; i < n; i++) {
                sum += ceil((double)nums[i] / mid);
            }
            if (sum > threshold) {
                lower = mid + 1;
            }

            else {
                upper = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
