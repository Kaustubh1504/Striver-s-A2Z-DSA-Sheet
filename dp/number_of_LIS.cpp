class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {

       int n= arr.size();
       int maxi=INT_MIN;
	   vector<int> dp(n+1,1),cnt(n+1,1);
       for(int ind=0;ind<n;ind++){
           for(int prev_ind=0;prev_ind<ind;prev_ind++){
               if(arr[ind]>arr[prev_ind] && dp[prev_ind]+1>dp[ind]){
                   dp[ind]=dp[prev_ind]+1;

                   //inherit
                   cnt[ind]=cnt[prev_ind];

               }else if(arr[ind]>arr[prev_ind] && dp[prev_ind]+1==dp[ind]){
                   cnt[ind]=cnt[ind]+cnt[prev_ind];
               }
           }
           maxi=max(maxi,dp[ind]);
       }

       int ans=0;
       for(int i=0;i<n;i++){
          if(dp[i]==maxi) ans+=cnt[i];
       }
       return ans;
        
    }
};
