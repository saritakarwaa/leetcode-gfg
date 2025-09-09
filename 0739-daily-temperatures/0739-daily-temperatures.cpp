class Solution {
public:
    //next greater to the right
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        vector<int>v;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            if(s.empty()) v.push_back(0);
            else if(!s.empty() && s.top().first>temperatures[i]) v.push_back(s.top().second-i);
            else if(!s.empty() && s.top().first<=temperatures[i]){
                while(!s.empty() && s.top().first<=temperatures[i]) s.pop();
                if(s.empty()) v.push_back(0);
                else v.push_back(s.top().second-i);
            }
            s.push({temperatures[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
