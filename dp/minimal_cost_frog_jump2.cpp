//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1000005];
    int mincost(int ind,vector<int>& h, int n, int k){
       if(ind==0) return 0;
       if(dp[ind]!=-1) return dp[ind];
       int ans=INT_MAX;
       
       for(int i=1;i<=k;i++){
           if(ind-i>=0){
                 ans=min(ans,mincost(ind-i,h,n,k)+abs(h[ind-i]-h[ind]));
           }
       }
       
       return dp[ind]=ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int ans=mincost(n-1,height,n,k);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
