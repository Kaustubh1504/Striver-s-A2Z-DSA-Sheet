class Solution {
    
public:

    bool wordsearch(int row,int col, int ind,vector<vector<char>>& board, string& word){
        int n = board.size();
        int m = board[0].size();

        if(ind>=word.size()) return true;

        // if(row>=n || row<0 || col>=m || col<0) return false;
        // if(board[row][col]!=word[ind]) return false;
        // if(board[row][col]=='#') return false;

        if (row < 0 || col < 0 || row == n || col == m || board[row][col] !=word[ind] || board[row][col] == '#')
            return false;

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        bool ans=false;
        cout<<board[row][col]<<" ";
        char original = board[row][col];
        board[row][col]='#';
        for(int i=0;i<4;i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            ans|=wordsearch(nx,ny,ind+1,board,word);
        }
        board[row][col]=original;

        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        

        int n = word.size();
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    ans|=wordsearch(i,j,0,board,word);
                }
            }
        }
        /*
        "A","B","C","E"
        "S","F","E","S"
        "A","D","E","E"
        */


        return ans;
    }
};
