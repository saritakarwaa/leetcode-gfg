#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string st,int i,int j){
    while(i<j){
        if(st[i]!=st[j]) return false;
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(string s) {
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            // Check if the substrings skipping one character each are palindromes
            return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
        i++;
        j--;
    }
    return true;
}

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.