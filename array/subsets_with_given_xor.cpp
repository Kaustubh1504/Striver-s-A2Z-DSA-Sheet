int generate(int ind,int curxor,vector<int> arr, int N, int K,vector<vector<int>> &dp){
        
        if(ind==N){
            if(curxor==K) return 1;
            return 0;
        }
        if(dp[ind][curxor]!=-1) return dp[ind][curxor];
        
        int nottake=generate(ind+1,curxor,arr,N,K,dp);
        
        int take=generate(ind+1,curxor^arr[ind],arr,N,K,dp);
        
        return dp[ind][curxor]=take+nottake;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        
        int M = 0;
        int curxor=0;
        for(auto c:arr) {
            curxor^=c;
            M=max(M,curxor);
        }
        const int size = 1e5;
        vector<vector<int>> dp(N+5,vector<int>(size,-1));
        int ans=generate(0,0,arr,N,K,dp);
        return ans;
    }
