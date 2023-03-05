class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // int low=0;
        // int high=0;
        // int n=nums.size();
        // int lastneg=0,lastpos=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<0) lastneg=i;
        //     if(nums[i]>0) lastpos=i;

        //     if(lastpos>lastneg){
        //         swap(nums[lastpos],nums[lastneg]);
        //     }
        // }
        int n=nums.size();
        vector<int> ans(n,0);
        int lastpos=0;
        int lastneg=0;

        // for(int i=0;i<n;i++){
        //     if(nums[i]<0) lastneg=i;
        //     if(nums[i]>0) lastpos=i;

        //     ans
        // }
        // while(lastpos<n && lastneg<n){

        // }

        //positve 
        int k=0,j=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[k]=nums[i];
                k+=2;
            }
            if(nums[i]<0){
                ans[j]=nums[i];
                j+=2;
            }
        }

        
        //negative
        // k=1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<0){
        //         ans[k]=nums[i];
        //         k+=2;
        //     }
        // } 




        return ans;
        
    }
};