#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Problem: Find the length of the longest palindromic subsequence in a string.

Approach:
1. Reverse the given string `s` to obtain `rev_s`.
2. Compute the Longest Common Subsequence (LCS) between the string `s` and its reverse `rev_s`.
   - The LCS between `s` and `rev_s` will give us the longest palindromic subsequence of `s`.
3. Return the length of the LCS.

This is because a palindromic subsequence is a sequence that reads the same forward and backward. The longest common subsequence between `s` and `rev_s` is the longest sequence that appears in both `s` and `rev_s`, which inherently forms a palindrome.
*/

class Solution {
public:
    // Function to find the length of the longest palindromic subsequence
    int longestPalindromicSubseq(string& s) {
        // Step 1: Reverse the string to get its reverse
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        int n = s.size(); // Length of the original string
        int m = rev_s.size(); // Length of the reversed string
        
        // Step 2: Initialize the DP table to store LCS lengths
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Step 3: Fill the DP table to compute the LCS of s and rev_s
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == rev_s[j - 1]) {
                    // Characters match, so the LCS length increases
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // No match, take the maximum LCS length from the previous row or column
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Step 4: The value at dp[n][m] gives the length of the LCS, which is the length of the longest palindromic subsequence
        return dp[n][m];
    }
};

int main() {
    Solution solution;
    
    // Test case: Example input string
    string s = "bbabcbcab"; 
    
    // Compute the length of the longest palindromic subsequence
    int result = solution.longestPalindromicSubseq(s);
    
    // Output the result
    cout << "Length of Longest Palindromic Subsequence: " << result << endl;
    
    return 0;
}
