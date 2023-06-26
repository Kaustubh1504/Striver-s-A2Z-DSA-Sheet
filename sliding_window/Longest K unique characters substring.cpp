//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    int longestKSubstr(string s, int k) {
        int n = s.size();
        int left=0;
        int right=0;
        
        map<char,int> mp;
        int maxlength=-1;
        
        while(right<n){
          
            char cur = s[right];
            mp[cur]++;
            
            //if we have less than k distinct chars
            if(mp.size()<k){
                right++;
                continue;
            }
            
            //if we have more than k distinct chars
            while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
            
            //if we have exactly k distinct chars
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
