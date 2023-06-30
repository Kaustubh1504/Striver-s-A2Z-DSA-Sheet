class Solution {
public:
    bool isPalindrome(string temp){
        string rev = temp;
        reverse(rev.begin(),rev.end());
        return temp==rev;
    }
    void func(int ind,string s,vector<string>&sub,vector<vector<string>> &ans){

        if(ind==s.size()){
            ans.push_back(sub);
            return;
        }


        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(isPalindrome(temp)){
                sub.push_back(temp);
                func(i+1,s,sub,ans);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        func(0,s,sub,ans);
        return ans;
    }
};
