class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedTasks;
        for(int i=0;i<n;i++){
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());
        vector<int>res;
        long long currTime=0;
        int idx=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minh;
        while(idx<n || !minh.empty()){
            if(minh.empty() && currTime<sortedTasks[idx][0]) currTime=sortedTasks[idx][0];
            while(idx<n && sortedTasks[idx][0]<=currTime){
                minh.push({sortedTasks[idx][1],sortedTasks[idx][2]});
                idx++;
            }
            pair<int,int>currTask=minh.top();
            minh.pop();
            currTime+=currTask.first;
            res.push_back(currTask.second);
        }
        return res;
    }
};