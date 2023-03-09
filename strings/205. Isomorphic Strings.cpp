class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // map<char,char> iso;

        // int n = s.size();

        // for(int i=0;i<n;i++){
        //     // if(iso.find(s[i])!=iso.end()){
        //     //     iso.insert({s[i],t[i]});
        //     // }

        //      //iso.insert({s[i],t[i]});
        //      auto it= iso.find(s[i]);
        //      if(it == iso.end()){
        //          iso.insert({s[i],t[i]});
        //      }
        // }
        // for(auto c: iso) cout<<c.first<<":"<<c.second<<endl;
        // for(int i=0;i<n;i++){
        //     s[i]=iso[s[i]];
        // }

        // // return s==t;

        // bool ans=false;
        // if(s==t) ans = true;

        // cout<<s<<" "<<t;

        // return ans;

        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
        
    }
};
