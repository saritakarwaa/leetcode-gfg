#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    if(s.size()==0 || s.size()==1) return true;
    int i=0,j=s.size()-1;
    while(i<j){
        if(!isalnum(s[i])){
            i++;
            continue;
        }
        if(!isalnum(s[j])){
            j--;
            continue;
        }
        if(tolower(s[i])!=tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.