//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    //floor
    int low=0;
    int high=n-1;
    
    pair<int,int> ans;
    int floor = -1;
    int ceil = -1;
    
     sort(arr,arr+n);
     
     while(low<=high){
         int mid= low + (high-low)/2;
         
         if(arr[mid]==x){
             floor=arr[mid];
             ceil=arr[mid];
             break;
         }else if(arr[mid]>x){
             ceil=arr[mid];
             high=mid-1;
         }else{
             low=mid+1;
             floor=arr[mid];
         }
     }
     
    //  low=0;
    //  high=n-1;
     
    //  while(low<=high){
    //      int mid= low + (high-low)/2;
         
    //      if(arr[mid]==x){
    //          ceil=arr[mid];
    //          break;
    //      }else if(arr[mid]>x){
    //          ceil=arr[mid];
    //          high=mid-1;
    //      }else{
    //          low=mid+1;
             
    //      }
    //  }
     
    //  ans.make_pair(floor,ceil);
    ans.first=floor;
    ans.second = ceil;
     return ans;
}