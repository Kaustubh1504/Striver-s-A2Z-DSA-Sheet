class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string text1=s;
        string text2=s;
        reverse(text2.begin(),text2.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return n-dp[n][n];
    }
};
