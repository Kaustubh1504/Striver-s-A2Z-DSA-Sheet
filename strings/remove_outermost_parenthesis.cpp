class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char> st;
        string ans="";

        for(auto c: s){

            if(!st.empty()) ans+=c;
            if(c=='(') st.push(c);
            else {
                 st.pop();
                 if(st.empty()) ans.pop_back();
            }
           
        }

        return ans;
        
    }
};
