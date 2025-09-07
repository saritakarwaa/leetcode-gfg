class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v;
        for(int i=1;i<=n/2;i++){
            v.push_back(i);
            v.push_back(-i);
        }
        if(v.size()!=n) v.push_back(0);
        return v;
    }
};