class Solution {
public:
    int func(int ind,int buy,vector<int>& prices, int fee,vector<vector<int>>dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit=0;
        if(buy){
            int take= - prices[ind]+func(ind+1,0,prices,fee,dp);
            int nottake = 0 + func(ind+1,1,prices,fee,dp);
            profit=max(take,nottake);
        }else{
            int take= prices[ind]-fee+func(ind+1,1,prices,fee,dp);
            int nottake= 0 +func(ind+1,0,prices,fee,dp);
            profit=max(take,nottake);
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int take= - prices[ind]+dp[ind+1][0];
                    int nottake = 0 + dp[ind+1][1];
                    profit=max(take,nottake);
                }else{
                    int take= prices[ind]-fee+dp[ind+1][1];
                    int nottake= 0 + dp[ind+1][0];
                    profit=max(take,nottake);
                }
                dp[ind][buy]=profit;
            }
        }

        // return func(0,1,prices,fee,dp);
        return dp[0][1];
    }
};
