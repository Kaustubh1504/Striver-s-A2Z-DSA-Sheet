class Solution {
public:
    bool isPalindrome(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    int func(int ind,string s,vector<int> &dp){
        if(ind==s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int mincost=INT_MAX;
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            int cost=1e9;
            if(isPalindrome(temp)){
                cost=1+func(i+1,s,dp);
                mincost=min(cost,mincost);
            }
        }

        return dp[ind]=mincost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+5,0);
        // return func(0,s,dp)-1;
        for(int ind=n-1;ind>=0;ind--){
            int mincost=INT_MAX;
            string temp="";
            for(int i=ind;i<s.size();i++){
                temp+=s[i];
                int cost=1e9;
                if(isPalindrome(temp)){
                    cost=1+dp[i+1];
                    mincost=min(cost,mincost);
                }
            }

            dp[ind]=mincost;
        }

        int ans = dp[0]-1;
        return ans;
    }
};
