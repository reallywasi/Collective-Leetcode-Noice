class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;

        // Count the frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Create a vector of pairs to store the frequency and the corresponding character
        vector<pair<int, char>> p;
        for (auto t : freq) {
            p.push_back({t.second, t.first});
        }

        // Sort the vector based on frequency in descending order using greater<int>
        sort(p.begin(), p.end(), greater<pair<int, char>>());

        // Build the result string
        string result = "";
        for (auto t : p) {
            result += string(t.first, t.second);  // Repeat the character t.first times
        }

        return result;
    }
};
