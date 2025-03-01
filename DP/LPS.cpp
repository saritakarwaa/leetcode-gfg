#include<bits/stdc++.h>
using namespace std;

int lcs(string s,string a, int n,int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==a[j-1]) t[i][j]= 1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][m];
}
int longestPalindromeSubseq(string s) {
    int n=s.size();
    string a = s; 
    reverse(a.begin(), a.end());
    int m=a.size();
    return lcs(s,a,n,m);
}