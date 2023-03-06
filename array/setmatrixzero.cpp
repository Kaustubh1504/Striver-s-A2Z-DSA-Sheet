class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int rowsize=matrix.size();
        // int colsize=matrix[0].size();
        // vector<vector<int>> zm;
        // vector<int> curcol(colsize,1);
        // for(int i=0;i<rowsize;i++) zm.push_back(curcol);
        // for(int i=0;i<rowsize;i++){
        //     for(int j=0;j<colsize;j++){
        //        if(matrix[i][j]==0)
        //            zm[i][j]=0;
        //     }
        // }
        
        // for(int i=0;i<rowsize;i++){
        //     for(int j=0;j<colsize;j++){
        //         if(zm[i][j]==0){//if we find a zero 
        //             //make the row zero
        //             for(int k=0;k<colsize;k++){
        //                 matrix[i][k]=0;
        //             }
        //             //make the colums zero
        //             for(int k=0;k<rowsize;k++){
        //                 matrix[k][j]=0;
        //             }
        //         }
        //     }
        // }

        int row=matrix.size();
        int col=matrix[0].size();

        // vector<int> zrow(row,1);
        // vector<int> zcol(col,1);

        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(matrix[i][j]==0){
        //             zrow[i]=0;
        //             zcol[j]=0;
        //         }
        //     }
        // }

        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(zrow[i]==0 || zcol[j]==0){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        int fcol=1,frow=1;

        for(int j=0;j<col;j++){
            if(matrix[0][j]==0) fcol=0;
        }

        for(int i=0;i<row;i++){
            if(matrix[i][0]==0) frow=0;
        }
        

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    
                }
        
            }
        }
        for(int i=row-1;i>0;i--){
            for(int j=col-1;j>0;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }

            }
        }


        if(fcol==0){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }

        if(frow==0){
            for(int j=0;j<row;j++){
                matrix[j][0]=0;
            }
        }



        
    }
};