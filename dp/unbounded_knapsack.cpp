//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int func(int ind,int wtleft,int val[],int wt[],vector<vector<int>> &dp){
        
    //     if(ind<0) return 0;
    //     if(wtleft==0) return 0;
    //     if(dp[ind][wtleft]!=-1) return dp[ind][wtleft];
        
    //     int notpick=func(ind-1,wtleft,val,wt,dp);
    //     int pick=0;
    //     if(wtleft>=wt[ind]) pick= func(ind,wtleft-wt[ind],val,wt,dp)+val[ind];
        
    //     return dp[ind][wtleft]=max(notpick , pick);
    // }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        // int ans=func(N-1,W,val,wt,dp);
        
        // for(int i=0;i<dp.size();i++){
        //     dp[i][0]=0;
        // }
        // dp[0][wt[0]]=0;
        
        // Base Cases:
        // If ind==0, it means we are at the first item. Now, in an 
        // unbounded knapsack we can pick an item any number of times we want. 
        // As there is only one item left, we will pick for W/wt[0] times 
        // because we ultimately want to maximize the value of items 
        // while respecting the constraint of weight of the knapsack. 
        // The value added will be the product of the number of items picked 
        // and value of the individual item. Therefore we return (W/wt[0]) * val[0].
        
        for(int i=0; i<=W; i++){
            dp[0][i] = ((int) i/wt[0]) * val[0];
        }
        
        for(int ind=1;ind<N;ind++){
            for(int wtleft=0;wtleft<=W;wtleft++){
                int notpick=dp[ind-1][wtleft];
                int pick=0;
                if(wtleft>=wt[ind]) pick= dp[ind][wtleft-wt[ind]]+val[ind];
                dp[ind][wtleft]=max(notpick , pick);
                
            }
        }
        
        // return ans;
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
