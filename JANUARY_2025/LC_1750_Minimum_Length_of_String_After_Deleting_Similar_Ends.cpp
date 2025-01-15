class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r && s[l] == s[r]) {
            char ch = s[l];
            
            // Move the left pointer to the right, skipping characters equal to `ch`
            while (l <= r && s[l] == ch) {
                l++;
            }
            
            // Move the right pointer to the left, skipping characters equal to `ch`
            while (l <= r && s[r] == ch) {
                r--;
            }
        }

        return r - l + 1;
    }
};
