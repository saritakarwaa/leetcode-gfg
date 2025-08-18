class Solution {
public:
    void solve(vector<int>& nums,int index,vector<vector<int>>&v){
        if(index==nums.size()){
            v.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int i=index;i<nums.size();i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[index],nums[i]);
            solve(nums,index+1,v);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        solve(nums,0,v);
        return v;   
    }
};