#include<bits/stdc++.h>
using namespace std; 

bool isValid(string st){
    if(st.empty() || st.size()>3) return false;
    int num=stoi(st);
    if(num<0 || num>255) return false;
    if (st.size() > 1 && st[0] == '0') return false;
    return true;
}
void solve(string s,int index,vector<string>&ans,vector<string>&temp){
    if(index==s.size() && temp.size()==4){
        ans.push_back(temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3]);
        return;
    }
    for(int i=1;i<=min(3,(int)s.size()-index);i++){
        string part=s.substr(index,i);
        if(isValid(part)){
            temp.push_back(part);
            solve(s,index+i,ans,temp);
            temp.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s){
    vector<string>ans;
    vector<string>temp;
    solve(s,0,ans,temp);
    return ans;
}