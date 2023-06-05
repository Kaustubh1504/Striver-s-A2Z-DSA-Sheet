class Solution {
public:
    vector<int> g[201];
    bool vis[201];
    void dfs(int v){
        vis[v]=true;
        for(auto child: g[v]){
            if(vis[child]==true) continue;
            dfs(child);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        memset(vis,0,sizeof(vis));
        int n = sizeof(g)/sizeof(g[0]);
        for(int i=0;i<n;i++) g[i].clear();

        for(int i=0;i<adj.size();i++){
            for(int j =0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    g[i+1].push_back(j+1);
                }
            }
        }

        int ans=0;
        for(int i=1;i<=adj.size();i++){
            if(vis[i]==true) continue;
            ans++;
            dfs(i);
        }

        return ans;
    }
};
