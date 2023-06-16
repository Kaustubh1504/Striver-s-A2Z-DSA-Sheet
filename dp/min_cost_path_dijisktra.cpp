//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int dijisktra(vector<vector<int>>& grid,vector<vector<int>>& dist){
        
        int n=grid.size();
        int m =n;
   
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        // {wt,{row,col}}
        q.push({0,{0,0}});
        dist[0][0]=grid[0][0];
        
        while(!q.empty()){
            auto cur=q.top();
            q.pop();
            int dis=cur.first;
            int cur_x = cur.second.first;
            int cur_y = cur.second.second;
            
            for(int i=0;i<4;i++){
                int child_x = cur_x + dx[i];
                int child_y = cur_y + dy[i];
                if(child_x>=n || child_x<0 || child_y>=m || child_y<0) continue;
                int child_wt=grid[child_x][child_y];
                
                if(dis + child_wt<dist[child_x][child_y]){
                    dist[child_x][child_y]= dis + child_wt;
                    q.push({dist[child_x][child_y],{child_x,child_y}});
                }
                
            }
            
        }
        
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dist[n-1][n-1]+dist[0][0];
    }
    
	int minimumCostPath(vector<vector<int>>& grid) 
    {   
        
        int n=grid.size();
        const int INF =1e9;
        vector<vector<int>> dis(n+10,vector<int>(n+10,INF));
        int ans=dijisktra(grid,dis);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
