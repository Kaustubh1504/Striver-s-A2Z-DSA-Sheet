class Solution {
public:
    int cnt=0;
    bool vis[505][505];
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>>& grid){
        vis[i][j]=true;
        grid[i][j]=0;
        cnt++;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=grid.size()||nx<0||ny>=grid[0].size()||ny<0) continue;
            if(vis[nx][ny]==true) continue;
            if(grid[nx][ny]!=1) continue;
            dfs(nx,ny,grid);
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //first row
        for(int j=0;j<m;j++){
            if(vis[0][j]==false && grid[0][j]==1) dfs(0,j,grid);
        }

        for(int i=0;i<n;i++){
            if(vis[i][m-1]==false && grid[i][m-1]==1) dfs(i,m-1,grid);
        }

        for(int j=m-1;j>=0;j--){
            if(vis[n-1][j]==false && grid[n-1][j]==1) dfs(n-1,j,grid);
        }

        for(int i=0;i<n;i++){
            if(vis[i][0]==false&& grid[i][0]) dfs(i,0,grid);
        }

        //  for (auto i = 0; i < A.size(); ++i)
        //         for (auto j = 0; j < A[0].size(); ++j) 
        //             if (i * j == 0 || i == A.size() - 1 || j == A[i].size() - 1) dfs( i, j,A);

        // dfs(0,1,A);
        int ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1) ones++;
            }
            // cout<<endl;
        }


        return ones;
    }
};
