class Solution {
public:
    string reverseWords(string s) {
        // stack<string>st;
        // string word;
        // string result;
        // stringstream ss(s);
        // while(ss>>word){
        //     st.push(word);
        // }
        // while(!st.empty()){
        //     result+=st.top();
        //     st.pop();
        //     if(!st.empty()) result+=" ";
        // }
        // return result;
        reverse(s.begin(),s.end());
        int i=0,l=0,r=0;
        int n=s.size();
        while(i<n){
            while(i<n && s[i]!=' ') s[r++]=s[i++];
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }
};