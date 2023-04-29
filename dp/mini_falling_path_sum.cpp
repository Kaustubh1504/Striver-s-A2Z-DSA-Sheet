class Solution {
public:
/*
-80 -13 22
83  94 -5
73 -48 61

*/
    int dp[105][105];
    int func(int x,int y,int m,int n,vector<vector<int>>& matrix){

        if(x==m) return 0;
        if(y<0 || y>=n) return 1e9;
        if(dp[x][y]!=-1) return dp[x][y];
        int ans=INT_MAX;
        if(y==0){
            ans=min(ans,func(x+1,y,m,n,matrix)+matrix[x][y]);
            ans=min(ans,func(x+1,y+1,m,n,matrix)+matrix[x][y]);
        }
        if(y==n-1){
            ans=min(ans,func(x+1,y,m,n,matrix)+matrix[x][y]);
            ans=min(ans,func(x+1,y-1,m,n,matrix)+matrix[x][y]);
        }

        ans=min(ans,func(x+1,y,m,n,matrix)+matrix[x][y]);
        ans=min(ans,func(x+1,y-1,m,n,matrix)+matrix[x][y]);
        ans=min(ans,func(x+1,y+1,m,n,matrix)+matrix[x][y]);

        return dp[x][y]=ans;
        

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        memset(dp,-1,sizeof(dp));

        int m=matrix.size();
        int n=matrix[0].size();
        int y=0;
        int cur=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            // cout<<matrix[0][i];
            // if(matrix[0][i]<cur){
            //     cur=matrix[0][i];
            //     y=i;
            // }
            // cout<<cur<<" ";
            ans=min(ans,func(0,i,m,n,matrix));
        }
        // cout<<y<<endl;
     

        return ans;
    }
};
