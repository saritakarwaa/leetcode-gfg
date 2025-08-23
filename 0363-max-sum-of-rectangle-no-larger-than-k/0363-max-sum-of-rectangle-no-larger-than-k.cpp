class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=INT_MIN;
        int count=0;
        for(int top=0;top<m;top++){
            vector<int>colSum(n,0);
            for(int bottom=top;bottom<m;bottom++){
                for(int c=0;c<n;c++){
                    colSum[c]+=matrix[bottom][c];
                }
                for(int i=0;i<n;i++){
                    int sum=0;  //reset sum for each starting point
                    for(int j=i;j<n;j++){
                        sum+=colSum[j];
                        if(sum<=k) maxi=max(maxi,sum); 
                    }
                }
            }
        }
        return maxi;
    }
};