class Solution {
public:
    void solve(vector<int>&res,vector<vector<int>>&v,int n,int k,int index){
        if(res.size()==k){
            v.push_back(res);
            return;
        }
        for(int i=index;i<=n;i++){
            res.push_back(i);
            solve(res,v,n,k,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>v;
        vector<int>res;
        solve(res,v,n,k,1);
        return v;
    }
};