class Solution {
public:
    // int path(int m,int n,int i,int j){
    //     if(i==m-1 && j==n-1) return 1;
    //     if(i>=m || j>=n) return 0;
    //     return path(m,n,i+1,j)+path(m,n,i,j+1);
    // }
    int uniquePaths(int m, int n) {
       vector<vector<int>>t(m,vector<int>(n,0));
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) t[i][j]=1;
            }
       }
       for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                t[i][j]=t[i-1][j]+t[i][j-1];
            }
       }
       return t[m-1][n-1];
    }
};