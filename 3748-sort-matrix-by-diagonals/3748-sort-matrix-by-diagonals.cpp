class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>mp;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            } 
        }
        for(auto &it:mp){
            int key=it.first;
            vector<int>&v=it.second;
            if(key>=0) sort(v.rbegin(),v.rend());
            else sort(v.begin(),v.end());
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=mp[i-j].front();
                mp[i-j].erase(mp[i-j].begin());
            }
        }
        return grid;
    }
};