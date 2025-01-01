class Solution {
public:
    int maxScore(string s) {
        // The problem asks us to split the given binary string `s` into two non-empty parts.
        // Each part must contain at least one character.
        // The score for the split is calculated as:
        //   - The number of '0's in the left part
        //   - Plus the number of '1's in the right part.
        // Our task is to find the maximum score possible after splitting the string.

        int leftz = 0, leftone = 0;   // Count of zeros and ones in the left part
        int totalz = 0, totalone = 0; // Total number of zeros and ones in the entire string

        // Step 1: Count the total number of '0's and '1's in the string.
        for (char ch : s) {
            if (ch == '0') totalz++;   // Increment total zeros
            else totalone++;           // Increment total ones
        }

        int mx = 0; // Variable to store the maximum score

        // Step 2: Iterate through the string, stopping before the last character.
        // This ensures both parts of the split are non-empty.
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                leftz++; // Increment the count of zeros in the left part
            } else {
                leftone++; // Increment the count of ones in the left part
            }

            // Calculate the number of '1's in the right part
            int rightone = totalone - leftone;

            // Update the maximum score
            mx = max(mx, leftz + rightone);
        }

        // Step 3: Return the maximum score obtained
        return mx;
    }
};
