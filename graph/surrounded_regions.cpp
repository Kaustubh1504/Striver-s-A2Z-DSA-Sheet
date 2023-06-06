class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};

    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j]='#';
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=board.size()||nx<0||ny>=board[0].size()||ny<0) continue;
            if(board[nx][ny]!='O') continue;
            dfs(nx,ny,board);
        }
    }
    void solve(vector<vector<char>>& board) {
    //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
      int m=board.size();
      int n=board[0].size();
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(i*j==0||i==m-1||j==n-1){
                // cout<<board[i][j]<<" ";
                if(board[i][j]=='O') dfs(i,j,board);
              }
            
            
          }
            // cout<<endl;
        }

       for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
             if(board[i][j]=='O'){
                  board[i][j]='X';
            }
          }
        }
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
             if(board[i][j]=='#') {
                 board[i][j]='O';
            }
          }
        }

    }
};
