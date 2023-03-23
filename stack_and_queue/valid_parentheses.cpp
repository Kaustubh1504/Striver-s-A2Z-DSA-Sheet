class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s[0]==')' || s[0]==']' || s[0]=='}') return false; 
        bool ans=true;
        for(auto c: s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{

                if(st.empty()==false){
                     char last = st.top();
                    if(c==')' && last=='(') st.pop();
                    else if(c==']' && last=='[') st.pop();
                    else if(c=='}' && last =='{') st.pop();
                    else{
                        ans=false;
                        break;
                    }

                }else{
                    ans=false;
                    break;
                }
               
            }
        }

        if(st.empty()==false) ans=false;
        // if(st.size()!=0) ans=false;

        return ans;
        
    }
};
