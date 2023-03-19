class Solution {
public:
    int findMin(vector<int>& nums) {

        
        int n = nums.size();
        int low=0;
        int high=n-1;

        // if(n==1) return nums[0];
        // int mid;
        // while(low<=high){
        //     mid = low+(high-low)/2;
        //     if(nums[low]<nums[high]){
        //         high=mid;
        //     }else{
        //         low=mid+1;
        //     }
        // }

        // // cout<<low<<endl;
        // // int ans=min(nums[low],nums[high]);
        // int ans= nums[mid];
        // return ans;



        while(low<high){
            if(nums[low]<nums[high]) return nums[low];

            int mid = low + (high-low)/2;

            if(nums[mid]>=nums[low]) low=mid+1;
            else high=mid;
        }

        return nums[low];
    }
};
