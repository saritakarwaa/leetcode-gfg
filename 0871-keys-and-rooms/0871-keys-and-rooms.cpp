class Solution {
public:
    void dfs(vector<vector<int>>&rooms,int source,vector<bool>&visited){
        visited[source]=true;
        for(int node:rooms[source]){
            if(!visited[node]) dfs(rooms,node,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        dfs(rooms,0,visited);
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};