//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void dfs(int i,int j,vector<vector<int>>& grid,vector<pair<int,int>> &list,
   vector<vector<bool>> &vis,int r0,int c0){
       vis[i][j]=true;
       list.push_back({i-r0,j-c0});
       
       vector<int> dx={1,-1,0,0};
       vector<int> dy={0,0,1,-1};
       
       int n=grid.size();
       int m=grid[0].size();
       
       for(int k=0;k<4;k++){
           int nx=i+dx[k];
           int ny=j+dy[k];
           
           if(nx>=n ||nx<0 || ny>=m || ny<0) continue;
           if(grid[nx][ny]!=1) continue;
           if(vis[nx][ny]==true) continue;
           
           dfs(nx,ny,grid,list,vis,r0,c0);
       }
   }
    int countDistinctIslands(vector<vector<int>>& grid) {
        /*
        approch:
            perform dfs on each island that is one and store the structure of the graph
            by substracting with the base row and base column
            
            insert all the structures into a set and return the unique graphs 
        */
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n+5,vector<bool>(m+5,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    vector<pair<int,int>> list;
                    dfs(i,j,grid,list,vis,i,j);
                    s.insert(list);
                }
            }
        }
       
        
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
