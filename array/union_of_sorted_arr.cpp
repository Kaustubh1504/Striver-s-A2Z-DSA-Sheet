//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        // set<int> s;
        // for(int i=0;i<n;i++) s.insert(arr1[i]);
        // for(int i=0;i<m;i++) s.insert(arr2[i]);
    
        
        // vector<int> list;
        // for(auto e: s) list.push_back(e);
        // return list;
        
        // int l1=0;
        // int l2=0;
        // vector<int> uni;
        // uni.push_back(-1);
        
        // while(l1<n1 && l2<m){
            
            
        //     int n=uni.size();
            
        //     if(arr1[l1]==arr2[l2] && n-1>=0){
        //         if(uni[n-1]!=arr1[l1])
        //             uni.push_back(arr1[l1]);
        //         l1++;
        //         l2++;
        //     }else if(arr1[l1]<arr2[l2] && n-1>=0){
        //          if(uni[n-1]!=arr1[l1])
        //           uni.push_back(arr1[l1]);
        //         l1++;
        //     }else {
        //          if(uni[n-1]!=arr2[l2] && n-1>=0)
        //             uni.push_back(arr2[l2]);
        //         l2++;
        //     }
        // }
        
        // while(l1<n1){
        //     int n=uni.size();
        //     if(uni[n-1]!=arr1[l1] && n-1>=0)
        //         uni.push_back(arr1[l1]);
        //     l1++;
            
        // }
        
        // while(l2<m){
        //     int n=uni.size();
        //     if(uni[n-1]!=arr2[l2] && n-1>=0)
        //         uni.push_back(arr2[l2]);
        //     l2++;
        // }
        
        int l1=0;
        int l2=0;
        vector<int> uni;
        int mi = min(arr1[l1],arr2[l2]);
        uni.push_back(mi);
        
        // int n=sizeof(arr1)/sizeof(arr1[0]);
        // int m =sizeof(arr2)/sizeof(arr2[0]);
        // uni[n-1]
        while(l1<n && l2<m){
            
            int n = uni.size();
            
            if(arr1[l1]==arr2[l2]){
                if(uni[n-1]!=arr1[l1]){
                    uni.push_back(arr1[l1]);
                }
                l1++;
                l2++;
            }else if(arr1[l1]<arr2[l2]){
                if(uni[n-1]!=arr1[l1]){
                    uni.push_back(arr1[l1]);
                }
                l1++;
            }else if(arr1[l1]>arr2[l2]){
                if(uni[n-1]!=arr2[l2]){
                    uni.push_back(arr2[l2]);
                }
                l2++;
            }
            
            
            
        }
        
        while(l1<n){
            if(uni.back()!=arr1[l1]){
                    uni.push_back(arr1[l1]);
                }
            l1++;
            
        }
        
        while(l2<m){
            if(uni.back()!=arr2[l2]){
                    uni.push_back(arr2[l2]);
                }
            l2++;
            
            
        }
        
        return uni;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
