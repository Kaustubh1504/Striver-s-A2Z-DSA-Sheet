//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /*
    
    1  2  5
    3  1  1
    3  3  3
    
    */
    int dp[100005][5];
    int mxpts(int ind,vector<vector<int>>& points,int n,int prev){
        
        if(ind<0) {
            return 0;
            
        }
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int ans=INT_MIN;
        for(int i=0;i<3;i++){
            if(i==prev) continue;
            ans=max(ans,mxpts(ind-1,points,n,i)+points[ind][i]);
            // cout<<ans<<" ";
        }
        // cout<<ans<<" ";
        return dp[ind][prev]=ans;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        if(n==1){
            for(auto c: points){
                for(auto i: c) ans=max(ans,i);
            }
        }else{
              ans=mxpts(n-1,points,n,-1);
        }
      
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
