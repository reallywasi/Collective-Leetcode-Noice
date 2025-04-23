problem:
  name: "Number of Substrings Containing All Three Characters"
  id: 1358
  difficulty: Medium
  input: 
    - A string `s` consisting only of characters 'a', 'b', and 'c'
  output: 
- Count of substrings that contain at least one 'a', one 'b', and one 'c'


//===============================================================================================================

approach:
  strategy: "Sliding Window"
  description: |
    We use a two-pointer approach with a sliding window. 
    The idea is to expand the right end of the window until it contains all three characters ('a', 'b', and 'c'), 
    then shrink the left end while still maintaining all three characters, counting all such substrings efficiently.

  why_sliding_window: |
    Since we only care about substrings that contain all three characters and we want to do it in linear time,
    we maintain a frequency count of 'a', 'b', and 'c' in the current window and adjust the window size using two pointers:
    `l` (left) and `r` (right).


//===============================================================================================================


  variables:
    freq: 
      type: array of size 3
      description: "Stores frequency of 'a', 'b', and 'c' in the current window."
    l: 
      description: "Left pointer of the sliding window"
    r: 
      description: "Right pointer of the sliding window"
    cnt:
      description: "Total count of valid substrings"


//===============================================================================================================


code_logic:
  loop:
    iterate_r: 
      description: "Move right pointer from 0 to n-1"
      action: "Increment character frequency for s[r]"
  window_check:
    condition: "If all characters (a, b, c) are present in the window (freq[0], freq[1], freq[2] > 0)"
    count_substrings:
      expression: "cnt += n - r"
      explanation: |
        Once the current window has all three characters, any substring that:
        - Starts from index `l` (left pointer)
        - Ends at any position from `r` to `n-1`
        will also contain all three characters.
        
        Thus, number of such substrings is:
        - (r to n-1) inclusive → Total = n - r

        Instead of manually iterating over all possible right ends, 
        we add all of them in one step using `cnt += n - r`.

  shrink_window:
    while_valid_window: 
      description: "While the window still contains all three characters"
      action:
        - count substrings: "cnt += n - r"
        - shrink window: "freq[s[l] - 'a']--; l++"

//===============================================================================================================

dry_run:
  input: "abcabc"
  steps:
    - r = 0 -> s[r] = 'a'; freq = [1, 0, 0]
    - r = 1 -> s[r] = 'b'; freq = [1, 1, 0]
    - r = 2 -> s[r] = 'c'; freq = [1, 1, 1]; All present
      - Valid window [l=0, r=2]
      - Substrings: "abc", "abca", "abcab", "abcabc"
      - cnt += 6 - 2 = 4
      - freq['a']--; l++
    - l = 1 -> freq = [0, 1, 1]; Window invalid
    - r = 3 -> s[r] = 'a'; freq = [1, 1, 1]; All present again
      - Valid window [l=1, r=3]
      - cnt += 6 - 3 = 3 → substrings: "bca", "bcab", "bcabc"
      - freq['b']--; l++
    - l = 2 -> freq = [1, 0, 1]; Window invalid
    - r = 4 -> s[r] = 'b'; freq = [1, 1, 1]; Valid
      - cnt += 6 - 4 = 2 → substrings: "cab", "cabc"
      - freq['c']--; l++
    - r = 5 -> s[r] = 'c'; freq = [1, 1, 1]; Valid
      - cnt += 6 - 5 = 1 → substring: "abc"
      - freq['a']--; l++

  total_count: 10

//===============================================================================================================
complexity:
  time: "O(n)"
  space: "O(1) - only uses a fixed size array for 3 characters"

key_takeaways:
  - Sliding window is used to reduce the time complexity from O(n^2) to O(n)
  - Instead of manually checking every substring, `cnt += n - r` adds all valid substrings in constant time
  - We efficiently shrink the window using the left pointer while maintaining validity




//===============================================================================================================

//===============================================================================================================





class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>freq(3,0);
int l=0;
int n=s.size();
int cnt=0;
        for(int r=0;r<n;r++)
        {
freq[s[r]-'a']++;

while((freq[0]>0 && freq[1]>0 && freq[2])>0)
{
    cnt+=n-r;
    freq[s[l]-'a']--;
    l++;
}
        }
        return cnt;
    }
};
