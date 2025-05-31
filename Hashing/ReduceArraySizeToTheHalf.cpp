// You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
// Return the minimum size of the set so that at least half of the integers of the array are removed.

 
#include<bits/stdc++.h>
using namespace std;
int minSetSize(vector<int>& arr) {
    unordered_map<int,int>m;
    int n=arr.size();
    for(int i=0;i<n;i++) m[arr[i]]++;
    priority_queue<int>maxh;
    for(auto it:m) maxh.push(it.second);
    int count=0,sum=0;
    while(!maxh.empty()){
        sum+=maxh.top();
        maxh.pop();
        count++;
        if(sum>=n/2) return count;
    }
    return count;
}