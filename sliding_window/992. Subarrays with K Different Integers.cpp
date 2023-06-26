class Solution {
public:
    int atmostKdistinct(vector<int>& nums, int k){
        int n=nums.size();
        int left=0;
        int right=0;

        map<int,int> mp;

        int noofsub=0;
        while(right<n){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            noofsub+=(right-left+1);
            right++;
        }

        return noofsub;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostKdistinct(nums,k)-atmostKdistinct(nums,k-1);
    }
};
