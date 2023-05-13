class Solution {
public:
    static bool comp(string& s1,string &s2){
        return s1.size()<s2.size();
    }
    bool compare(string & s1, string & s2){
        if(s1.size()!=s2.size()+1) return false;

        int first=0;
        int second=0;

        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }else first++;
        }

        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        // for(auto c: words) cout<<c<<" ";
        int n = words.size();

       vector<int> dp(n+1,1);
       int ans=1;
       for(int ind=1;ind<n;ind++){
            for(int i=0;i<ind;i++){
                if((compare(words[ind],words[i])) && 1+dp[i]>dp[ind]){
                    dp[ind]=dp[i]+1;
                }
              
            }
              ans=max(ans,dp[ind]);
        }
        return ans;
    }
};
