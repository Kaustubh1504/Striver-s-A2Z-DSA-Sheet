//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    
	   // vector<vector<int>> seive;
	   // for(int i=0;i<n)
	   // seive[0]={0};
	   // seive[1]={1};
	   int seive[N+5]={0};
	   
	    vector<int> ans;
	    for(int i=2;i<=N;i++){
	        
	        if(seive[i]==0){
	            for(int j=i;j<=N;j+=i){
    	            seive[j]=i;
    	            if(j==N){
    	                
    	                ans.push_back(i);
    	            }
	            }
	            
	        }
	        
	    }
	   //cout<<seive[N]<<endl;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends
