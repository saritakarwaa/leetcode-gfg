//LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int i=0,j=0,maxi=0;
        unordered_map<char,int>m;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size()==j-i+1) maxi=max(maxi,j-i+1);
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
}