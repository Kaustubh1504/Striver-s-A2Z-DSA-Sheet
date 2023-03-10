class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx=INT_MIN;

        for(auto c: s){
            if(c=='(') st.push(c);
            else if(c==')') st.pop();
            int cur = st.size();
            if(cur>mx) mx=cur;
        }

        return mx;
        
    }
};
