class Solution {
public:
    vector<string> valid;
    vector<string> generateParenthesis(int n) {
        string sub="";
        generate(sub,n,n);

        return valid;
    }
    void generate(string sub,int open,int close){
        
        if(open==0 && close==0){
            valid.push_back(sub);
            return;
        }


        if(open>0){
            sub.push_back('(');
            generate(sub,open-1,close);
            sub.pop_back();
        }

        if(close>0){
            if(open<close){
                sub.push_back(')');
                generate(sub,open,close-1);
                sub.pop_back();
            }
        }
    }
};
