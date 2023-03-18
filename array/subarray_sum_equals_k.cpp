class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // int ans=0;
        // int n=nums.size();

        // for(int i=0;i<n;i++){
        //     int sum=nums[i];
        //     if(sum==k) ans++;
        //     for(int j=i+1;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k) ans++;
        //     }
            
        // }
        // //if(nums[n-1]==k) ans++;
        // return ans;
        // if(k==0) return 0;
    
        // int i=0;
        // int j=0;
        // int n=nums.size();
        // int sum=0;
        // int ans=0;

        // if(n==1 && k!=nums[0]) return 0;

        // while(j<n){
        //     sum+=nums[j];
        //     if(sum==k){
        //         // ans=max(ans,j-i+1);
        //         ans++;
        //         j++;
        //     }else if(sum<k){
        //         j++;
        //     }else if(sum>k){
        //         while(sum>k){
        //             sum-=nums[i];
        //             if(sum==k) ans++;
        //             i++;
        //         }
        //         j++;
        //     }
        // }

        int n=nums.size();

        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        map<int,int> valInd;
        int ans=0;

        for(int i=0;i<n;i++){

          int cur = prefix[i]-k;
          if(valInd.find(cur)!=valInd.end()){
            ans+=valInd[cur];

          }
          // for(auto itr: valInd){
          //   if(itr.first==k) ans++;
          // }
          if(prefix[i]==k) ans++;


          //  valInd[prefix[i]]=i;
          // valInd.insert({prefix[i],i});
          valInd[prefix[i]]++;

        }


        return ans;
    }
};
