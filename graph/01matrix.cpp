 void bfs(vector<pair<int,int>>&sources,vector<vector<int>>& mat,vector<vector<int>> &level,vector<vector<bool>> &vis){
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        for(auto p:sources){
            q.push({p.first,p.second});
            vis[p.first][p.second]=true;
        }
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};

        while(!q.empty()){
            auto cur= q.front();
            q.pop();
            int cur_x= cur.first;
            int cur_y = cur.second;

            for(int i=0;i<4;i++){
                int nx= cur_x+dx[i];
                int ny = cur_y+ dy[i];
                if(nx>=n || nx<0 || ny>=m || ny<0) continue;
                if(mat[nx][ny]==0) continue;
                if(vis[nx][ny]==true) continue;

                q.push({nx,ny});
                level[nx][ny]=level[cur_x][cur_y]+1;
                vis[nx][ny] = true;
            }

        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> sources;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) sources.push_back({i,j});
            }
        }
        vector<vector<int>> level(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        bfs(sources,mat,level,vis);
        return level;
    }
