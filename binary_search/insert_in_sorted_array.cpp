class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    //     unsigned int l=0;
    //     unsigned int h=nums.size()-1;
    //     unsigned int mid;
    //     int ans;
    //     if(nums[0]>=target){
    //         return 0;
            
    //     }else{
    //     while(l<=h){
    //         mid=floor((l+h)/2);
    //         if(nums[mid]>=target){
    //             if(nums[mid-1]<target)
    //                 //if the target lies in the range of nums[mid-1]<=target<=nums[mid]
    //                 return mid;
    //             else
    //                 h=mid-1;
    //              //if the target is less than nums[mid] but not greater than nums[mid-1]
    //             //look for first half
                    
    //         }else{
    //             l=mid+1;
    //             //look for second half
    //         }
    //     }
            
    //     }
  
    //    return nums.size();








        int n=nums.size();

        int low=0;
        int high = n-1;

        // int ind = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        // return nums[ind]==target?ind: ind+1;

        int floor=-1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                floor = mid;
                // break;
                return mid;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                floor=mid;
                low=mid+1;
            }
        }




        return floor+1;


    }
};