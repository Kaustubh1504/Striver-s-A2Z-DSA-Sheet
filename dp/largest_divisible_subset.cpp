class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        
       int n = arr.size();
       sort(arr.begin(),arr.end());
       vector<int> dp(n+1,1);
       vector<int> hash(n+1,0);
       for(int i=0;i<n;i++) hash[i]=i;
       
       for(int ind=1;ind<n;ind++){
            int ans=1;
            for(int i=0;i<ind;i++){
                if((arr[ind]%arr[i]==0 || arr[i]%arr[ind]==0) && 1+dp[i]>dp[ind]){
                    dp[ind]=dp[i]+1;
                    hash[ind]=i;
                }
            }
        }
        // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<hash[i]<<" ";
        // cout<<endl;
        vector<int> ans;
        
        //max length of dp array
        int mxlen=0,lastind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>mxlen){
                mxlen=dp[i];
                lastind=i;
            }
        }
        
        //trace back the path
        ans.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            ans.push_back(arr[lastind]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
