class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_map<string,int>mp;
        vector<string>res;
        for(int i=0;i<=s.size()-10;i++){
            string sub=s.substr(i,10);
            mp[sub]++;
            if(mp[sub]==2) res.push_back(sub);
        }
        return res;
    }
};