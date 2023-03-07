//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        // long long low=0;
        // long long high=n-1;
        // long long ans=-1;
        
        // while(low<=high){
        //     long long mid=low+(high-low)/2;
            
        //     if(v[mid]>=x){
                
        //          high=mid-1;
        //     }else {
        //       low=mid+1;
        //     }
        // }
        
        
        // return low;
        
        // int low=0;
        // int high=n-1;
        
        // while(low<=high){
        //     int mid=low+(high-low)/2;
            
        //     if(v[mid]>x){
        //         high=mid-1;
                
        //     }
        //     else{
        //         low=mid+1;
        //     }
            
            
        // }
        
        // return v[low]<=x?low:-1;
        // return lower_bound(v,n,x);
        // int ind = lower_bound(v.begin(),v.end(),x)-v.begin();
        // if(ind!=n && v[ind]==x) ind=ind;
        // else ind=-1;
        
        // return ind;
        // cout<<low<<" "<<v[low];
        // return low==n || v[low]>x ?-1:v[low];
        // int ans=0;
        // if(high-1<0) ans=-1;
        // else ans = high;
        
        // return ans;
        
        // int low=0;
        // int high=n-1;
        
        // while(low<=high){
        //     int mid=low+(high-low)/2;
            
        //     if(v[mid]>x){
              
        //         low=mid+1;
        //     }else{
        //          high=mid-1;
                
        //     }
        // }
        
        
        
        // return v[low];
        
        
        // int low=0;
        // int high=n-1;
        // int ans=-1;
        
        // while(low<=high){
        //     int mid= low + (high-low)/2;
            
        //     if(v[mid]==x){
        //         // ans=v[mid];
        //         return v[mid];
        //     }
        //     else if(v[mid]>x){
        //          high=mid-1;
                 
        //     }else{
        //       low=mid+1;
        //       ans=v[mid];
        //     }
        // }
        
        
        // return ans;
        
        int low = 0, high = v.size() - 1;
    int floor = -1;
    int target=x;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (v[mid] == target) {
            return mid;
        }
        else if (v[mid] > target) {
            high = mid - 1;
        }
        else {
            floor = mid;
            low = mid + 1;
        }
    }

    
        
    return floor;

        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends
