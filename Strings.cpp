
______________________________________________________________________________________________________________________________
##############################################################################################################################
______________________________________________________________________________________________________________________________


1. Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.


  ____________________________________________________________________________________________________________________

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        vector<string>x(words.size());
        copy(words.begin(),words.end(),x.begin());

        for(int i=0;i<words.size();i++)
        {
            reverse(x[i].begin(),x[i].end());
        }
        for(int i=0;i<words.size();i++)
        {
if(x[i]==words[i])
{
    return words[i];
}
        }
        return "";
    }
};
______________________________________________________________________________________________________________________________
##############################################################################################################################
______________________________________________________________________________________________________________________________

