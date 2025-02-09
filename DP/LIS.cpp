#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int t[2501][2501];
        int solve(vector<int>&nums,vector<int>&v,int n,int m){
            for(int i=0;i<n+1;i++){
                for(int j=0;j<m+1;j++){
                    if(i==0 || j==0) t[i][j]=0;
                }
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<m+1;j++){
                    if(nums[i-1]==v[j-1]) t[i][j]= 1+t[i-1][j-1];
                    else t[i][j]=max(t[i-1][j], t[i][j-1]);
                }
            }
            return t[n][m];
        }
        int lengthOfLIS(vector<int>& nums) {
            memset(t,-1, sizeof(t));
            int n=nums.size();
            set<int>st(nums.begin(),nums.end());
            vector<int>v(st.begin(),st.end());
            int m=v.size();
            return solve(nums,v,n,m);
        }
};