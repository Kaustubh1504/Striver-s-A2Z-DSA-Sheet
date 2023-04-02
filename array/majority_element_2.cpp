class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // map<int,int> freq;
        // for(auto e: nums){
        //     freq[e]++;
        // }

        // vector<int> ans;
        // int th= nums.size()/3;

        // for(auto itr: freq){
        //     if(itr.second>th) ans.push_back(itr.first);
        // }

        // return ans;
        int n =nums.size();
        int num1=-1;
        int num2=-1;
        int c1=0;
        int c2=0;

        for(auto el: nums){

            if(el==num1) c1++;
            else if(el==num2) c2++;
            else if(c1==0){
                num1=el;
                c1=1;
            }else if(c2==0){
                num2=el;
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        int freqnum1=0;
        for(auto el: nums){
            if(el==num1) freqnum1++;
        }

        int freqnum2=0;
        for(auto el: nums){
            if(el==num2) freqnum2++;
        }

        vector<int> ans;
        if(freqnum1>n/3) ans.push_back(num1);
        if(freqnum2>n/3 && num2!=num1) ans.push_back(num2);


        return ans;



    }
};
