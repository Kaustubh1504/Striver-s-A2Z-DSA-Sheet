class Solution {
public:
    int dp[105][105];
    int find(int x,int y,int m,int n,vector<vector<int>>& obstacleGrid){

        if(x<0 || x==m || y<0 || y==n) return 0;
        if(obstacleGrid[x][y]==1) return 0;
        if(x==m-1 && y==n-1) return 1;
        
        if(dp[x][y]!=-1) return dp[x][y];
        //way one
        int ans=find(x+1,y,m,n,obstacleGrid);

        //way two
        ans+=find(x,y+1,m,n,obstacleGrid);

        return dp[x][y]=ans;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int ans=find(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid);

        return ans;
    }
};
