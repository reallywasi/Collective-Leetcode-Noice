
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
      unordered_set<int> uniq(nums.begin(), nums.end());
        int total = uniq.size();    int n=nums.size();
unordered_map<int,int>curr;
        int l=0;  int cnt=0;     int r=0;
        for(int r=0;r<n;r++)
        {
            curr[nums[r]]++;
            while(curr.size()==total)
            {
                             cnt+=n-r;
                curr[nums[l]]--;
                if(curr[nums[l]]==0) curr.erase(nums[l]);
                l++;
            }
        }
        return cnt;
    }
};


// class Solution {
// public:
//     long long countCompleteSubarrays(vector<int>& nums)   // ① cnt must be long long
//     {
//         unordered_map<int,int> freq;          // counts distinct elements in whole array
//         for (int x : nums) freq[x];           // just touch each key once
//         int total = freq.size();

//         int n = nums.size();
//         unordered_map<int,int> curr;          // window frequencies
//         int l = 0;
//         long long cnt = 0;                    // ①  ← same type as return value

//         for (int r = 0; r < n; ++r) {
//             ++curr[nums[r]];                  // add right end

//             if (curr.size() == total) cnt += n - r;

//             while (curr.size() == total) {
//                 if (--curr[nums[l]] == 0)     // ② erase key when count hits 0
//                     curr.erase(nums[l]);      // ② ← one‑line fix
//                 ++l;
//             }
//         }
//         return cnt;
//     }
// };




