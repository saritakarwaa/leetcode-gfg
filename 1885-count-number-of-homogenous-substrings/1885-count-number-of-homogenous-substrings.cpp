class Solution {
public:
    int countHomogenous(string s) {
        int ans=1;
        int curr=s[0];
        const int mod=1e9+7;
        int count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==curr) count=(count+1)%mod;
            else{
                count=1;
                curr=s[i];
            }
            ans=(ans+count)%mod;
        }
        return ans;
    }
};