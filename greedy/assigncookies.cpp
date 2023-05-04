class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int p1=g.size()-1;
        int p2=s.size()-1;
        int ans=0;

        while(p1>=0 && p2>=0){
            if(s[p2]>=g[p1]){
                ans++;
                p1--;
                p2--;
            }else{
                p1--;
            }
        }

        return ans;
    }
};
