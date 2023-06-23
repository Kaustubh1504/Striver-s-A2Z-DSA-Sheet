class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         /*
         1. set ds to store all the words in wordlist
         2. do a bfs traveral {string,steps}
         3. to get the children of each word change each word from a to z and check wheter it is present or not
         4. while traversing if we find the endword return the steps else return 0
         */
         set<string> st;
         for(auto str: wordList) st.insert(str);

         queue<pair<string,int>> q;
         q.push({beginWord,1});
         st.erase(beginWord);

         while(!q.empty()){
             string word = q.front().first;
             int steps = q.front().second;
             q.pop();

            if(word==endWord) return steps;
             for(int i=0;i<word.size();i++){
                 char originalchar = word[i];
                 for(char j='a';j<='z';j++){
                     word[i]=j;
                     if(st.find(word)!=st.end()){
                         st.erase(word);
                         q.push({word,steps+1});
                     }
                 }
                 word[i]=originalchar;
             }

         }

         return 0;

    }
};
