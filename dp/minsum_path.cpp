class Solution {
public:
    int dp[205][205];
    /*
    1 3 1
    1 5 1
    4 2 1
    */
    int find(int x,int y,vector<vector<int>>& grid){

        if(dp[x][y]!=-1) return dp[x][y];
        if(x==0 && y==0) return grid[x][y];
        if(x==0) return grid[x][y]+find(x,y-1,grid);
        if(y==0) return grid[x][y]+find(x-1,y,grid);
        return dp[x][y]=min(grid[x][y]+find(x,y-1,grid),grid[x][y]+find(x-1,y,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans= find(m-1,n-1,grid);
        return ans;
    }
};
