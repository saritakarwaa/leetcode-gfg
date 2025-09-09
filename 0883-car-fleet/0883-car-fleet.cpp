class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>v;
        int n=speed.size();
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            v.push_back({position[i],time});
        }
        sort(v.rbegin(),v.rend()); //position descending
        int fleet=0;
        double maxTime=0.0;
        for(int i=0;i<n;i++){
            double currTime=v[i].second;
            if(currTime>maxTime){
                fleet++;
                maxTime=currTime;
            }
        }
        return fleet;
    } 
};