class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    bool vis[55][55];
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int m,int n,int initialcolor){
        vis[sr][sc]=true;
        image[sr][sc]=color;
        
        for(int i=0;i<4;i++){
            
            int cr=sr+dx[i];
            int cc=sc+dy[i];

            if(cr>=m||cr<0||cc>=n||cc<0) continue;
            if(vis[cr][cc]==true) continue;
            if(image[cr][cc]!=initialcolor) continue;
           
            dfs(image,cr,cc,color,m,n,initialcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        dfs(image,sr,sc,color,m,n,image[sr][sc]);
        return image;
    }
};
