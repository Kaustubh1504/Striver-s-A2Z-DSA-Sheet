//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dijikstra(int n,vector<pair<int,int>> g[]){
        const int INF = 1e10;
        const int M = 1e9+7;
        vector<int> dist(n+1,INF);
        vector<int> ways(n+1,0);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        dist[0]=0;
        ways[0]=1;
        
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            int dis = cur.first;
            int cur_n = cur.second;
            
            for(auto child:g[cur_n]){
                int child_wt = child.second;
                int child_n = child.first;
                
                if(dis+child_wt<dist[child_n]){
                    dist[child_n]=(dis+child_wt)%M;
                    q.push({dist[child_n],child_n});
                    //inherit ways from parent node
                    ways[child_n]=ways[cur_n]%M;
                }else if(dis+child_wt==dist[child_n]){
                    //if we get the same minimum distance increament the way of child node
                    ways[child_n]=(ways[child_n]+ways[cur_n])%M;
                }
            }
        }
        
        return ways[n-1]%M;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        const int M = 1e9+7;
        vector<pair<int,int>> g[n+1];
        for(auto edge:roads){
            int x=edge[0];
            int y=edge[1];
            int wt=edge[2]%M;
            g[x].push_back({y,wt});
            g[y].push_back({x,wt});
        }
        
        int ans = dijikstra(n,g);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
