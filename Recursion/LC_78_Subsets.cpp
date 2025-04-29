problem:
  title: Subsets
  problem_statement: |
    Given a collection of integers, `nums`, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.
    Each subset must be returned as a list of integers.

  example:
    input: [1, 2, 3]
    output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
    
  constraints: 
    - The number of elements in `nums` is between 0 and 10.
    - The integers in `nums` are distinct.

approach:
  - Problem Type: Backtracking
  - High-Level Approach:
      - Use backtracking to explore all possible subsets.
      - For each element, recursively include or exclude it and generate all combinations.
      - Store each valid subset when the recursion reaches the end of the array.
  
  detailed_steps:
    - Start with an empty subset and an index of 0.
    - At each step, decide whether to include the current element in the subset or not.
    - Recursively explore both options: including the element or excluding it.
    - Once the recursion reaches the end of the list, add the current subset to the answer.
    - Use backtracking to undo the inclusion and explore the other option (excluding the element).

  code:
    solution: |
      class Solution {
      public:
          void solve(vector<vector<int>>& ans, vector<int>& output, int index, vector<int>& nums) {
              if(index >= nums.size()) {
                  ans.push_back(output);
                  return;
              }
              
              // Including the current element
              output.push_back(nums[index]);
              solve(ans, output, index + 1, nums);
              
              // Excluding the current element
              output.pop_back();
              solve(ans, output, index + 1, nums);
          }

          vector<vector<int>> subsets(vector<int>& nums) {
              vector<vector<int>> ans;
              vector<int> output;
              solve(ans, output, 0, nums);
              return ans;
          }
      };
    
learning_from_problem:
  - **Backtracking** is a powerful technique used to generate all possible combinations of a set of elements. It involves building the solution incrementally and then undoing choices to explore other possibilities.
  - **Recursion** helps in solving problems where the same subproblem is solved multiple times. By using recursion with backtracking, we can efficiently explore all subsets of the given set.
  - Understanding when and how to use the **include-exclude** pattern in recursion is key to solving subset-related problems.
  - The solution leverages the fact that each element has two possibilities: it is either included in the subset or it is not.
  
patterns:
  - **Backtracking Pattern**: This is a typical backtracking problem, where we have a decision to make at each step (include or exclude an element), and we explore both decisions recursively.
  - **Recursive Tree**: The recursive calls can be visualized as a decision tree, where each node represents a decision to include or exclude an element, and each leaf node represents a valid subset.
  - **Space Complexity**: The space complexity is **O(n)** because, in the worst case, the depth of recursion will be `n`, and at each level, we store the current subset, which has a space complexity of **O(n)**.
  - **Time Complexity**: The time complexity is **O(2^n)**, where `n` is the number of elements in `nums`. This is because there are `2^n` possible subsets of a set of `n` elements.

patterns_in_problem_solving:
  - Use **recursive backtracking** to explore all possible configurations.
  - Use **include-exclude** approach to handle each element's decision of inclusion or exclusion.
  - Leverage the **combination generation** approach where every subset is considered as a combination of elements, and recursion helps in systematically exploring these combinations.

additional_notes:
  - This problem can be extended to handle more complex constraints, such as allowing duplicate elements in `nums` (though in this specific problem, `nums` has distinct integers).
  - The recursive backtracking pattern can be generalized to problems like generating permutations, combinations, and partitions of a set.



  // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


  class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&output, int index, vector<int>&nums)
    {
            if(index>=nums.size()) {  ans.push_back(output); return;    } 
            // including
                output.push_back(nums[index]);
                solve(ans,output,index+1,nums);
            //excluding 
                output.pop_back();
                solve(ans,output,index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(ans,output,0,nums);
        return ans;
    }
};
