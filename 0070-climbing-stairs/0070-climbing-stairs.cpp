class Solution {
public:
    int memo(int n, vector<int>& t){
        if(n==0) return 1;
        if(n<0) return 0;
        if(t[n]!=-1) return t[n];
        return t[n]=memo(n-1,t) + memo(n-2,t);
    }
    int climbStairs(int n) {
        vector<int> t(n+1,-1);
        return memo(n,t);
    }
};