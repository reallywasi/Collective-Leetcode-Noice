/*
//________________________________________________________________________________________________

Problem Description:
You are given a string `s` and an array of integers `spaces` that specify positions in the string 
where spaces need to be inserted. The `spaces` array is 0-based indexed, and the positions are in 
increasing order. Insert the spaces into the string `s` and return the resulting string.

Example:
Input:
s = "leetcodeisawesome"
spaces = [8, 11, 15]
Output:
"leetcode is awesome"

Explanation:
Spaces are added at indices 8, 11, and 15, resulting in the modified string:
"leetcode is awesome".

Constraints:
- 1 <= s.length <= 3 * 10^5
- 1 <= spaces.length <= 3 * 10^5
- spaces is a strictly increasing array of integers in the range [0, s.length - 1].
*/

//________________________________________________________________________________________________
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int spacesi = 0; // Pointer for the spaces array

        // Traverse the string `s`
        for (int i = 0; i < s.size(); i++) {
            // If the current index matches the next position in `spaces`, add a space
            if (spacesi < spaces.size() && spaces[spacesi] == i) {
                ans += ' ';
                spacesi++; // Move to the next space position
            }
            ans += s[i]; // Add the current character from the string
        }
        return ans;
    }
};
