class Solution {
public:
    bool rotateString(string s, string goal) {

        // int n=s.length();
        // int pos=-1;
        // char st=s[0];
        // for(int i=0;i<n;i++){
        //     if(goal[i]==st){
        //         pos=i;
        //         break;
        //     }
        // }

        // if(pos==-1) return false;
        // reverse(s.begin(),s.end());
        // reverse(s.begin(),s.begin()+pos);
        // reverse(s.begin()+pos,s.end());

        // cout<<s;
        // if(s==goal) return true;
        if(s.size()!=goal.size()) return false;
        string s2 = s+s;
        auto itr = s2.find(goal);
        if(itr==string::npos) return false;
        return true;

        
    }
};
