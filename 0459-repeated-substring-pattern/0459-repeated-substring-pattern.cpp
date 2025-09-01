class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int l=n/2;l>=1;l--){
            if(n%l==0){
                int times=n/l;
                string pattern=s.substr(0,l);
                string ss="";
                while(times--) ss+=pattern;
                if(ss==s) return true;
            }
        }
        return false;
    }
};