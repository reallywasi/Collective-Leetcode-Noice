// 1539. Kth Missing Positive Number
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

 

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.


//=================================================================================================
//=================================================================================================

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxele=0;
        int n=arr.size();
        for(int i: arr)  maxele=max(maxele,i);
int j=0;
for(int i=1;i<=maxele;i++)
{
if(j<n && arr[j]==i) j++;
else { k--; } 
if(k==0) return i; 
}
return maxele+k;
    }
};
