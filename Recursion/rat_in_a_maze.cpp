// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void func(int row,int col,string sub,vector<vector<int>> &matrix){
        int n = matrix.size();
      
        if(row>=n || col >=n || row<0 || col<0) return;
        if(matrix[row][col]!=1) return;
        
        if(row==n-1 && col == n-1){
            ans.push_back(sub);
            return;
        }
        
        int original=matrix[row][col];
        matrix[row][col]=2;
        
        sub.push_back('D');
        func(row+1,col,sub,matrix);
        sub.pop_back();
        
        sub.push_back('U');
        func(row-1,col,sub,matrix);
        sub.pop_back();
        
        sub.push_back('R');
        func(row,col+1,sub,matrix);
        sub.pop_back();
        
        sub.push_back('L');
        func(row,col-1,sub,matrix);
        sub.pop_back();
        
        matrix[row][col]=original;
        
        
    }
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // ans.push_back({-1});
        // if(matrix[0][0]==0 || matrix[n-1][n-1]==0) return ans;
        
        ans.clear();
        string sub="";
        
        func(0,0,sub,matrix);
        return ans;
    }
};

    
