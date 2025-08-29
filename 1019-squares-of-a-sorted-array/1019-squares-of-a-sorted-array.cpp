class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int i=0,j=n-1;
        int k=n-1;
        while(k>=0){
            int a=nums[i]*nums[i];
            int b=nums[j]*nums[j];
            if(a>b){
                res[k]=a;
                i++;
            }
            else{
                res[k]=b;
                j--;
            }
            k--;
        }
        return res;
    }
};