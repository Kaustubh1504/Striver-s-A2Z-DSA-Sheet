class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // if(n==1 && target==nums[0]) return 0; 
        // if(n==2){
        //     if(target==nums[1]) return 1;
        // } 
        int low=0;
        int high= n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            //check for the sorted side
            //low--> mid and mid+1--> high
            if(nums[mid]==target) return mid;
            else if(nums[low]<=nums[mid]){

                if(target>=nums[low] && target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }

            }else{

                if(target>=nums[mid]&& target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            

        }


        return -1;
        
    }
};
