#include<bits/stdc++.h>
using namespace std;
string sortFrequency(string s){
    unordered_map<char,int>mp;
    string op;
    for(int i=0;i<s.size();i++) mp[s[i]]++;
    priority_queue<pair<int,char>>maxh;
    for(auto it=mp.begin();it!=mp.end();it++){
        maxh.push({it->second,it->first});
    }
    while(maxh.size()){
        int frequency=maxh.top().first;
        int element=maxh.top().second;
        op.append(frequency,element);
        maxh.pop();
    }
    return op;
}
int main(){
    string s="tree";
    cout<<sortFrequency(s);
    return 0;
}