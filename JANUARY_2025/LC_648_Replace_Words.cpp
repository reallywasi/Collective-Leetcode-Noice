// class Solution {
// public:


// string solve(string &word,unordered_set<string>&st)
// {
// for(int l=0;l<word.size();l++)
// {
// if(st.find(word.substr(0,l))!=st.end()) return word.substr(0,l);
// }
// return word;
// }
//     string replaceWords(vector<string>& dictionary, string sentence) {
        
//         string word;

//         unordered_set<string>st(dictionary.begin(),dictionary.end());

//         stringstream ss(sentence);
// string result="";
//         while(getline(ss,word,' '))
//         {
//          result=result+solve(word,st)+" ";
//         }

// result.pop_back();
// return result;
//     }
// };












class Solution {
public:

    string findRoot(string& word, unordered_set<string>& st) {

        //try all length substring starting from 0th index
        for(int l = 1; l <= word.length(); l++) {
            string root = word.substr(0, l);
            if(st.count(root)) {
                return root;
            }
        }

        return word;

    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string result;

        while(getline(ss, word, ' ')) {
            result += findRoot(word, st) + " ";
        }

        result.pop_back();
        return result;

    }
};
