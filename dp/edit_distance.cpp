class Solution {
public:
    int func(int i,int j,string word1,string word2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=0+func(i-1,j-1,word1,word2,dp);
        }
        int insert = func(i,j-1,word1,word2,dp)+1;
        int del = func(i-1,j,word1,word2,dp)+1;
        int replace = func(i-1,j-1,word1,word2,dp)+1;

        return dp[i][j]=min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) {
        /*
            string matching using recursion
            f(i,j) { --> returns the steps word1[0....i] to word2[0......j]

                if(word1[i]==word2[j]) return 0 + f(i-1,j-1); // no operations

                insert = func(i,j-1)+1;
                delete = func(i-1,j)+1;
                replace = func(i-1,j-1)+1;

                return min(insert,delete,replace);
                

            }
        */
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int j=1;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++) dp[i][0]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1]){
                         dp[i][j]=0+dp[i-1][j-1];
                    }else{
                        int insert = dp[i][j-1]+1;
                        int del = dp[i-1][j]+1;
                        int replace = dp[i-1][j-1]+1;

                        dp[i][j]=min(insert,min(del,replace));

                    }
                    
            }
        }
        

        // return func(n-1,m-1,word1,word2,dp);
        return dp[n][m];
    }
};
