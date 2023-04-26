class Solution {
public:
    int dp[105][105];
    int find(int x,int y,int m,int n){

        if(x<0 || x==m || y<0 || y==n) return 0;
        else if(x==m-1 && y==n-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        //way one
        int ans=find(x+1,y,m,n);

        //way two
        ans+=find(x,y+1,m,n);

        return dp[x][y]=ans;

    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        int ans=find(0,0,m,n);

        return ans;
    }
};
