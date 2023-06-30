class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int row,int col,vector<string> &board,int n){
        int i=row;
        int j=col;

        // north west
        while(j>=0 && i>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        // west
        i=row;
        j=col;
        while(j>=0){
            if(board[i][j]=='Q') return false;
            j--;
        }

        //south west
        i=row;
        j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }

        return true;
        

    }
    void solve(int col,vector<string> &board,int n){

        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board;
        for(int i=0;i<n;i++){
            string row="";
            for(int j=0;j<n;j++) row+='.';
            board.push_back(row);
        }
        solve(0,board,n);
        return ans;
    }
};
