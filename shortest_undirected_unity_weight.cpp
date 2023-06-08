//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
         
         vector<int> g[N];
         for(int i=0;i<M;i++){
             int x = edges[i][0];
             int y=  edges[i][1];
             g[x].push_back(y);
             g[y].push_back(x);
         }
         
        //  int i=0;
        //  for(auto vec: g){
        //      cout<<i<<":";
        //      for(auto i: vec){
        //          cout<<i<<" ";
        //      }
        //      i++;
        //      cout<<endl;
        //  }
         
         vector<int> level(N,-1);
         bool vis[N+1];
         
    //      //perform bfs 
    //      queue<int> q;
    //      q.push(src);
    //      level[src]=0;
    //     //  vis[src]=true;
         
    //      while(!q.empty()){
    //         int cur_n = q.front();
		  //  q.pop();
		  ////  cout<<cur_n<<" ";
		  //  for(auto child: g[cur_n]){
    //             if(vis[child]==true) continue;
    //              q.push(child);
    //              vis[child]=true;
    //              level[child]=level[cur_n]+1;
		  //  }
    //          }
        queue<int> q;
	    q.push(src);
	    level[src]=0;
	    vis[src]=true;
    

	    while(!q.empty()){
		    int cur_n = q.front();
		    q.pop();
		  //  cout<<cur_n<<" ";
		    for(auto child: g[cur_n]){
                // if(vis[child]==true) continue;
                if(level[child]!=-1) continue;
                q.push(child);
                vis[child]=true;
                level[child]=level[cur_n]+1;
		    }
	    }
       
         return level;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
