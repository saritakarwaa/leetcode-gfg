class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>row(m,false);
        vector<bool>col(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==true || col[j]==true) matrix[i][j]=0;
            }
        }
    }
};

    // vector<vector<int>>v=matrix;
    // int m=matrix.size();
    // int n=matrix[0].size();
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         if(v[i][j]==0){
    //             for(int col=0;col<n;col++) if(matrix[i][col]!=0) matrix[i][col]=0;
    //             for(int row=0;row<m;row++) if(matrix[row][j]!=0) matrix[row][j]=0;
    //         }
    //     }
    // }
// Time: O(m*n*(m+n)) – for each zero, you zero out its entire row and column.
// Space: O(m*n) – due to the copy of the matrix.