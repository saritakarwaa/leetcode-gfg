class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>v;
        for(int i=0;i<strs.size();i++){
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end()); //anagrams,when sorted,will be identical
            mp[sorted].push_back(strs[i]);
        }
        for(auto it:mp){
            v.push_back(it.second);
        }
        return v;
    }
};