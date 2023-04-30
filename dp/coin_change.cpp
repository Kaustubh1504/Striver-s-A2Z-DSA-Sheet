class Solution {
public:
    int dp[100005];
    int knapsack(int amtleft,vector<int>& coins){
        if(amtleft==0) return 0;
        if(dp[amtleft]!=-1) return dp[amtleft];

        int ans=INT_MAX;
        for(auto coin: coins){
            if(amtleft-coin>=0)
                ans=min(ans+0ll,knapsack(amtleft-coin,coins)+1ll);
        }

        return dp[amtleft]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        // int n = coins.size();

        // int ans=knapsack(amount,coins);

        // return ans==INT_MAX?-1:ans;

        dp[0]=0;
        for(int amtleft=1;amtleft<=amount;amtleft++){
            int ans=INT_MAX;
            for(auto coin: coins){
                if(amtleft-coin>=0)
                    ans=min(ans+0ll,dp[amtleft-coin]+1ll);
            }
            dp[amtleft]=ans;
        }

        return dp[amount]==INT_MAX?-1:dp[amount];

    }
};
