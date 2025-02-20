#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void subset(int index,vector<int>&nums, vector<vector<int>>&res,int n,vector<int>& temp){
            res.push_back(temp);
            for(int i=index;i<n;i++){
                temp.push_back(nums[i]);
                subset(i+1,nums,res,n,temp);
                temp.pop_back();
            }
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>res;
            vector<int>temp;
            int n=nums.size();
            subset(0,nums,res,n,temp);
            return res;
        }
    };

#include<iostream>
using namespace std;
void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<"";
        return;
    }
    string op1=op;
    string op2=op; 
    op2.push_back(ip[0]);
    ip.erase(ip.begin() +0);
    solve(ip,op1);
    solve(ip,op2);
    return;
    
}
int main(){
    string ip;
    cin>>ip;
    string op=" ";
    solve(ip,op);
    return 0;
}

