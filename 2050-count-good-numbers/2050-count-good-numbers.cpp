class Solution {
public:
    const int MOD=1e9+7;
    int myPow(long long x, long long int n) {
        if(n==0){
            return 1; 
        }
        long long temp = myPow(x, n / 2);
        long long result=(temp*temp)%MOD;
        if(n%2==1) result=(result*x)%MOD;
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)myPow(5,(n+1)/2)*myPow(4,n/2)%MOD;     
    }
};