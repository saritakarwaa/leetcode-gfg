class Solution {
public:
    int t[101][101];
    int path(int m,int n,int i,int j,vector<vector<int>>& obstacleGrid){
        if(i>=m || j>=n || obstacleGrid[i][j]==1) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(i==m-1 && j==n-1) return 1;
        return t[i][j]=path(m,n,i+1,j,obstacleGrid)+path(m,n,i,j+1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return path(m,n,0,0,obstacleGrid);
    }
};

//we didn't make it visited because it can go only right or down, not left,right,top,bottom