class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<vector<int>,int> temp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        // -4 -1 -1 0 1 2
        for(int i = 0 ;i < n ;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = - nums[i];
            int l=i+1;
            int h=n-1;

            while(l<h){
                if(nums[l]+nums[h]==target){
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[l]);
                    t.push_back(nums[h]);
                    temp[t]++;
                    l++;

                }else if(nums[l]+nums[h]>target){
                    h--;
                }else{
                    l++;
                }
            }
        }
        
        for(auto it: temp){
            ans.push_back(it.first);
        }

       
        return ans;

































        // vector<vector<int>> ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
           
        //     for(int j=i+1;j<n;j++){
        //             for(int k=j+1;k<n;k++){
        //                  vector<int> temp;
        //                 if(nums[i]+nums[j]+nums[k]==0){
        //                     temp.push_back(nums[i]);
        //                     temp.push_back(nums[j]);
        //                     temp.push_back(nums[k]);

        //                     ans.push_back(temp);
        //                 }
        //             }
        //     }

        // }
        // for(auto & v: ans){
        //     sort(v.begin(),v.end());
        // }
        // // for(auto v : ans){
        // //     for(auto e: v){
        // //         cout<<e<<" ";
        // //     }
        // //     cout<<endl;
        // // }
        // std::sort(ans.begin(), ans.end());
        // ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        // // vector<vector<int>> sol = unique(ans.begin(),ans.end());
        // return ans;

        // vector<vector<int>> ans;
        // int n = nums.size();

        // sort(nums.begin(),nums.end());


        
        // int last = INT_MIN;
        // for(int i=0;i<n;i++){

        //     // if(last==nums[i]) continue;
        //     // else last= nums[i];
        //     if(i>0 && nums[i]==nums[i-1]) continue;


        //     int target = -nums[i];
        //     int l=i+1;
        //     int h=n-1;
        //     while(l<h){
        //         if(nums[l]+nums[h]==target){
        //             vector<int> temp;
        //             temp.push_back(nums[i]);
        //             temp.push_back(nums[l]);
        //             temp.push_back(nums[h]);
        //             ans.push_back(temp);
        //             l++;
        //             // break;

        //         }
        //         else if(nums[l]==nums[h]) break;
        //         else if(nums[l]+nums[h]>target){
        //             if(nums[h]==nums[h-1]) h--;
        //             h--;

        //         }else{
        //             if(nums[l]==nums[l+1]) l++;
        //             l++;
        //         }
    
        //     }
        // }

        // std::sort(ans.begin(), ans.end());
        // ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        // // vector<vector<int>> sol = unique(ans.begin(),ans.end());
        // return ans;



    }
};
