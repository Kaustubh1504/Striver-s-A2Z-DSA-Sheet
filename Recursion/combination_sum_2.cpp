class Solution {
public:
    vector<vector<int>> ans;
    // void generate(int ind,vector<int> &sub,int cursum,vector<int>& candidates,int target){

    //     if(ind==candidates.size() || cursum>target){
    //         if(cursum==target) ans.push_back(sub);
    //         return;
    //     }

    //     //pick
    //     if(cursum+candidates[ind]<=target){
    //         sub.push_back(candidates[ind]);
    //         cursum+=candidates[ind];
    //         generate(ind+1,sub,cursum,candidates,target);
    //         cursum-=candidates[ind];
    //         sub.pop_back();

    //     }
       

    //     //do not pick
    //     generate(ind+1,sub,cursum,candidates,target);

      
    // }
     void generate(int ind,vector<int> &sub,int cursum,vector<int>& candidates,int target){

         if(cursum>target) return;
         if(cursum==target) ans.push_back(sub);

         for(int i=ind;i<candidates.size();i++){

             if(i>ind && candidates[i]==candidates[i-1]) continue;
             sub.push_back(candidates[i]);
             cursum+=candidates[i];
             generate(i+1,sub,cursum,candidates,target);
             cursum-=candidates[i];
             sub.pop_back();
         }
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        sort(candidates.begin(),candidates.end());
        generate(0,sub,0,candidates,target);

        // Sort the vector of vectors
        std::sort(ans.begin(), ans.end());

        // Use unique to get the unique elements
        auto it = std::unique(ans.begin(), ans.end());
        ans.resize(std::distance(ans.begin(), it));


        return ans;
        
    }
};
