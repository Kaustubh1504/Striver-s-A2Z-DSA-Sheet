//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1005][1005];
    int func(int ind,int wtleft,int W,int wt[],int val[],int n){
        
        if(ind==n) return 0;
        if(wtleft==0) return 0;
        if(dp[ind][wtleft]!=-1) return dp[ind][wtleft];
    
        int ans=func(ind+1,wtleft,W,wt,val,n);
        
        if(wtleft-wt[ind]>=0)
            ans = max(ans,func(ind+1,wtleft-wt[ind],W,wt,val,n)+val[ind]);
        
        return dp[ind][wtleft]=ans;
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       int ans=func(0,W,W,wt,val,n);
       
       return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
