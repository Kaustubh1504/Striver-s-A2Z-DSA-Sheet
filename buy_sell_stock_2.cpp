class Solution {
public:
    int func(int ind,int buy,vector<int>& prices, vector<vector<int>> dp){

        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            int take = -prices[ind] + func(ind+1,0,prices,dp);
            int nottake = 0         + func(ind+1,1,prices,dp);
            profit=max(take,nottake);
        }else{
            int take = prices[ind] + func(ind+1,1,prices,dp);
            int nottake= 0          + func(ind+1,0,prices,dp);
            profit=max(take,nottake);
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        // return func(0,1,prices,dp);

        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=1;buy>=0;buy--){
        //             int profit=0;
        //             if(buy){
        //                 int take = -prices[ind] + dp[ind+1][0];
        //                 int nottake = 0         + dp[ind+1][1];
        //                 profit=max(take,nottake);
        //             }else{
        //                 int take = prices[ind] + dp[ind+1][1];
        //                 int nottake= 0          + dp[ind+1][0];
        //                 profit=max(take,nottake);
        //             }

        //              dp[ind][buy]=profit;

        //     }
        // }
        
        // return dp[0][1];

        vector<int> ahead(2,0),cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                    int profit=0;
                    if(buy){
                        int take = -prices[ind] + ahead[0];
                        int nottake = 0         + ahead[1];
                        profit=max(take,nottake);
                    }else{
                        int take = prices[ind] + ahead[1];
                        int nottake= 0          + ahead[0];
                        profit=max(take,nottake);
                    }

                     cur[buy]=profit;
                ahead=cur;
            }

        }

        return ahead[1];
        
    }
};
