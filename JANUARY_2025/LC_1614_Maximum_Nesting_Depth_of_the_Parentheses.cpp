class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int mx=0;
        for(char ch:s)
        {
            if(ch=='('){ st.push(ch);    mx=max(mx,(int)st.size());   }
            if(ch==')'){     st.pop();    }

        }
return mx;
    }
};
