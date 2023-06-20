class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       vector<vector<int>> dp(m+1,vector<int>(n+1,0));

       //fill the first row and first col
       for(int i=0;i<m;i++){
           if(matrix[i][0]==1) dp[i][0]=1;
       }

       for(int j=0;j<n;j++){
           if(matrix[0][j]==1) dp[0][j]=1;
       }

       for(int i=1;i<m;i++){
           for(int j=1;j<n;j++){

               if(matrix[i][j]==1){
                   dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
               }
           }
       }
      
      int ans=0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
                ans+=dp[i][j];
           }
       }

       return ans;



    }
};
