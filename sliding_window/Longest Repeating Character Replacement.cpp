class Solution {
public:
    int characterReplacement(string str, int k) {
        int n=str.size();
        int left=0;
        int right=0;
        
        map<char,int> freq;
        int ans=0;
        while(right<n){
            char cur = str[right];
            freq[cur]++;

            //check if the window is valid
            int mxfreq=0;
            for(auto c:freq) mxfreq=max(mxfreq,c.second);
            int sizeofwindow=right-left+1;

            while(sizeofwindow-mxfreq>k && left<right){
                freq[str[left]]--;
                if(freq[str[left]]==0) freq.erase(str[left]);
                left++;
                for(auto c:freq) mxfreq=max(mxfreq,c.second);
                sizeofwindow=right-left+1;
            }
            
            

            ans=max(ans,right-left+1);
            right++;

        }

        return ans;

    }
};
