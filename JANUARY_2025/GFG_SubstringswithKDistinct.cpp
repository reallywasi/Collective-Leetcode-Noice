class Solution {
public:
    int countSubstr(string& s, int k) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> distinctChars; // To track distinct characters
            int distinctCount = 0;

            for (int j = i; j < n; j++) {
                if (distinctChars.find(s[j]) == distinctChars.end()) {
                    distinctChars.insert(s[j]);
                    distinctCount++;
                }

                // If we have exactly k distinct characters, count the substring
                if (distinctCount == k) cnt++;
                // If distinct characters exceed k, break early
                if (distinctCount > k) break;
            }
        }

        return cnt;
    }
};
