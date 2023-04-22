class Solution {
public:

    vector<vector<int>> ans;
    void generate(int ind,vector<int> &sub,int cursum,vector<int>& candidates,int target){

        int sum=0;
        for(auto c: sub) sum+=c;
        // cout<<cursum<<" ";
        if(sum>target || ind==candidates.size()) return;
        if(sum==target){
            ans.push_back(sub);
        }
        // if(ind==candidates.size()) return;

        //pick
        sub.push_back(candidates[ind]);
        // cursum+=candidates[ind];
        generate(ind,sub,cursum,candidates,target);
        // cursum-=candidates[ind];
        sub.pop_back();

        //do not pick
        generate(ind+1,sub,cursum,candidates,target);

      
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        generate(0,sub,0,candidates,target);

        // Sort the vector of vectors
        std::sort(ans.begin(), ans.end());

        // Use unique to get the unique elements
        auto it = std::unique(ans.begin(), ans.end());
        ans.resize(std::distance(ans.begin(), it));


        return ans;
        
    }
};
