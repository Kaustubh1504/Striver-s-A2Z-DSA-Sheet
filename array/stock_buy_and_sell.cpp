class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // int n=prices.size();
        // int mx=INT_MIN;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         int cur=prices[j]-prices[i];
        //         mx=max(mx,cur);
        //     }
        // }
        

        // return mx<0?0:mx;
        int n=prices.size();
        int low=0;
        int high=0;
        int mx=INT_MIN;

        while(high<n){
            int cur=prices[high]-prices[low];
            mx=max(mx,cur);
            if(prices[high]<prices[low]) low=high; 
            high++;
        }

        return mx<0?0:mx;
    }
};