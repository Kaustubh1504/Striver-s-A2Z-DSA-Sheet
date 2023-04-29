class Solution {
public:
    int dp[205][205];
    // int minpath(int x,int y,vector<vector<int>>& triangle){

    //     cout<<"x: "<<x<<" y: "<<y<<" | ";
    //     if(x<0 || y<0 || y>=triangle[x].size()) return 100;
    //     if(x==0 && y==0) return triangle[x][y];

    //     int ans=INT_MAX;
    //     // move to index i right
    //     if(y-1>=0)
    //          ans=min(ans,minpath(x-1,y-1,triangle)+triangle[x][y]);
    //     if(y+1<triangle[x].size())
    //         ans=min(ans,minpath(x-1,y+1,triangle)+triangle[x][y]);

    //     //move to (i+1)
    //     if(x-1>=0)
    //         ans=min(ans,minpath(x-1,y,triangle)+triangle[x][y]);

    //     return ans;
    // }
    int func(int x,int y,int n,vector<vector<int>>& triangle){

        if(x==n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int lower_right=func(x+1,y+1,n,triangle)+triangle[x][y];
        int lower_down=func(x+1,y,n,triangle)+triangle[x][y];

        return dp[x][y]=min(lower_right,lower_down);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int m = triangle.size();
        int n = triangle[m-1].size();

        // int ans = minpath(m-1,n-1,triangle);
        int ans=func(0,0,m,triangle);

        return ans;
    }
};
