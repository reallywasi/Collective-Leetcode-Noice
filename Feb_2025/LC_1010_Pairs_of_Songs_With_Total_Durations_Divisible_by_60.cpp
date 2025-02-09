class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>remcnt;

        for(int & i: time) i=i%60;
int cnt=0;
        for(int i:time)
        {
            int compliment=(60-i)%60;
            cnt=cnt+remcnt[compliment];
            remcnt[i]++;
        }
        return cnt;
    }
};
