class Solution {
public:
    void solve(vector<int>&nums,int index,vector<vector<int>>&v){
        if(index==nums.size()){
            v.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,v);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        solve(nums,0,v);
        return v;
    }
};