//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        // sort(arr,arr+N);
        // long long n=N;
        // long long ans = arr[n-2] + arr[n-1];
        
        // return ans;
        // long long fmi=0;
        // long long smi=0; 
        // long long ansmax=0;
        // for(int i=0;i<N;i++){
        //     fmi=arr[i];
        //     smi=arr[i];
        //     for(int j=i+1;j<N;j++){
                
        //         if(arr[j]<fmi && fmi>smi) fmi=arr[j];
        //         if(arr[j]<smi && smi<fmi) smi=arr[j];
                
        //         ansmax=max(ansmax,fmi+smi);
                
        //     }
        // }
        
        // return ansmax;
        
        long long ans = arr[0]+arr[1];
        for(int i=1;i<N-1;i++){
            ans=max(ans,arr[i]+arr[i+1]);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends