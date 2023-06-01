class Solution {
public:
     vector<string> allsub;
	 void generate(int ind,string& sub,string s){
        
         if(ind<0) {
             allsub.push_back(sub);
             return;
         }

         generate(ind-1,sub,s);

         sub.push_back(s[ind]);
         generate(ind-1,sub,s);
         sub.pop_back();
     }
     /*
     bbbab
     babbb

     cbbd
     dbbc
     */
    int longestPalindromeSubseq(string s) {
        // int n = s.size();
        // string sub="";
        // generate(n-1,sub,s);
        // for(auto c:allsub ) cout<<c<<" ";
        // cout<<allsub.size();
        // return 0;
        int n=s.size();
        int m=n;
        string text1=s;
        string text2=s;
        reverse(text2.begin(),text2.end());
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
