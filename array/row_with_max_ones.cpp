//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int lower_bound(vector<int> row, int m,int target){
        int low=0;
        int high=m-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(row[mid]>=target){
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
            
            
        }
        
        return low;
        
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int target=1;
	    int ans=INT_MAX;
	    int index=-1;
	   // cout<<lower_bound(arr[3],m,1);
	   for(int i=0;i<arr.size();i++){
	       //ans=min(ans,lower_bound(arr[i],m,target));
	       int curones = lower_bound(arr[i],m,target);
	       if(curones<ans && curones<m){
	           ans=curones;
	           index=i;
	       }
	       
	   }
	    
	    return index;
	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends