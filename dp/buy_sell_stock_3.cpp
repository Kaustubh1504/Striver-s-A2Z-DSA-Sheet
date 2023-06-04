class Solution {
public:
    int func(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit=0;
        if(buy){
            int take= -prices[ind]+func(ind+1,0,cap,prices,dp);
            int notake = 0 +func(ind+1,1,cap,prices,dp);
            profit=max(take,notake);
        }else {
            int take=prices[ind]+func(ind+1,1,cap-1,prices,dp);
            int notake= 0 +func(ind+1,0,cap,prices,dp);
            profit=max(take,notake);
        }

        return dp[ind][buy][cap]=profit;                                           
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,0)));

        vector<vector<int>> ahead(n+1,vector<int>(3,0)),cur(n+1,vector<int>(3,0));
        
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int cap=1;cap<=2;cap++){
        //             int profit=0;
        //             if(buy){
        //                 int take= -prices[ind]+dp[ind+1][0][cap];
        //                 int notake = 0 +dp[ind+1][1][cap];
        //                 profit=max(take,notake);
        //             }else {
        //                 int take=prices[ind]+dp[ind+1][1][cap-1];
        //                 int notake= 0 +dp[ind+1][0][cap];
        //                 profit=max(take,notake);
        //             }

        //             dp[ind][buy][cap]=profit;
        //         }
        //     }
        // }


        // return func(0,1,2,prices,dp);
        // return dp[0][1][2];

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;
                    if(buy){
                        int take= -prices[ind]+ahead[0][cap];
                        int notake = 0 +ahead[1][cap];
                        profit=max(take,notake);
                    }else {
                        int take=prices[ind]+ahead[1][cap-1];
                        int notake= 0 +ahead[0][cap];
                        profit=max(take,notake);
                    }

                    cur[buy][cap]=profit;

                   
                }
                 
            }
            ahead=cur;
        }


        // return func(0,1,2,prices,dp);
        return ahead[1][2];
        
    }
};
