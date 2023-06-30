// User function Template for C++

class Solution {
  public:
  
    // int distinctSubsequences(string s){
    //     map<string,int> freq;
    //     int n= s.size();
        
    //     for(int i=1;i<(1<<n);i++){
    //         string temp="";
    //         for(int j=30;j>=0;j--){
    //             if((i>>j)&1==1){
    //                 temp+=s[j];
    //             }
    //         }
    //         freq[temp]++;
            
    //     }
    //     return freq.size();
    // }
    // abcbac
    /*
    1 a   b   c    b 
      ""  ""  ""   "" b
      a   b    b   b  bb
          a    a   a  ab
          ab   ab  ab abc
               c    c  cb
               bc   bc  bbc
               ac   ac  abc
               abc  abc  abbc
          
    */    
    // int distict(string s){
        
    //     const int M =1000000007;
    //     int n = s.size();  
    //     vector<long long> dp(n+1,0);
    //     dp[0]=1; // empty subsequecne
       
       
    //     map<char,int> elementIndex; // lastoccurance of an element at a Index
       
    //     for(int i=1;i<=n;i++){
    //         char ch = s[i-1];
           
    //         if(elementIndex.find(ch)==elementIndex.end()){//not present
    //             dp[i]=((dp[i-1]%M)*(2%M))%M;
    //         }else{
    //             int lastoccurace = elementIndex[ch];
    //             dp[i] = (((dp[i-1]%M)*(2%M))%M - dp[lastoccurace-1]%M)%M;
    //         }
           
    //         elementIndex[ch]=i;
    //     }
       
    //     // if(dp[n]<0)dp[n]+=M;
    //     return dp[n];
    // }
    
    int distict(string s){
         const int M =1000000007;
        int n = s.size();  
        vector<long long> dp(n+1,0);
        
        dp[0]=1; //empty string
        
        map<char,int> valIndex;
        for(int i=1;i<=n;i++){
            char c = s[i-1];
            
            if(valIndex.find(c)==valIndex.end()){
                dp[i]=(dp[i-1]*2)%M;
            }else{
                int lastoccurance= valIndex[c];
                dp[i]=((dp[i-1]*2)%M- dp[lastoccurance-1])%M;
            }
            
            valIndex[c]=i;
        }
        
        if(dp[n]<0)dp[n]+=M;
        return dp[n];
        
    }
    
    
    string betterString(string str1, string str2) {
        
        // if(distinctSubsequences(str1)>=distinctSubsequences(str2)){
        //     return str1;
        // }else{
        //     return str2;
        // }
        
        int s1 = distict(str1);
        int s2 = distict(str2);
        
        if(s2>s1) return str2;
        else return str1;
        
        
        
    }
    
};
