#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
            unordered_map<int,int>m;
            vector<int>v;
            for(int i=0;i<nums.size();i++) m[nums[i]]++;
            for(auto i=m.begin();i!=m.end();i++){
                minh.push({i->second,i->first});
                if(minh.size()>k) minh.pop();
            }
            while(minh.size()){
                v.push_back(minh.top().second);
                minh.pop();
            }
            return v;
        }
    };
    