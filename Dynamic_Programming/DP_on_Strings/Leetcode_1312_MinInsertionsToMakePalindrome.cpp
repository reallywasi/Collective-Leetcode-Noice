// Leetcode Problem 1312: Minimum Insertion Steps to Make a String Palindrome
// File name: MinInsertionsToMakePalindrome.cpp

// Problem Statement:
// Given a string `s`, you need to return the minimum number of insertions required to make the string a palindrome.
// A palindrome is a string that reads the same forward and backward. The goal is to find the minimum number of insertions needed to 
// transform the given string into a palindrome by inserting characters into it.

// -----------------------------------------
// Approach:
// To solve this problem, we can utilize dynamic programming. The idea is to compute the **Longest Palindromic Subsequence** (LPS) of the string, 
// which is the longest sequence of characters that can be found in the string and read the same in both directions. 
// Once we find the LPS, the minimum insertions required will be the difference between the length of the string and the length of the LPS.

// Key Observations:
// 1. **Longest Palindromic Subsequence (LPS)**: If we can find the longest palindromic subsequence of the string, 
//    then the remaining characters will need to be inserted to make the string a palindrome.
// 2. **Relation with Longest Common Subsequence (LCS)**: The LPS of a string `s` is the same as the **Longest Common Subsequence** (LCS) 
//    between the string `s` and its reverse `revs`. This is because the characters of the LPS will appear in both `s` and `revs`, 
//    making it a common subsequence.

// Plan:
// 1. Reverse the string `s` to get `revs`.
// 2. Compute the **Longest Common Subsequence** (LCS) between `s` and `revs`.
// 3. The length of the **Longest Palindromic Subsequence** (LPS) is equal to the LCS of `s` and `revs`.
// 4. The minimum number of insertions required to make the string a palindrome = `n - LPS`, where `n` is the length of the string `s`.

// -----------------------------------------

class Solution {
public:
    int minInsertions(string s) {
        // Step 1: Reverse the string `s` to get `revs`
        string revs = s;             // Create a copy of the original string
        reverse(revs.begin(), revs.end());  // Reverse the string in-place
        
        int n = s.size();  // Get the length of the original string
        
        // Step 2: Initialize the DP table where dp[i][j] will store the length
        // of the longest common subsequence of s[0...i-1] and revs[0...j-1].
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));  // Create DP table
        
        // Step 3: Fill the DP table using bottom-up approach
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                if (s[i1 - 1] == revs[i2 - 1]) {
                    // If characters match, the length of the LCS increases by 1
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                } else {
                    // If characters don't match, take the maximum value from the previous row or column
                    dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
                }
            }
        }

        // Step 4: The length of the longest palindromic subsequence is found in dp[n][n].
        int LPS = dp[n][n];
        
        // Step 5: The minimum insertions required to make the string a palindrome is:
        return n - LPS;
    }
};

// -----------------------------------------
// Example Test Case:

// Test case 1:
string s = "abcda";  // Input string
Solution sol;
int result = sol.minInsertions(s);  // Output: 1
cout << "Minimum insertions required: " << result << endl;
// Explanation:
// Reverse of "abcda" is "adcba". The longest palindromic subsequence (LPS) is "abcd", which has a length of 4.
// The minimum insertions required = 5 (length of "abcda") - 4 (LPS length) = 1.

// -----------------------------------------

// Test case 2:
s = "abca";  // Input string
result = sol.minInsertions(s);  // Output: 1
cout << "Minimum insertions required: " << result << endl;
// Explanation:
// Reverse of "abca" is "acba". The longest palindromic subsequence (LPS) is "aba", which has a length of 3.
// The minimum insertions required = 4 (length of "abca") - 3 (LPS length) = 1.

// -----------------------------------------

// Test case 3:
s = "abc";  // Input string
result = sol.minInsertions(s);  // Output: 2
cout << "Minimum insertions required: " << result << endl;
// Explanation:
// Reverse of "abc" is "cba". The longest palindromic subsequence (LPS) is "a" or "b" or "c", which has a length of 1.
// The minimum insertions required = 3 (length of "abc") - 1 (LPS length) = 2.
