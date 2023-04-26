//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int dp[1000005];
	// calculate the maximum sum with out adjacent
	int maxsum(int i,int *arr,int n){
	    
	    
	    if(i<0) return 0;
	    if(dp[i]!=-1) return dp[i];
	    //do not pick
	    int ans=maxsum(i-1,arr,n);
	    
	    //pick
	    ans=max(ans,maxsum(i-2,arr,n)+arr[i]);
	 
	    
	    
	    return dp[i]=ans;
	        
	    
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	   // int ans=0;
	    memset(dp,-1,sizeof(dp));
	    int ans=maxsum(n-1,arr,n);
	    
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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
