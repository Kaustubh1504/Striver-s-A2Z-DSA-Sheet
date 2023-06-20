class Solution {
public:
    bool ismatch(int i,int j,string str,string pattern,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false; // pattern is over and string is still left
        if(i>=0 && j<0) {
            //pattern is still left and str is over
            // so all the charecters should be *=>(null)
            for(int k=0;k<=i;k++){
                if(pattern[k]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(pattern[i]==str[j] || pattern[i]=='?'){
            return dp[i][j]=ismatch(i-1,j-1,str,pattern,dp);
        }else if(pattern[i]=='*'){
            bool starisnull = ismatch(i-1,j,str,pattern,dp);
            bool matchcharwithstar = ismatch(i,j-1,str,pattern,dp);
            return dp[i][j]=starisnull || matchcharwithstar;
        }else{
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // bool ans = ismatch(n-1,m-1,s,p,dp);
        // return ans;
        
    }
};
