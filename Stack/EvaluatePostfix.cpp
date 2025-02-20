#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isSymbol(char ch){
            return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
        }
        int evalRPN(vector<string>& tokens) {
            stack<int>s;
            int ans=0;
            for(int i=0;i<tokens.size();i++){
                if(tokens[i].size() == 1 && isSymbol(tokens[i][0])){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    if(tokens[i][0]=='+') s.push(a+b);
                    if(tokens[i][0]=='-') s.push(b-a);
                    if(tokens[i][0]=='*') s.push(a*b);
                    if(tokens[i][0]=='/') s.push(b/a);
                }
                else s.push(stoi(tokens[i]));
            }
            return s.top();
        }
    };