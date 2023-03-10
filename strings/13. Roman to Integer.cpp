class Solution {
public:
    int romanToInt(string s) {
        // int ans=0;
        // for(int i=s.length()-1;i>0;i--){
        //     if(s[i]=='I'){
        //         ans+=1;
        //     }else if(s[i]=='V'){
        //         if(s[i-1]=="I"){
        //             ans+=4;
        //         }else{
        //             ans+=5;
        //         }
        //     }else if(s[i]=='X'){
        //         if(s[i-1]=="I"){
        //             ans+=9;
        //         }else{
        //             ans+=10;
        //         }
        //     else if(s[i]=='L'){
        //         if(s[i-1]=="X"){
        //             ans+=40;
        //         }else{
        //             ans+=90;
        //         }
                
        //     }else{}
        // }
        // return ans;

        map<char,int> romval;
        romval.insert({'I',1});
        romval.insert({'V',5});
        romval.insert({'X',10});
        romval.insert({'L',50});
        romval.insert({'C',100});
        romval.insert({'D',500});
        romval.insert({'M',1000});

        

        int n = s.size();
        int curmax=romval[s[n-1]];
        int ans=0;

        for(int i=n-1;i>=0;i--){
            cout<<curmax<<" "<<romval[s[i]]<<endl;
            // cout<<endl;
            if(romval[s[i]]>=curmax){
                ans+=romval[s[i]];
                curmax = romval[s[i]];
            }else{
                ans-=romval[s[i]];
            }
            
        }

        return ans;

        
    }
};
