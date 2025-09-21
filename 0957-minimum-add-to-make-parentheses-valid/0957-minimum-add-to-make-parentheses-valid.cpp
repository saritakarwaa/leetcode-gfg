class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int right=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stk.push(s[i]);
            else{
                if(!stk.empty()) stk.pop();
                else right++;
            }
        }
        int left=stk.size();
        return left+right;
    }
};