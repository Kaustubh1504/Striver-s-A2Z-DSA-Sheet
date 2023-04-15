class Solution {
public:
    string reverseWords(string s) {
        // vector<string> sen;

        // char separator = ' ';
        // int i = 0;
    
        // // Temporary string used to split the string.
        // string str; 
        // while (s[i] != '\0') {
        //     if (s[i] != separator) {
        //         // Append the char to the temp string.
        //         str += s[i]; 
        //     } else {
        //         // cout << str << endl;
        //         if(str[0]!=' ') sen.push_back(str);
        //         str.clear();
        //     }
        //     i++;

        // }
        // if(str[0]!=separator) sen.push_back(str);
        // string ans="";
        // // for(auto i: sen) cout<<i<<" ";
        // for(int i=sen.size()-1;i>0;i--) ans=ans+sen[i]+" ";
        // ans+=sen[0];

        // return ans;
        vector<string> words;
        int n = s.size();
        string ans="";
        int i=0;
        while(s[i]==' ') i++;
        // cout<<s[i]<<endl;
        string cur="";
        for(int j=i;j<s.size();j++){
            

            if(j==n-1){
                cur+=s[j];
                if(cur!="" && cur[0]!=' ') words.push_back(cur);
            }
            else if(s[j]!=' '){
                cur+=s[j];
            }
            else{

                if(cur!="") words.push_back(cur);
                cur="";
            }

            // cout<<cur<<" "<<j<<endl;
        }

        // for(auto c: words) {
        //     // cout<<c<<endl;
        //    reverse(c.begin(),c.end());
        //     cout<<c<<endl;
        // }
        // cout<<i<<endl;
        // string ans="";
        for(int i=words.size()-1;i>0;i--){
            // cout<<words[i]<<endl;
            ans+=words[i];
            ans+=" ";
           
        }

        ans+=words[0];

        return ans;
    }
};
