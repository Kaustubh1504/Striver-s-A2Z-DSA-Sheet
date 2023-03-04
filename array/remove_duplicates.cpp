class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //   map<int,int> freqElemt;
        //   for(auto itr: nums){
        //       freqElemt[itr]++;
        //   }
        //  nums.clear();
        //  for(auto itr: freqElemt){
        //      nums.push_back(itr.first);
        //  }
        // return nums.size();
        // int cnt=nums.size();
        int n=nums.size();
        int insertIndex=1;
        for(int i=1;i<n;i++){
            
            if(nums[i]!=nums[i-1]){
                nums[insertIndex]=nums[i];
                insertIndex++;
            }
            
        }


        

        return insertIndex;
    }
};