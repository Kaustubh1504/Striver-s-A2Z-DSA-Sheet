class Solution {
public:
    int bfs2(vector<vector<int>>& grid){
        int n=grid.size();
        const int INF=1e9;
        vector<vector<int>> level(n,vector<int>(n,INF));
        vector<vector<bool>> vis(n,vector<bool>(n,0));

        if(grid[0][0]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        level[0][0]=1;
        vis[0][0]=true;

        int dx[]={1,-1,0,0,1,1,-1,-1};
        int dy[]={0,0,1,-1,1,-1,1,-1};

        while(!q.empty()){
            int curx=q.front().first;
            int cury=q.front().second;
            q.pop();

            for(int i=0;i<8;i++){
                int childx=curx+dx[i];
                int childy=cury+dy[i];

                if(childx>=n || childy>=n || childx<0 || childy<0) continue;
                if(grid[childx][childy]!=0) continue;
                if(level[curx][cury]+1>level[childx][childy]) continue;
                if(vis[childx][childy]==true) continue;

                level[childx][childy]=level[curx][cury]+1;
                q.push({childx,childy});
                vis[childx][childy]=true;
            }

        }

        // for(auto c: level){
        //     for(auto i: c) cout<<i<<" ";
        //     cout<<endl;
        // }

        return level[n-1][n-1];

    
         
    }









    int bfs(vector<vector<int>>& grid){
        int n=grid.size();
        vector<vector<int>> level(n,vector<int>(n,0));
        vector<vector<bool>> vis(n,vector<bool>(n,0));

        queue <pair<int,int>> q;
        q.push({0,0});
        vector<int> dx={-1,-1,1,1,1,-1,0,0};
        vector<int> dy={-1,1,-1,1,0,0,1,-1};

        while(!q.empty()){
            int curx=q.front().first;
            int cury=q.front().second;
            q.pop();

            //traverse on child
            for(int i=0;i<8;i++){
                int nx=curx+dx[i];
                int ny=cury+dy[i];
                if(nx>=n || ny>=n || nx<0 || ny<0) continue;
                if(grid[nx][ny]==1) continue;
                if(vis[nx][ny]==true) continue;
                if(level[curx][cury]+1<level[nx][ny]) continue;
             
                q.push({nx,ny});
                vis[nx][ny]=true;
                level[nx][ny]=level[curx][cury]+1;
            }

           
        }

        for(auto c: level){
            for(auto i: c) cout<<i<<" ";
            cout<<endl;
        }

        //  for(auto c: vis){
        //     for(auto i: c) cout<<i<<" ";
        //     cout<<endl;
        // }

         return level[n-1][n-1];

    }
    int dijisktra(vector<vector<int>>& grid){
        int n=grid.size();

        const int INF=1e9;
        vector<vector<int>> dis(n,vector<int>(n,INF));      
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        dis[0][0]=0;
        vector<int> dx={-1,-1,1,1,1,-1,0,0};
        vector<int> dy={-1,1,-1,1,0,0,1,-1};

        int steps=0;
        while(!pq.empty()){
            auto cur=pq.top();
            int x = cur.second.first;
            int y= cur.second.second;
            int cur_dis=cur.first;
            pq.pop();
            
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=n || ny>=n || nx<0 || ny<0) continue;

                if(cur_dis+grid[nx][ny]<dis[nx][ny]){
                    dis[nx][ny]=cur_dis+grid[nx][ny];
                    pq.push({1,{nx,ny}});
                }
            }


        }

        return dis[n-1][n-1];
        
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // return dijisktra(grid);
        int ans=bfs2(grid);
        if(ans==1e9) return -1;
        return ans;
    }
};
