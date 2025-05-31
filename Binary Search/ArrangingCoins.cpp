#include<bits/stdc++.h>
using namespace std;
int arrangeCoins(int n) {
    long long start=1,end=n,ans=-1;
    while(start<=end){
        long long mid=start+(end-start)/2;
        if(mid*(mid+1)/2<=n){
            ans=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    return ans;
}