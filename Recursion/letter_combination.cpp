class Solution {
public:
    vector<string> dchar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

    // void generate
    // a b c
    // d e f
    // t u v

    void generate(int i,string cur,vector<string> mat){

        if(i==mat.size()){
            if(!cur.empty()) ans.push_back(cur);
            return;
        }
        
        for(int k=0;k<mat[i].size();k++){
            cur.push_back(mat[i][k]);
            generate(i+1,cur,mat);
            cur.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> curchars;

        for(auto c: digits){
            int d = c-'0';
            curchars.push_back(dchar[d]);
        }

        for(auto c: curchars) cout<<c<<endl;

        generate(0,"",curchars);

        return ans;
    }
};
