//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        /*
          apply topo sort using kahns alorithm bfs 
          if size of topo sort is less than V cycle is present
        */
        
        vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(auto child:adj[i]){
                indegree[child]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            
            topo.push_back(cur);
            
            for(auto child:adj[cur]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }
        
        if(topo.size()==V) return false;
        return true;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
