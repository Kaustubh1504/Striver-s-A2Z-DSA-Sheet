class Solution {
public:

    int lis(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){

        if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int nottake=lis(ind+1,prev_ind,nums,dp);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take=lis(ind+1,ind,nums,dp)+1;
        }
        return dp[ind][prev_ind+1]=max(take,nottake);
    }
    // int lis(int ind,vector<int>& nums,vector<int>&dp){

    //     if(dp[ind]!=-1) return dp[ind];
    //     int ans=1;
    //     for(int i=0;i<ind;i++){
    //         if(nums[ind]>nums[i]){
    //             ans=max(ans,lis(i,nums,dp)+1);
    //         }
    //     }

    //     return dp[ind]=ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n,0);
        // // int ans=0;
        // // for(int i=0;i<n;i++){
        // //     ans=max(ans,lis(i,nums,dp));
        // // }

        // for(int ind=0;ind<n;ind++){
        //     int ans=1;
        //     for(int i=0;i<=ind;i++){
        //         if(nums[ind]>nums[i]){
        //             ans=max(ans,dp[i]+1);
        //         }
        //     }
        //     dp[ind]=ans;
        // }

        // int ans=0;
        // for(auto c: dp) ans=max(ans,c);
        // for(auto c:dp) cout<<c<<" ";
        // return ans;
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // int ans=lis(0,-1,nums,dp);

        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int nottake=dp[ind+1][prev_ind+1];
                int take=0;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    take=dp[ind+1][ind+1]+1;
                }
                dp[ind][prev_ind+1]=max(take,nottake);
            }
        }

        return dp[0][0];
    }
};
