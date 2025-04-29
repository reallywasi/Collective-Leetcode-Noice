
class Solution {
  public:
    int longestKSubstr(string &s, int k) {

unordered_map<char,int>freq;

int l=0;
int r=0;
int length=-1;
while(r<s.size()){     
     freq[s[r]]++;
     
     while(freq.size()>k && r<s.size())
     {
         freq[s[l]]--;
         if(freq[s[l]]==0) freq.erase(s[l]);
    l++;
     }
     if(freq.size()==k) length=max(length,r-l+1);
     r++;
}
     return length;


    }
};
