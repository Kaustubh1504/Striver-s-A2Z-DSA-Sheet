class Solution {
public:
    long long int frogjump(int ind,vector<int>& nums,vector<int>&dp){

        if(ind>=nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];

        long long int ans=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
                ans=min(ans+0ll,frogjump(ind+i,nums,dp)+1);
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;

        vector<int>dp(n+1,-1);
        long long int ans=frogjump(0,nums,dp);
        return ans;
    }
};

