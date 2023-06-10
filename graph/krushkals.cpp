//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjointset{
   vector<int> rank,par,size;
   public:
   	Disjointset(int n){
   		rank.resize(n+1,0);
   		par.resize(n+1,0);
   		size.resize(n+1,0);

   		for(int i=0;i<=n;i++) {
   			par[i]=i;
   			size[i]=1;
   		}
   	}

    int findParent(int v){
    	if(par[v]==v) return v;
    	return par[v]=findParent(par[v]);
    }

    void unionByRank(int u,int v){
    	int ulp_u = findParent(u);
    	int ulp_v= findParent(v);

    	if(ulp_u==ulp_v) return;

    	if(rank[ulp_u]<rank[ulp_v]){
    		par[ulp_u]=ulp_v;
    	}else if(rank[ulp_v]<rank[ulp_u]){
    		par[ulp_v]=ulp_u;
    	}else{
    		par[ulp_v]=ulp_u;
    		rank[ulp_u]++;
    	}
    }

    void unionBySize(int u,int v){
    	int ulp_u = findParent(u);
    	int ulp_v= findParent(v);

    	if(ulp_u==ulp_v) return;

    	if(size[ulp_u]<size[ulp_v]){
    		par[ulp_u]=ulp_v;
    		size[ulp_v]+=size[ulp_u];
    	}else{
    		par[ulp_v]=ulp_u;
    		size[ulp_u]+=size[ulp_v];
    	}
    }
};
class Solution
{
	public:
	int prims(int V, vector<vector<int>> g[]){
	    
	    vector<bool> vis(V,0);
	    vector<pair<int,int>> mst;
	    int sum=0;
	    
	    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	    //{wt,{node,par}}
	    q.push({0,{0,-1}});
	    
	    while(!q.empty()){
	        int curn=q.top().second.first;
	        int par=q.top().second.second;
	        int wt=q.top().first;
	        q.pop();
	        
	       // cout<<curn<<" "<<par<<endl;
	        if(vis[curn]==true) continue;
	        vis[curn]=true;
	        sum+=wt;
	        
	        if(par!=-1){
	            mst.push_back({curn,par});
	        }
	       //mst.push_back({curn,par});
	        
	        for(auto child:g[curn]){
	            int child_n=child[0];
	            int child_wt=child[1];
	            if(vis[child_n]==true) continue;
	            q.push({child_wt,{child_n,curn}});
	        }
	        
	    }
	    
	    for(auto pr:mst){
	        cout<<pr.first<<"-->"<<pr.second<<endl;
	    }
	    
	    return sum;
	    
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // return prims(V,adj);
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        vector<pair<int,int>> mst;
        Disjointset ds(V);
        sort(edges.begin(),edges.end());
        int weight=0;
        for(auto edge: edges){
            int wt=edge.first;
            int u = edge.second.first;
            int v=edge.second.second;
            
            if(ds.findParent(u)==ds.findParent(v)) continue;
            weight+=wt;
            ds.unionBySize(u,v);
            mst.push_back({u,v});
        }
    //     for(auto pr:mst){
	   //     cout<<pr.first<<"-->"<<pr.second<<endl;
	   // }
        
        return weight;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
