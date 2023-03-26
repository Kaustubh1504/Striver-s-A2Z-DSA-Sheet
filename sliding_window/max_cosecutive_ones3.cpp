class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,h=0;
        int n=nums.size();
        int tol=0;
        int mx=0;

        while(h<n){

            if(nums[h]==0){
                tol++;
            }

            if(tol>k){
                while(tol>k){
                    if(nums[l]==0){
                        tol--;
                    }
                    l++;
                }
            }

            cout<<l<<" "<<h<<" "<<tol<<endl;
            mx=max(mx,h-l+1);
            // for(int i=l;i<=h;i++) cout<<nums[i]<<" ";
            // cout<<endl;
            h++;
        }
        return mx;
    }
};
