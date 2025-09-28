class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&res,vector<int>temp,int source,int target){
        temp.push_back(source);
        if(source==target){
            res.push_back(temp);
            return;
        }
        for(int node:graph[source]){
            dfs(graph,res,temp,node,target);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>temp;
        int source=0;
        int target=graph.size()-1;
        dfs(graph,res,temp,source,target);
        return res;
    }
};