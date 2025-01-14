class Solution {
public:
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>m;
        int n=A.size();
vector<int>ans(n,0);
     unordered_set<int>st;
     int cnt=0;
     for(int i=0;i<n;i++)
     {
        st.insert(B[i]);
        if(st.find(A[i])!=st.end()) cnt++;
        ans[i]=cnt;
     }
cnt=0;
st.clear();
        for(int i=0;i<n;i++)
     {
        st.insert(A[i]);
        if(st.find(B[i])!=st.end()) cnt++;
        ans[i]+=cnt;
     }

return ans;
    }
};




// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         set<int>st;
//         int n=A.size();
//         vector<int>ans(n);
//         for(int i=0;i<n;i++) {
//             st.insert(A[i]);
//             st.insert(B[i]);
// ans[i]=2*(i+1)-st.size();
//         }
//         return ans;
//     }
// };
