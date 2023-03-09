class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // sort(t.begin(),t.end());
        // sort(s.begin(),s.end());
        // // cout<<t;
        // if(s==t) return true;
        // else return false;

        int m[26]={0};
        int ans=true;
        for(auto c: s) m[c-'a']++;
        for(auto c: t) m[c-'a']--;

        for(auto i: m ) {
            if(i!=0){
                ans=false;
                break;
            }
        }

        return ans;
        
    }
};
