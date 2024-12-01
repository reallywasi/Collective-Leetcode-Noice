// Question: 
// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
// If there are multiple valid strings, return any of them.
// A string S is a subsequence of a string T if deleting some (or no) characters from T results in the string S.

//----------------------------------------

// Approach:
// 1. Use Dynamic Programming to calculate the length of the Longest Common Subsequence (LCS) of str1 and str2.
// 2. Create a DP table to store the LCS length for all substrings of str1 and str2.
// 3. Trace back from the DP table to construct the shortest common supersequence (SCS):
//    - If characters from str1 and str2 match, add it to the result and move diagonally up-left in the DP table.
//    - If they don't match, add the character from the string with the larger DP value and move accordingly.
// 4. If any characters remain in either string after reaching the start of one, add them to the result.
// 5. Reverse the constructed string to get the SCS.

//----------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize the DP table
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Construct the shortest common supersequence
        string ans = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters from str1 or str2
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        // Reverse the result to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//----------------------------------------

// Test Cases:
// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: Both "cabac" and "ababc" are valid answers, but "cabac" is returned here.

// Input: str1 = "geek", str2 = "eke"
// Output: "geeke"
// Explanation: "geeke" is the shortest string containing both "geek" and "eke" as subsequences.

// Input: str1 = "abc", str2 = "def"
// Output: "abcdef"
// Explanation: Since there is no common subsequence, concatenate both strings.

//----------------------------------------

// Example Usage:
int main() {
    Solution solution;
    string str1 = "abac";
    string str2 = "cab";
    cout << "Shortest Common Supersequence: " << solution.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}
