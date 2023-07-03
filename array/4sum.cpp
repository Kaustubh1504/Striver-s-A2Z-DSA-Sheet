class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int ultimate_target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<vector<int>,int> temp;
        
        // -2 -1 0 0 1 2
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                long long target = ultimate_target*1ll- (nums[i]+nums[j])*1ll;
                int l=j+1;
                int h=n-1;

                while(l<h){
                    if(nums[l]+nums[h]==target){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[l]);
                        t.push_back(nums[h]);
                        sort(t.begin(),t.end());
                        temp[t]++;
                        l++;

                    }else if(nums[l]+nums[h]>target){
                        h--;
                    }else{
                        l++;
                    }
                }
            }
        }

        vector<vector<int>> ans;
         for(auto it: temp){
            ans.push_back(it.first);
        }

       
        return ans;

    }
};
