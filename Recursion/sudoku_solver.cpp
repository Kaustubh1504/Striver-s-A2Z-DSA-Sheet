bool issafe(int row,int col,char c,vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
        }
        // 5,7  --> 3,6
        int start_row = (row/3)*3; 
        int start_col = (col/3)*3;

        // cout<<start_row<<" "<<start_col<<endl;

        for(int i=start_row;i<start_row+3;i++){
            for(int j=start_col;j<start_col+3;j++){
                if(board[i][j]==c) return false;
            }
        }

        return true;

    }
    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){

                    for(char c='1';c<='9';c++){
                        if(issafe(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board)==true) return true;
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;

                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
