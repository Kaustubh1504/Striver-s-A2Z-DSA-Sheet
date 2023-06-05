//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    static const int N = 1e5+10;
    bool vis[N];
    bool dfs(int v,int par,vector<int> g[]){
        vis[v]=true;
        bool isloopexits=false;
        for(auto child: g[v]){
            if(child==par) continue;
            if(vis[child]==true) return true;
            isloopexits|=dfs(child,v,g);
        }
        
        return isloopexits;
    }
    bool isCycle(int V, vector<int> g[]) {
        // Code here
        bool ans=false;
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<V;i++){
            if(vis[i]==true) continue;
            ans|=dfs(i,0,g);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
