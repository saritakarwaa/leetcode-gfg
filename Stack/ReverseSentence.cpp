#include<bits/stdc++.h>
using namespace std;
 
// Function to reverse a text without reversing the individual words
// Notice that string is passed by reference
void reverseText(string &str)
{
    // `str[low…high]` forms a word
    int low = 0, high = 0;
 
    // create an empty stack
    stack<string> s;
 
    // scan the text
    for (int i = 0; i < str.length(); i++)
    {
        // if space is found, we found a word
        if (str[i] == ' ')
        {
            // push each word into the stack
            s.push(str.substr(low, high - low + 1));
 
            // reset `low` and `high` for the next word
            low = high = i + 1;
        }
        else {
            high = i;
        }
    }
 
    // push the last word into the stack
    s.push(str.substr(low));
 
    // clear the string
    str.clear();
 
    // construct the string by following the LIFO order
    while (!s.empty())
    {
        str.append(s.top()).append(" ");
        s.pop();
    }
 
    // remove last space
    str.erase(prev(str.end()));
}
 
int main()
{
    string str = "Preparation Interview Technical";
 
    reverseText(str);
    cout << str;
 
    return 0;
}


string reverseWords(string s) {
    stack<string>st;
    string word;
    string result;
    stringstream ss(s);
    while(ss>>word){
        st.push(word);
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
        if(!st.empty()) result+=" ";
    }
    return result;
}