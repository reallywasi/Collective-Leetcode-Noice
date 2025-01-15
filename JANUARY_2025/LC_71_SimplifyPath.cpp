class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
stack<string>st;
string token;
        while(getline(ss,token,'/')){
            if(token=="." || token=="") continue;
            if(token==".."){       if(!st.empty())  st.pop();  }
            else{ st.push(token);
            }
        }
    if(st.empty()) return "/";
string ans="";
    while(!st.empty()){
ans="/"+st.top()+ans;
st.pop();
    }
    return ans;
    }
};
