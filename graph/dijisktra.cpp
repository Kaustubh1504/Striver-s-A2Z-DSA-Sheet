//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {       
        
          const int INF=1e9;
          priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
          vector<int> dis(V,INF);
          
          pq.push({0,S});
          dis[S]=0;
          
          while(!pq.empty()){
              auto cur=pq.top();
              int cur_n=cur.second;
              int cur_dis=cur.first;
              pq.pop();
              
              for(auto child:adj[cur_n]){
                  int child_n=child[0];
                  int child_wt=child[1];
                  
                  if(cur_dis+child_wt<dis[child_n]){
                      dis[child_n]=cur_dis+child_wt;
                      pq.push({dis[child_n],child_n});
                  }
              }
          }
          
          return dis;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
