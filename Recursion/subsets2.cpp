class Solution {
public:
    vector<vector<int>> ans;
    // set<vector<int>> dup;

    void gen(int ind,vector<int>& sub, vector<int>& nums,int n){

        // if(ind==n){
        //     ans.push_back(sub);
        //     return;
        // }
        ans.push_back(sub);

        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            sub.push_back(nums[i]);
            gen(i+1,sub,nums,n);
            sub.pop_back();
        }


    }
    // void subs(vector<int> &nums, int curr, vector<int> &res){
    //     ans.push_back(res);
    //     for(int i = curr; i < nums.size(); i++){
    //         if(i!=curr && nums[i]==nums[i-1]){
    //             continue;
    //         }
    //         res.push_back(nums[i]);
    //         subs(nums, i+1, res);
    //         res.pop_back();
            
    //     }
    // }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        // ans.push_back(sub);
        sort(nums.begin(),nums.end());
        gen(0,sub,nums,nums.size());
        // subs(nums,0,sub);

        return ans;
    }
};
