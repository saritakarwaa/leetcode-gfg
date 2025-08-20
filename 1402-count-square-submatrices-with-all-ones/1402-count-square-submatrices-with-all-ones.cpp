class Solution {
public:

    //see maximal area before this
    int countSquares(vector<vector<int>>& matrix) {
        int total=0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    if(i==0 || j==0) dp[i][j]=1;
                    else dp[i][j]+=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    total+=dp[i][j];
                }
            }
        }
        return total;
    }
};