//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int arr[],vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
            mini =min(mini,steps);
        }
        
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        /*
           dim : arr[i-1]*arr[i]
           
           Partion DP:
           1. start with entire block/array
               i = start point
               j= end point
           2. Try all partitions run a loop
           3. return the best possible 2 partitions
           
           
           f(1,n-1) returns the min mul fo multipy
           
           f(i,j){
               if(i==j) return 0
               
               for(k --> i to j-1){
                   steps = (A[j-1]*A[k]*A[j]) + f(i,k) + f(k+1,j)
                   mini=min(mini,steps)
               }
               
               return mini
           }
          
        */
        vector<vector<int>> dp(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j){
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
                    mini =min(mini,steps);
                }
                
                 dp[i][j]=mini;
            }
        }
        
        // return f(1,N-1,arr,dp);
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
