class Solution {
public:
    void solve(vector<vector<int>>&v,vector<int>&res,vector<int>&candidates,int target,int idx){
        if(target==0){
            v.push_back(res);
            return;
        }
        if(target<0 || idx==candidates.size()) return;
        for(int i=idx;i<candidates.size();i++){
            res.push_back(candidates[i]);
            solve(v,res,candidates,target-candidates[i],i);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>res;
        solve(v,res,candidates,target,0);
        return v;
    }
};