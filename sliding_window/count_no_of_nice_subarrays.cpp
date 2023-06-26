class Solution {
public:
    int atMostKodd(vector<int>& nums, int k){
        int n = nums.size();
        int left=0,right=0;
        
        int odd=0;
        int noofsub=0;
        
        while(right<n){
            if(nums[right]%2==1) odd++;
            while(odd>k && left<=right){
                if(nums[left]%2==1) odd--;
                left++;
            }
            noofsub+=right-left+1;
            right++;
        }

        return noofsub;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKodd(nums,k)-atMostKodd(nums,k-1);
    }
};
