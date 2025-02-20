#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string x,string y){
    if(x.size()!=y.size()) return false;
    unordered_map<char,int>xFreq, yFreq;
    for(int i=0;i<x.size();i++) xFreq[x[i]]++;
    for(int i=0;i<y.size();i++) yFreq[y[i]]++;
    return xFreq==yFreq;
}