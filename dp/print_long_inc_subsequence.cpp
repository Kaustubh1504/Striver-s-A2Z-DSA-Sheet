//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class Solution {
//   public:
//     vector<vector<int>> allincseq;
//     int lis(int ind,vector<int>&sub,vector<int>&arr){
        
//         int ans=1;
//         sub.push_back(arr[ind]);
//         for(int i=0;i<=ind;i++){
//             if(arr[ind]>arr[i]){
//                 ans=max(ans,lis(i,sub,arr)+1);
//             }
            
//         }
//         allincseq.push_back(sub);
//         sub.pop_back();
//         return ans;
//     }
//     vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
//         // Code here
//         vector<int> ans;
//         vector<int> sub;
//         vector<vector<int>> alllis;
        
//         int len=0;
//         for(int i=0;i<n;i++){
//             len=max(len,lis(i,sub,arr));
//         }
        
//         // cout<<len<<endl;
        
//         for(auto vec: allincseq){
//             if(vec.size()==len){
//                 reverse(vec.begin(),vec.end());
//                 alllis.push_back(vec);
//             }
//         }
//         int minsum=INT_MIN;
//         for(auto vec:alllis){
//             int sum=0;
//             for(auto c: vec){
//                 sum+=c;
//             }
//             if(sum>minsum){
//                 ans.clear();
//                 ans=vec;
//                 minsum=sum;
//             }
            
//         }
        
//         // for(auto vec:alllis){
//         //     for(auto e: vec){
//         //         cout<<e<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
//         // for(auto vec:allincseq){
//         //     for(auto e: vec){
//         //         cout<<e<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
//         return ans;
        
//     }
// };





class Solution {
  public:
     vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
       
       vector<int> dp(n+1,1);
       vector<int> hash(n+1,0);
       for(int i=0;i<n;i++) hash[i]=i;
       
       for(int ind=0;ind<n;ind++){
            int ans=1;
            for(int i=0;i<=ind;i++){
                if(arr[ind]>arr[i] && 1+dp[i]>dp[ind]){
                    dp[ind]=dp[i]+1;
                    hash[ind]=i;
                }
            }
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<hash[i]<<" ";
        // cout<<endl;
        vector<int> ans;
        
        //max length of dp array
        int mxlen=0,lastind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>mxlen){
                mxlen=dp[i];
                lastind=i;
            }
        }
        
        //trace back the path
        ans.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            ans.push_back(arr[lastind]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
         
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
