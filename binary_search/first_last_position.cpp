class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n=nums.size();
        int low=0;
        int high=n-1;

        int floor=-1;
        int ceil=-1;

        while(low<=high){
            int mid= low + (high-low)/2;
            if(nums[mid]==target){
                floor=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        low=0;
        high=n-1;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(nums[mid]==target){
                ceil=mid;
                // high=mid-1;
                low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        vector<int> ans;
        ans.push_back(floor);
        ans.push_back(ceil);

        return ans;
        
    }
};