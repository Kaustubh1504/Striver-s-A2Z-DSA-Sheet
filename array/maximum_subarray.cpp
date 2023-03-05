public:
    int maxSubArray(vector<int>& nums) {
        
        
        // int n=nums.size();
        // int maxsum=INT_MIN;
        // int sum=0;
        // /*for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         maxsum=max(maxsum,sum);
        //     }
        // }*/
        // for(int i=0;i<n;i++){
        //     sum=max(nums[i],sum+nums[i]);
        //     maxsum=max(sum,maxsum);
        // }
        // return maxsum;

        int sum=0,mx=INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx=max(mx,sum);
            if(sum<0) sum =0;
        }
        
        return mx;
      