class Solution {
public:
    void reverse(vector<int> &nums,int start,int end){
        int low=start;
        int high=end;

        while(low<=high){
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // int end=k;
        // int start=nums.size()-1;
        // for(int i=0;i<k;i++){
        //     swap(nums[end-i-1],nums[end]);
        //     swap(nums[end-i-1],nums[start]);
        //     if (start!=end){
        //          start--;
        //     }else{
        //         start=start;
        //     }
            
            
        // }
        
        // int n=nums.size();
        // for(int i=0;i<k;i++){

        //     int last=nums[n-1];
        //     for(int i=n-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=last;
        // }
        // map<int,int> elemIndex;
        // for(int i=0;i<nums.size();i++){
        //     elemIndex.insert({nums[0],i});
        // }
        
        int n=nums.size();
        k=(k)%n;
        if(n==1) return;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        
        
    }
};