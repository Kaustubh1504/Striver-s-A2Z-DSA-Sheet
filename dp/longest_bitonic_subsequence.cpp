//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    /*
	      1 2 1 3 3 4 2 1
	      1 5 2 4 3 3 2 1                
	    */
	   int n= arr.size();
	   vector<int> dp(n+1,1);
	   vector<int> dp2(n,1);
	   
       for(int ind=1;ind<n;ind++){
            for(int i=0;i<ind;i++){
                if((arr[ind]>arr[i]) && 1+dp[i]>dp[ind]){
                    dp[ind]=dp[i]+1;
                }
            }
        }
        
        reverse(arr.begin(),arr.end());
        
        for(int ind=1;ind<n;ind++){
            for(int i=0;i<ind;i++){
                if((arr[ind]>arr[i]) && 1+dp2[i]>dp2[ind]){
                    dp2[ind]=dp2[i]+1;
                }
            }
        }
        reverse(dp2.begin(),dp2.end());
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<dp2[i]<<" ";
        // cout<<endl;
        
        int ans=1;
        
        for(int i=0;i<n;i++){
            int cur = dp[i]+dp2[i]-1;
            ans=max(ans,cur);
        }
        
        
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
