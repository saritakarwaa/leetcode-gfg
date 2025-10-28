class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        int count=0;
        // bool one=false;
        // map<char,int>mp;
        // for(int i=0;i<s.size();i++) mp[s[i]]++;
        // for(auto it:mp){
        //     if(it.second%2==0) count+=it.second;
        //     else if(it.second%2!=0){
        //         count+=it.second;
        //         if(!one) one=true;
        //         else count--;
        //     }
        // }
        unordered_set<char>st;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                count+=2;
                st.erase(s[i]);
            }
            else st.insert(s[i]);
        }
        if(!st.empty()) count++;
        return count;
    }
};