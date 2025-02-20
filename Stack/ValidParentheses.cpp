#include<bits/stdc++.h>
using namespace std;

    bool mapping(char a, char b){
        return (a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']' );
    }
    bool isValid(string s){
        stack<int>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                else if(mapping(s[i],stk.top()==false)) return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }



// Function to check if the given expression is balanced or not
bool isBalanced(string exp)
{
    // base case: length of the expression must be even
    if (exp.length() & 1) {
        return false;
    }
 
    // take an empty stack of characters
    stack<char> stack;
 
    // traverse the input expression
    for (char ch: exp)
    {
        // if the current character in the expression is an opening brace,
        // push the corresponding closing brace into the stack.
        if (ch == '(') {
            stack.push(')');
        }
        else if (ch == '{') {
            stack.push('}');
        }
        else if (ch == '[') {
            stack.push(']');
        }
 
        // check if the current character is the same as the last inserted
        // character on the stack
        else if (!stack.empty() && stack.top() == ch) {
            stack.pop();
        }
 
        // return false if the stack is empty or
        // if the popped character is not an opening brace
        else {
            return false;
        }
    }
 
    // the expression is balanced only when the stack is empty at this point
    return stack.empty();
}