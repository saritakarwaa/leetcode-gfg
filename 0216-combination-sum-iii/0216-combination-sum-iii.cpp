class Solution {
public:
    void solve(int idx,int k,int n,vector<vector<int>>&ans,vector<int>&res){
        if(res.size()==k && n==0){
            ans.push_back(res);
            return;
        }
        for(int i=idx;i<=9;i++){
            if(i>n) break;
            res.push_back(i);
            solve(i+1,k,n-i,ans,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(1,k,n,ans,res);
        return ans;
    }
};