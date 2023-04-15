//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool ispossible(vector<int> & stalls,int mindis,int cows){
        
        int placedcows=1;
        int lastcow=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastcow>=mindis){
                placedcows++;
                lastcow=stalls[i];
                if(placedcows==cows) return true;
            }
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1];
        
        while(low<=high){
            int mid = low +(high-low)/2;
            
            if(ispossible(stalls,mid,k)){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        
        
        
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
