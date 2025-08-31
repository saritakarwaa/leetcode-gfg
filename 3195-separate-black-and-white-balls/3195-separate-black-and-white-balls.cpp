class Solution {
public:
    long long minimumSteps(string s) {
        int i=0,j=s.size()-1;
        long long count=0;
        while(i<j){
            if(s[j]=='1') j--;
            else if(s[i]!=s[j]){
                swap(s[i],s[j]);
                count+=(j-i);
                j--;
                i++;
            }
            else i++;
        }
        return count;
    }
};