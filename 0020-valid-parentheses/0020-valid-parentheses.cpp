class Solution {
public:
    bool check(char c,char top){
        return (c == ')' && top == '(') ||
               (c == ']' && top == '[') ||
               (c == '}' && top == '{');
    }
    bool isValid(string s) {
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                if(!check(s[i],stk.top())) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};