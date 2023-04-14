class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high=INT_MAX;

        while(low<high){
            int mid=low+ (high-low)/2;
            int cursum=0;
            for(auto c: nums){
                cursum+=(c+mid-1)/mid;
                // cout<<ceil(c/mid);
                // cout<<(c+mid-1)/mid;
            }

            // cout<<endl;

            // cout<<"low:"<<low<<" high:"<<high<<" mid:"<<mid<<endl;

            if(cursum>threshold){
                
                low=mid+1;
            }else{
                high=mid;
            }
        }

        return high;
    }
};
