//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int func(int ind,int wtleft,int val[],int wt[],vector<vector<int>> &dp){
        
        if(ind==0){
            return (int)(wtleft/wt[0])*val[0];
        }
        // if(wtleft==0) return 0;
        if(dp[ind][wtleft]!=-1) return dp[ind][wtleft];
        
        int notpick=func(ind-1,wtleft,val,wt,dp);
        int pick=0;
        if(wtleft>=wt[ind]) pick= func(ind,wtleft-wt[ind],val,wt,dp)+val[ind];
        
        return dp[ind][wtleft]=max(notpick , pick);
    }
    
    int cutRod(int price[], int n) {
        //code here
        int wt[n+1];
        for(int i=0;i<n;i++) wt[i]=i+1;
        
        // for(int i=0;i<n;i++) cout<<price[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<wt[i]<<" ";
        // cout<<endl;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        // int ans=func(n-1,n,price,wt,dp);
        for(int wtleft=0;wtleft<=n;wtleft++){
            dp[0][wtleft]=(int)(wtleft/wt[0])*price[0];
        }

        for(int ind=1;ind<n;ind++){
            for(int wtleft=0;wtleft<=n;wtleft++){
                int notpick=dp[ind-1][wtleft];
                int pick=0;
                if(wtleft>=wt[ind]) pick= dp[ind][wtleft-wt[ind]]+price[ind];
                
                 dp[ind][wtleft]=max(notpick , pick);
            }
        }
        
        return dp[n-1][n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
