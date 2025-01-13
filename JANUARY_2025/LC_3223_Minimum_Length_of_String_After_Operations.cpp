class Solution {
public:
    int minimumLength(string s) {
        map<char,int>m;

        for(char ch:s)  m[ch]++;
int cnt=0;
        for(auto & p : m)
        {
while(p.second>2)
{
    p.second-=2;
}
cnt+=p.second;
        }
        return cnt;
    }
};
