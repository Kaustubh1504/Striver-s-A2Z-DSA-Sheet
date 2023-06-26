class Solution {
public: 
    int atMost(vector<int>& nums, int goal){
        int n=nums.size();
        int left=0,right=0;

        int sum=0;
        int noofsub=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal && left<=right){
                sum=sum-nums[left];
                left++;
            }
            noofsub+=right-left+1;
            right++;

        }

        return noofsub;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal-1);
    }
};
