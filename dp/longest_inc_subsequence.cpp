class Solution {
public:
    int lis(int ind,vector<int>& nums,vector<int>&dp){

        if(dp[ind]!=-1) return dp[ind];
        int ans=1;
        for(int i=0;i<ind;i++){
            if(nums[ind]>nums[i]){
                ans=max(ans,lis(i,nums,dp)+1);
            }
        }

        return dp[ind]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,lis(i,nums,dp));
        // }

        for(int ind=0;ind<n;ind++){
            int ans=1;
            for(int i=0;i<=ind;i++){
                if(nums[ind]>nums[i]){
                    ans=max(ans,dp[i]+1);
                }
            }
            dp[ind]=ans;
        }

        int ans=0;
        for(auto c: dp) ans=max(ans,c);
        for(auto c:dp) cout<<c<<" ";
        return ans;
    }
};
