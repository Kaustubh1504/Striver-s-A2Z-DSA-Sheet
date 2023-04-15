class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<char,int> freq;
            for(int j=i;j<n;j++){
                //substrings are generated
                freq[s[j]]++;
                int mxone=0;
                char mxchar=' ';
                int mxtwo=INT_MAX;
                for(auto itr: freq){
                    mxone=max(mxone,itr.second);
                    mxtwo=min(mxtwo,itr.second);
                }

                // for(auto itr: freq){
                //     if(itr.first!=mxchar) mxtwo=max(mxtwo,itr.second);
                // }

                // cout<<mxone<<" "<<mxtwo<<endl;
                
                if(freq.size()>1){
                    // cout<<mxone<<" "<<mxtwo<<endl;
                   ans+=(mxone-mxtwo); 
                }
            }
        }

        return ans;
    }
};
