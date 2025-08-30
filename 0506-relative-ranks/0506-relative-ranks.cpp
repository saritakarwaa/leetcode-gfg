class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // vector<pair<int,int>>v;
        int n=score.size();
        // vector<string>res(n);
        // for(int i=0;i<n;i++) v.push_back({score[i],i});
        // sort(v.rbegin(),v.rend());
        // for(int i=0;i<n;i++){
        //     if(i==0) res[v[i].second]="Gold Medal";
        //     else if(i==1) res[v[i].second]="Silver Medal";
        //     else if(i==2) res[v[i].second]="Bronze Medal";
        //     else res[v[i].second]=to_string(i+1);
        // }
        priority_queue<pair<int,int>>maxh;
        for(int i=0;i<n;i++) maxh.push({score[i],i});
        int rank=1;
        vector<string>result(n);
        while(!maxh.empty()){
            auto [val,idx]=maxh.top();
            maxh.pop();
            if (rank == 1) result[idx] = "Gold Medal";
            else if (rank == 2) result[idx] = "Silver Medal";
            else if (rank == 3) result[idx] = "Bronze Medal";
            else result[idx] = to_string(rank);
            rank++;
        }
        return result;
    }
};