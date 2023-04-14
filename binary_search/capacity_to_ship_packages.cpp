class Solution {
public:
    int isPossible(vector<int>& weights,int capacity, int days){
        int d=1;
        int cur=0;
        for(int x: weights){
            if(cur+x>capacity){
                d++;
                cur=0;
            }
            cur+=x;   
        }
        // cout<<"days:"<<d<<endl;
        // if(d<=days) return true;
        // else return false;

        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;int high=0;
        for (int w: weights) {
            low = max(low, w);
            high += w ;
        }
        

        while(low<high){
            int mid = low + (high-low)/2;

            int D=isPossible(weights,mid,days);
            if(D>days){
                 low=mid+1;
              
            }else{
                 high=mid;
            }
            // cout<<"low:"<<low<<" high:"<<high<<" mid:"<<mid<<endl;
        }

        return low;
    }
};
