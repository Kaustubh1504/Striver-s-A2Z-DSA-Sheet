class Solution {
    public:
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        
        bool vis[15][15];

        void bfs(vector<pair<int,int>>source,vector<vector<int>>&grid,vector<vector<int>>& level){
            queue<pair<int,int>> q;
            
            for(auto s:source){
                int i=s.first;
                int j=s.second;
                vis[i][j]=true;
                q.push({i,j});
            }

            int m=grid.size();
            int n=grid[0].size();

           

            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                int curx=cur.first;
                int cury=cur.second;

                for(int i=0;i<4;i++){
                    int x = curx+dx[i];
                    int y = cury+dy[i];

                    if(x>=m||x<0||y>=n||y<0) continue;
                    if(grid[x][y]!=1) continue;
                    if(vis[x][y]==true) continue;

                    level[x][y]=level[curx][cury]+1;
                    grid[x][y]=2;
                    vis[x][y]=true;
                    q.push({x,y});
                }
            }
            
        }
        int orangesRotting(vector<vector<int>>& grid){

            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>> level(m+1,vector<int>(n+1,0));

            vector<pair<int,int>> source;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==2){
                        source.push_back({i,j});
                    }
                }
            }

            bfs(source,grid,level);


            // // bfs(0,0,grid);
            // for(int i=0;i<m;i++){
            //     for(int j=0;j<n;j++){
            //         // cout<<grid[i][j]<<" ";
            //         if(grid[i][j]==2 && vis[i][j]==false){
            //             bfs(i,j,grid,level);
            //         }
            //     }
            //     // cout<<endl;
            // }

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cout<<level[i][j]<<" ";
                }
                cout<<endl;
            }

            cout<<"------------------------------------------"<<endl;
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }



            int maxlevel=INT_MIN;
            bool allrotten=true;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    // cout<<level[i][j]<<" ";
                    if(grid[i][j]==1) allrotten=false;
                    maxlevel=max(maxlevel,level[i][j]);
                }
                // cout<<endl;
            }
            if(allrotten) return maxlevel;
            return -1;
        }

};


// class Solution {
// public:
//     bool vis[500][500];
//     int depth[500][500];
    
//     void dfs(int row,int column,int m,int n,vector<vector<int>>& arr){
      
//       vis[row][column]=true;

//       if((row+1)<m &&vis[row+1][column]==false && arr[row+1][column]==1){
//         vis[row+1][column]=true;
//         depth[row+1][column]=depth[row][column]+1;
//       	dfs(row+1,column,m,n,arr);
//       }
//       if((row-1)>=0 && vis[row-1][column]==false  && arr[row-1][column]==1){
//          vis[row-1][column]=true;
//         depth[row-1][column]=depth[row][column]+1;
//       	dfs(row-1,column,m,n,arr);
//       }
//       if((column+1)<n&&vis[row][column+1]==false  && arr[row][column+1]==1){
//          vis[row][column+1]=true;
//         depth[row][column+1]=depth[row][column]+1;
//       	dfs(row,column+1,m,n,arr);
//       }
//       if((column-1)>=0&& vis[row][column-1]==false  && arr[row][column-1]==1){
//          vis[row][column-1]=true;
//         depth[row][column-1]=depth[row][column]+1;
//       	dfs(row,column-1,m,n,arr);
//       }

// }
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         memset(vis,0,sizeof(vis));
//         dfs(0,0,m,n,grid);
//         for(int i=0;i<n;i++){
//           for(int j=0;j<n;j++)cout<<vis[i][j]<<" ";
//           cout<<endl;
//         }
        
//         cout<<endl<<"depth\n";
//         for(int i=0;i<n;i++){
//           for(int j=0;j<n;j++)cout<<depth[i][j]<<" ";
//           cout<<endl;
//         }
      
//         return -1;
//     }
// };
