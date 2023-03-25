class Solution {
public:
    int checkhrs(vector<int> piles,int x){
        int ans=0;
        for (int p : piles)
                ans += (p + x - 1) / x;

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low=1;
        int high=1e9+10;
        int ans=INT_MAX;
        while(low<high){
            int mid=low+(high-low)/2;
            int curhrs=checkhrs(piles,mid);

            // if(curhrs==h) return mid;
            // cout<<mid<<":"<<curhrs<<" ";
            // if(curhrs==h){
            //     ans=min(ans,mid);
            //     // low=mid+1;
            //     high=mid;
            // }
            // else if(curhrs>h){
            //     low=mid+1;
            // }else if(curhrs<h){
            //     high=mid;
            // }
            if(curhrs>h) low=mid+1;
            else high=mid;
        }



        return low;
        
    }
};
