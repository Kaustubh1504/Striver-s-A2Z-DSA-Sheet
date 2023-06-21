//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int M = 1003;
    int func(int i,int j,int isTrue,string s,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        
        if(i==j){
            if(isTrue==1){
                if(s[i]=='T') return 1;
                else return 0;
            }else{
                //for false
                if(s[i]=='F') return 1;
                else return 0;
            }
        }
       
        
        if( dp[i][j][isTrue]!=-1) return  dp[i][j][isTrue];
        
        
        int ways=0;
        for(int ind=i+1;ind<=j-1;ind+=2){
            int lt = func(i,ind-1,1,s,dp);
            int lf = func(i,ind-1,0,s,dp);
            
            int rt = func(ind+1,j,1,s,dp);
            int rf = func(ind+1,j,0,s,dp);
    
            if(s[ind]=='|'){
            //  if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            // else ways = (ways + (lF * rF) % mod) % mod;
            
                //for true
                int bothtrue = (lt*rt)%M;
                int eithertrue = ((lt*rf)%M + (rt*lf)%M)%M;
                
                //for false
                int bothfalse = (lf*rf)%M;
                
                if(isTrue==1){
                    ways=(ways+ bothtrue+eithertrue)%M;
                }else{
                    ways=(ways+ bothfalse)%M;
                }
                
            }
            if(s[ind]=='&'){
                //     if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            // else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                //for true
                int bothtrue = (lt*rt)%M;
                
                //for false
                int bothfalse = (lf*rf)%M;
                int eitherfalse = ((lt*rf)%M+( rt*lf)%M)%M;
                
                if(isTrue==1){
                    ways=(ways+ bothtrue)%M;
                }else{
                    ways=(ways+ bothfalse+eitherfalse)%M;
                }
            }
            if(s[ind]=='^'){
                //for true
                int eithertrue = ((lt*rf )%M+ (rt*lf)%M)%M;
                
                //for false
                int bothtrue = (lt*rt)%M;
                int bothfalse= (lf*rf)%M;
                
                if(isTrue==1){
                    ways=(ways+ eithertrue)%M;
                }else{
                    ways=(ways+ bothtrue+bothfalse)%M;
                }
            }
        }
        
        return dp[i][j][isTrue]=ways%M;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N+5,vector<vector<int>>(N+5,vector<int>(3,-1)));
        int ans = func(0,N-1,1,S,dp);
        return ans%M;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
