class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&t){
        if(i>j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int mn=INT_MIN;
        for(int k=i;k<=j;k++){
            int temp=solve(nums,i,k-1,t)+solve(nums,k+1,j,t)+nums[i-1]*nums[k]*nums[j+1];
            mn=max(temp,mn);
        }
        return t[i][j]=mn;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        int ans=solve(nums,1,n,t);
        return ans;
    }
};