class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(vector<int>edge: edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>visited(n,false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(auto &v:mp[node]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        return false;
    }
};