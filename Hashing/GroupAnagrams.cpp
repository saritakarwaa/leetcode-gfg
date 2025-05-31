#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>v;
    unordered_map<string,vector<string>>m;
    for(int i=0;i<strs.size();i++){
        string sorted=strs[i];
        sort(sorted.begin(),sorted.end());
        m[sorted].push_back(strs[i]);
    }
    for(auto it:m){
        v.push_back(it.second);
    }
    return v;
}