/*
Problem Statement:
Given two strings, s1 and s2, we are tasked with finding the longest common substring between the two strings.
A substring is a contiguous sequence of characters within a string. The goal is to return all the longest common substrings that appear in both strings.

Example:
Input:
    s1 = "abcd"
    s2 = "abzd"
Output:
    ["ab"]

Explanation:
The longest common substring between "abcd" and "abzd" is "ab". This substring is present in both strings.

Approach:
1. Use dynamic programming (DP) to find the longest common substrings.
2. Create a 2D DP table, dp[i][j], where dp[i][j] represents the length of the longest common suffix of substrings s1[0..i-1] and s2[0..j-1].
3. If characters s1[i-1] and s2[j-1] match, increment the length of the common substring from the previous substring.
4. Track the maximum length of common substrings found during the iteration.
5. Once the table is populated, extract all substrings of maximum length from the string s1 using the recorded positions.
*/




#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        int maxdp = 0;
        
        // DP table to store lengths of longest common suffixes
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // To store the ending positions of the longest substrings in s1
        vector<int> max_positions;
        
        // Fill DP table
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {
                if (s1[i1 - 1] == s2[i2 - 1]) {
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                    if (dp[i1][i2] > maxdp) {
                        maxdp = dp[i1][i2];
                        max_positions.clear();
                        max_positions.push_back(i1); // Store position in s1
                    } else if (dp[i1][i2] == maxdp) {
                        max_positions.push_back(i1); // Store position in s1
                    }
                } else {
                    dp[i1][i2] = 0;
                }
            }
        }
        
        // Collect all the substrings from the recorded positions
        vector<string> result;
        for (int i1 : max_positions) {
            result.push_back(s1.substr(i1 - maxdp, maxdp));
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string s1 = "abcd";
    string s2 = "abzd";
    
    vector<string> result = solution.longestCommonSubstr(s1, s2);
    
    cout << "Longest Common Substrings: " << endl;
    for (const string& substr : result) {
        cout << substr << endl;
    }
    
    return 0;
}
