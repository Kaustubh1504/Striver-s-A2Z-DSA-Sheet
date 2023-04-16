class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // int n = nums.size();

        // for(int i=0;i<(1<<n);i++){
        //     vector<int> temp;
        //     for(int j=0;j<31;j++){
        //         if((i>>j)&1){
        //             temp.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }

        // return ans;
        vector<int> sub;
        generate(sub,0,nums);
        return ans;
        
    }

    void generate(vector<int> &sub,int ind,vector<int>& nums){


        if(ind>=nums.size()){
            ans.push_back(sub);
            return;
        }

        //do not pick
        generate(sub,ind+1,nums);

        //pick at index 
        sub.push_back(nums[ind]);
        generate(sub,ind+1,nums);
        sub.pop_back();
    }
};
