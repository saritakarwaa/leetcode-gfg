class Solution {
public:
    string makeGood(string s) {
        if(s.size()==1) return s;
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(!stk.empty() && tolower(s[i])==tolower(stk.top()) && s[i]!=stk.top()) stk.pop();
            else stk.push(s[i]);
        }
        string res="";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};