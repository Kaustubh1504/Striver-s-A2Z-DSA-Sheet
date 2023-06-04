class Solution {
public:
    int func(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp){
        
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit=0;
        if(buy){
            int take=-prices[ind]+func(ind+1,0,cap,prices,dp);
            int nottake= 0 + func(ind+1,1,cap,prices,dp);
            profit=max(take,nottake);
        }else{
            int take=prices[ind]+func(ind+1,1,cap-1,prices,dp);
            int nottake=0 + func(ind+1,0,cap,prices,dp);
            profit=max(take,nottake);
        }

        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit=0;
                    if(buy){
                        int take=-prices[ind]+ahead[0][cap];
                        int nottake= 0 + ahead[1][cap];
                        profit=max(take,nottake);
                    }else{
                        int take=prices[ind]+ahead[1][cap-1];
                        int nottake=0 + ahead[0][cap];
                        profit=max(take,nottake);
                    }
                    cur[buy][cap]=profit;
                }
            }
            ahead=cur;
        }
        // return func(0,1,k,prices,dp);
        return ahead[1][k];
    }
};
