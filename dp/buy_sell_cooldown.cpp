class Solution {
public:
    int func(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){

        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            int take=-prices[ind]+func(ind+1,0,prices,dp);
            int nottake = 0 + func(ind+1,1,prices,dp);
            profit=max(take,nottake);
        }else{
            int take=prices[ind]+func(ind+2,1,prices,dp);
            int nottake= 0 + func(ind+1,0,prices,dp);
            profit=max(take,nottake);
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){
        //             int take=-prices[ind]+dp[ind+1][0];
        //             int nottake = 0 + dp[ind+1][1];
        //             profit=max(take,nottake);
        //         }else{
        //             int take=prices[ind]+dp[ind+2][1];
        //             int nottake= 0 + dp[ind+1][0];
        //             profit=max(take,nottake);
        //         }

        //          dp[ind][buy]=profit;
        //     }
        // }
        // // return func(0,1,prices,dp);
        // return dp[0][1];
        vector<vector<int>> ahead(3,vector<int>(2,0));
        vector<vector<int>> cur(3,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int take=-prices[ind]+ahead[1][0];
                    int nottake = 0 + ahead[1][1];
                    profit=max(take,nottake);
                }else{
                    int take=prices[ind]+ahead[2][1];
                    int nottake= 0 + ahead[1][0];
                    profit=max(take,nottake);
                }

                 cur[0][buy]=profit;
            }
            ahead=cur;
        }
        // return func(0,1,prices,dp);
        return ahead[0][1];
    }
};
