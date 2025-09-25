class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')') stk.push(s[i]);
            else{
                string str="";
                while(!stk.empty() && stk.top()!='('){
                    str+=stk.top();
                    stk.pop();
                }
                if(!stk.empty()) stk.pop(); //remove (
                for(int j=0;j<str.size();j++) stk.push(str[j]);
            }
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