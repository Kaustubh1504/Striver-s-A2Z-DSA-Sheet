//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //{0,0,0,1, 2, 2, 2, 2 }
    int totalFruits(int n, vector<int> &fruits) {
        
        int left=0;
        int right=0;
        
        map<int,int> freq;
        int maxlength=0;
        while(right<n){
            
            int cur = fruits[right];
            freq[cur]++;
         
            while(freq.size()>2 && left<right){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0) freq.erase(fruits[left]);
                left++;
            }
            
            maxlength=max(maxlength,right-left+1);
            right++;
        }
        
        return maxlength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends
