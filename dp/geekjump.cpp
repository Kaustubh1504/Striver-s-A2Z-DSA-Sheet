//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
       int dp[100005];
       int mincost(vector<int>& height,int ind){
            
            // cout<<"ind:"<<ind<<endl;
            if(ind==0) return 0;
            if(dp[ind]!=-1) return dp[ind];
            int ans = mincost(height,ind-1)+abs(height[ind]-height[ind-1]);
            
            if(ind>1) ans=min(ans,mincost(height,ind-2)+abs(height[ind]-height[ind-2]));
            
            return dp[ind]=ans;
        }
        int minimumEnergy(vector<int>& height,int n){
            memset(dp,-1,sizeof(dp));
            int ans = mincost(height,n-1);
            
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
