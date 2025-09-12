class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0){
            return x;
        }
        long long first=1, last=x;
        long long ans=0;
        while(first<=last){
            long long mid=first+ (last-first)/2;
            if(mid*mid==x) return mid;
            if(mid*mid<x){
                ans=mid;
                first=mid+1;
            }
            else{
                last=mid-1;
            } 
        }
        return ans;
    }
};