class Solution {
public:
    vector<vector<int>> ans;
    void generate(int ind,int sum,int k,int n,vector<int>& sub, vector<int>& digits){

        if(sum==n && sub.size()==k)  ans.push_back(sub);
        for(int i=ind;i<digits.size();i++){
            sub.push_back(digits[i]);
            generate(i+1,sum+digits[i],k,n,sub,digits);
            sub.pop_back();
        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> digits;
        for(int i=1;i<=9;i++) digits.push_back(i);
        vector<int> sub;

        generate(0,0,k,n,sub,digits);

        return ans;
    }
};
