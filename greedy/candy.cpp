class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=0;
        int candies[n];
        for(int i=0;i<n;i++) candies[i]=1;

        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(auto c: candies) cout<<c<<" ";
        cout<<endl;

        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candies[i-1]=max(candies[i-1],candies[i]+1);
            }
        }
        
        
        for(auto c: candies) cout<<c<<" ";
        for(auto c: candies) ans+=c;
        return ans;
    }
};
