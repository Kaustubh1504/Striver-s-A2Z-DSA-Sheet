class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        for(auto itr: intervals){
            if(ans.empty()){
                ans.push_back(itr);
            }

            int curstart=itr[0];
            int curend=itr[1];

            int laststart=ans[ans.size()-1][0];
            int lastend=ans[ans.size()-1][1];

            if(curstart>=laststart && curstart<=lastend){
                //change last interval
                ans.pop_back();
                ans.push_back({min(curstart,laststart),max(curend,lastend)});
            }else{
                ans.push_back(itr);
            }   
        }
        return ans;

        
    }
};
