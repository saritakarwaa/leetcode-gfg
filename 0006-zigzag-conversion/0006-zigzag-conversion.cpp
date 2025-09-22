class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>res(numRows);
        int i=0;
        while(i<s.size()){
            for(int idx=0;idx<numRows && i<s.size();idx++) res[idx]+=s[i++];
            for(int idx=numRows-2;idx>0 && i<s.size();idx--) res[idx]+=s[i++];
        }
        string ans="";
        for(int j=0;j<res.size();j++){
            ans+=res[j];
        }
        return ans;
    }
};