class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // int row= matrix.size();
        // int col=matrix[0].size();

        // vector<int> spiralorder;

        // // int i=0,j=0;
        //  int i=0;
        // int j=0;
        // for(int k=0;k<row/2;k++){
        //             //left to right
        //             for(j=j;j<col;j++){
        //                 spiralorder.push_back(matrix[i][j]);
        //             }
        //             j--;
        //             //top to bottom
        //             for(i=i+1;i<row;i++){
        //                 spiralorder.push_back(matrix[i][j]);
        //             }
        //             i--;

        //             //right to left
        //             for(j=j-1;j>=0;j--){
        //                 spiralorder.push_back(matrix[i][j]);
        //             }
        //             j++;

        //             //bottom to top
        //             for(i=i-1;i>0;i--){
        //                 spiralorder.push_back(matrix[i][j]);
        //             }
        //             i++;

        //         i=i+1;
        //         col=col-1;
        //         row=row-1;
        //         j=j+1;







        // }
        



        // return spiralorder;





















        int left=0;
        int right=matrix[0].size();

        int top=0;
        int bottom=matrix.size();


        vector<int> spiral;


        while(top<bottom && left<right){

            //left to right
            for(int i=left;i<right;i++){
                spiral.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top;i<bottom;i++){
                spiral.push_back(matrix[i][right-1]);
            }
            right--;

            if(top>=bottom || left>=right) break;
            //right to left
            for(int i=right-1;i>=left;i--){
                cout<<matrix[bottom-1][i]<<endl;
                spiral.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            //bottom to top
            for(int i=bottom-1 ;i>=top;i--){
                spiral.push_back(matrix[i][left]);
            }
            left++;



        }

        return spiral;
        
    }
};
