class Solution {
public:
    int dijisktra(vector<vector<int>>& heights){
        int n = heights.size();
        int m=heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        // vector<vector<bool>> vis(n,vector<bool>(m,false));

        priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        // vis[0][0]=true;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        int ans=INT_MAX;

        while(!pq.empty()){
            int diff=pq.top().first;
            int curx=pq.top().second.first;
            int cury=pq.top().second.second;
            pq.pop();

            if(curx==n-1 && cury==m-1) ans=min(ans,diff);

            for(int i=0;i<4;i++){
                int nx=curx+dx[i];
                int ny=cury+dy[i];

                if(nx>=n || nx<0 || ny>=m || ny<0) continue;
                int neweffort=max(diff,abs(heights[curx][cury]-heights[nx][ny]));
                // if(neweffort>dis[nx][ny]) continue;
                // if(vis[nx][ny]==true) continue;

                // dis[nx][ny]=neweffort;
                // pq.push({neweffort,{nx,ny}});
                // vis[nx][ny]=true;
                if (neweffort < dis[nx][ny])
                    {
                        dis[nx][ny] = neweffort;
                        pq.push({neweffort, {nx, ny}});
                }
            }


        }

        return ans;



    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijisktra(heights);
    }
};
