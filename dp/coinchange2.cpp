class Solution {
public:
    // int coinchange(int amtleft, vector<int>& coins){

    //     cout<<amtleft<<" |";
    //     if(amtleft==0) return 1;
    //     int ans=0;
    //     for(auto coin : coins){
    //         if(amtleft-coin>=0){
    //             cout<<"coin: "<<coin<<" ";
    //             ans+=coinchange(amtleft-coin,coins);

    //         }
    //     }

    //     return ans;
    // }

    int coin2(int ind,int amtleft,vector<int>&coins,vector<vector<int>>&dp){
        if(amtleft==0) return 1;
        if(ind==0){
            if(amtleft%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[ind][amtleft]!=-1) return dp[ind][amtleft];

        int nottake = coin2(ind-1,amtleft,coins,dp);
        int take=0;
        if(amtleft-coins[ind]>=0) take = coin2(ind,amtleft-coins[ind],coins,dp);

        return dp[ind][amtleft]=take+nottake; 
    }
    int change(int amount, vector<int>& coins) {
        // int ans=coinchange(amount,coins);
        int n = coins.size();
        vector<vector<int>> dp(n+5,vector<int>(amount+5,0));
        // int ans=coin2(n-1,amount,coins,dp);

        for(int amtleft=0;amtleft<=amount;amtleft++){
            if(amtleft%coins[0]==0) dp[0][amtleft]=1;
            else dp[0][amtleft]= 0;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int amtleft=0;amtleft<=amount;amtleft++){

                    int nottake = dp[ind-1][amtleft];
                    int take=0;
                    if(amtleft-coins[ind]>=0) take = dp[ind][amtleft-coins[ind]];

                    dp[ind][amtleft]=take+nottake; 
            }
        }
        int ans =dp[n-1][amount];

        return ans;
    }
};
