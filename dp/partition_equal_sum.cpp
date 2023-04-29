class Solution {
public:
    int dp[205][20005];
    bool func(int ind,int target,vector<int>& nums){

        if(ind<0 || target<0) return false;
        if(target==0) return true;
        if(dp[ind][target]!=-1) return dp[ind][target];

        //do not pick
        bool ans = func(ind-1,target,nums);

        //pick
        ans|=func(ind-1,target-nums[ind],nums);
        return dp[ind][target]=ans;

    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int target=0;
        for(auto c: nums) target+=c;
        if(target%2!=0) return false;
        target/=2;
        int n = nums.size();
        // cout<<target<<endl;
        bool ans = func(n-1,target,nums);

        for(int i=0;i<nums.size();i++) cout<<dp[i]<<" ";

        return ans;
    }
};
