#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void subset(int index,vector<int>&nums, vector<vector<int>>&res,int n,vector<int>&temp){
            res.push_back(temp);
            unordered_set<int>m;
            for(int i=index;i<n;i++){
                if(m.find(nums[i])==m.end()){
                    m.insert(nums[i]);
                    temp.push_back(nums[i]);
                    subset(i+1,nums,res,n,temp);
                    temp.pop_back();
                }
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>>res;
            vector<int>temp;
            int n=nums.size();
            subset(0,nums,res,n,temp);
            return res;
        }
};
    