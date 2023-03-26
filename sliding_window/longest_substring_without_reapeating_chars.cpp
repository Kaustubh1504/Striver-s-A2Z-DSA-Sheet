class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
      int n=s.size();
      int l=0,r=0;

    //   set<char> vis;
      int mx=0;
      map<char,int> vis;

      while(r<n){
          if(vis.find(s[r])==vis.end()){
              vis.insert({s[r],1});
              r++;
          }else{
              while(vis.find(s[r])!=vis.end()){
                  vis.erase(s[l]);
                  l++;
              }
              vis.insert({s[r],1});
              r++;
          }

          mx=max(mx,r-l);


      }

      return mx;

    //   while(r<n){

    //       if(vis.find(s[r])!=vis.end()){ //present
    //             while(l!=r && s[l]!=s[r]){
    //                 vis.erase(s[l]);
    //                 l++;
    //             }

    //             vis.erase(s[l++]);
    //             vis.insert(s[r]);
    //             r++;


    //       }
    //       else{
    //           vis.insert(s[r]);
    //           mx=max(mx,r-l+1);
    //           r++;
    //       }


    //   }

    //   return mx;

    








    //     map<char,int> freq;
    //     int currentLength=0;
    //     int maxLength=0;
    //     int left=0;
    //     int right=0;
    //     int n=s.size();
    //     freq[s[right]]=right;
    //     while(right<n){
    //         currentLength=right-left+1;
    //         maxLength=max(currentLength,maxLength);
            
    //         //if found in map i.e present in substring
    //         if(freq.find(s[right])!=freq.end()){
                
    //         }else{
    //             freq[s[right]]=right;
    //         }
    //     }
    //    return maxLength; 




    }
};
