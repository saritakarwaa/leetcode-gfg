class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int count=0;
        for(int top=0;top<m;top++){
            vector<int>colSum(n,0);
            for(int bottom=top;bottom<m;bottom++){
                for(int c=0;c<n;c++){
                    colSum[c]+=matrix[bottom][c];
                }
                int sum=colSum[0];
                for(int i=0;i<n;i++){
                    int sum=0;  //reset sum for each starting point
                    for(int j=i;j<n;j++){
                        sum+=colSum[j];
                        if(sum==target)
                        ++count;  
                    }
                }
            }
        }
        return count;
    }
};