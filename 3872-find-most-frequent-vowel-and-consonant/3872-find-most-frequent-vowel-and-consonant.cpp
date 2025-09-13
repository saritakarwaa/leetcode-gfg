class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int v=0,c=0;
        for(auto it:mp){
            if(isVowel(it.first)) v=max(v,it.second);
            else c=max(c,it.second);
        }
        return v+c;
    }
};