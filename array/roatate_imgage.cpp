class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // vector<vector<int>> temp;
        // for(int i=0;i<matrix.size();i++){
        //     temp.push_back(matrix[i]);
        // }
       
        // int n=matrix.size();
        //  /*for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<temp[i][j];
        //      cout<<endl;
        //  }*/
        // //int col=matrix[0].size(); 
        // //cout<<n;
        // int l=0,j,k;
        // for(int i=0;i<n;i++){
        //     k=n-1;
        //     for(j=0;j<n;j++){
        //         matrix[i][j]=temp[k][l];
        //         k--;
        //     }
        //     l++;
        //  }
        // temp.clear();

        int row=matrix.size();
        int col=matrix[0].size();

        reverse(matrix.begin(),matrix.end());

        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        

        
        
    }
};