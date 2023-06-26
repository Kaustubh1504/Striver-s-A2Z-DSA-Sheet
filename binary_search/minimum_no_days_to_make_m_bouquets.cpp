class Solution {
public:
// 1 2 3 10 10
    bool isPossible(int x,vector<int>& bloomDay, int m, int k){
        int n=bloomDay.size();
        int Bouquets=0;
        int adjcnt=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=x){
                adjcnt++;
            }else{
                Bouquets+=(adjcnt/k);
                adjcnt=0;
            }
        }
        Bouquets+=(adjcnt/k);
        if(Bouquets>=m) return true;
        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long flowersinbouquet=m*1ll*k*1ll;
        if(flowersinbouquet>n) return -1;

        int low=1;
        int high=-1;
        for(auto f:bloomDay) high=max(high,f);

        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(isPossible(mid,bloomDay,m,k)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        // isPossible(93,bloomDay,m,k);
        cout<<high<<" "<<low<<endl;
        return ans;
    }
};
