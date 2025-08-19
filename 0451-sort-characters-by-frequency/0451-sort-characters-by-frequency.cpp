class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++) m[s[i]]++;
        priority_queue<pair<int,char>>maxH;
        for(auto it:m){
            maxH.push({it.second,it.first});
        }
        string res="";
        while(!maxH.empty()){
            char c=maxH.top().second;
            int n=maxH.top().first;
            maxH.pop();
            res+=string(n,c);
        }
        return res;
    }
};