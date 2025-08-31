class Solution {
public:
    int bits(int n){
        int count=0;
        while(n){
             n = n & (n - 1);
             count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        // for(int i=0;i<=n;i++){
        //     v[i]=bits(i);
        // }
        if(n==0) return v;
        v[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2!=0) v[i]=v[i/2]+1;
            else v[i]=v[i/2];
        }
        return v;
    }
};