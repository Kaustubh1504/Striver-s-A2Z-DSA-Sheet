class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int n=nums.size();
        // int ans=-1;
        // if(n==1) return 0;
        // for(int i=0;i<n;i++){
        //     if(i==0){
        //         if(nums[i+1]<nums[i]){
        //             ans=i;
        //         }

        //     }
        //     else if(i==n-1){
        //         if(nums[i-1]<nums[i]) ans=i;

        //     }else{
        //         if(nums[i-1]<nums[i] && nums[i+1]<nums[i]){
        //             ans=i;
        //         }
        //     }
        // }


        // return ans;


        int n = nums.size();
        
        if(n==1) return 0;
        if(n>1){
            if(nums[0]>nums[1]) return 0;
            else if(nums[n-1]>nums[n-2]) return n-1;
        }
        

        int low=1;
        int high=n-2;
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]) return mid;
            else if(nums[mid-1]>nums[mid]) high=mid-1;
            else if(nums[mid+1]>nums[mid]) low=mid+1;
        }

        return -1;
        
    }
};
