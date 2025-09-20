class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,INT_MAX),col(n,INT_MIN);
        for(int i=0;i<m;i++){
            row[i]=*min_element(matrix[i].begin(),matrix[i].end());
        }
        for(int j=0;j<n;j++){
            int mx=INT_MIN;
            for(int i=0;i<m;i++){
                mx=max(mx,matrix[i][j]);
            }
            col[j]=mx;
        }
        vector<int>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j]) v.push_back(matrix[i][j]);
            }
        }
        return v;
    }
};