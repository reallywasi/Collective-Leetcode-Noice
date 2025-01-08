class Solution {
public:
    bool isPrefixSuffix(string &s1, string &s2) {
        if (s1.size() == s2.size()) {
            return s1 == s2;  // Both are equal, not valid as a prefix-suffix pair
        }
        // Check if s1 is a prefix of s2
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) return false;
        }

        // Check if s1 is a suffix of s2
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[n - 1 - i] != s2[s2.size() - 1 - i]) return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (i != j && isPrefixSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};
