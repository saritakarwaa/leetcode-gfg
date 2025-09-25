class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;//player, number of times they lost
        for(int i=0;i<matches.size();i++){
            mp[matches[i][1]]++;
        }
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<matches.size();i++){
            if(mp.find(matches[i][0])==mp.end()) {
                v1.push_back(matches[i][0]);
                mp[matches[i][0]]=2;
            }
            if(mp[matches[i][1]]==1) v2.push_back(matches[i][1]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return {v1,v2};
    }
};