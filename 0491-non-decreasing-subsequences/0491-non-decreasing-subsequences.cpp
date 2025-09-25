class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& res, vector<vector<int>>& ans) {
        if (res.size() >= 2) {
            ans.push_back(res);
        }

        unordered_set<int> used; // track duplicates at this recursion level
        for (int i = idx; i < nums.size(); i++) {
            if ((res.empty() || res.back() <= nums[i]) && !used.count(nums[i])) {
                res.push_back(nums[i]);
                solve(i + 1, nums, res, ans);
                res.pop_back();
                used.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> ans;
        solve(0, nums, res, ans);
        return ans;
    }
};
