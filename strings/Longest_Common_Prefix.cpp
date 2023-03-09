
#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();
        int mi = INT_MAX;
        // string ans="";
        for(auto c: strs){
             if(c.size()<mi) mi=c.size();
        }
        for(int i=0;i<mi;i++){
            bool add=true;
            for(int j=0;j<n-1;j++){
                if(strs[j][i]!=strs[j+1][i]) add=false;
            }

            if(add) ans+=strs[0][i];
            else break;
        }

        return ans;
    }
};
