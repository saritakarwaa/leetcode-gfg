#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int m,int n){
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s1[i-1]==s2[j-1]) t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[m][n];
}
int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1, s2,6,7) << endl;
    return 0;
}

int recursion(string s1,string s2,int m,int n){
    if(n==0 || m==0) return 0;
    if(s1[m-1]==s2[n-1]){
        return 1+recursion(s1,s2,m-1,n-1);  //include this character in lcs and recur for remaining substrings
    }
    else return max(recursion(s1,s2,m-1,n),recursion(s1,s2,m,n-1)); //either exclude the last character of s1 or s2
}

int memo(string s1,string s2,int m,int n){
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));


    if(n==0 || m==0) return 0;
    if(t[m][n]!=-1) return t[m][n];
    if(s1[m-1]==s2[n-1]){
        return t[m][n]=1+recursion(s1,s2,m-1,n-1); 
    }
    else return t[m][n]=max(recursion(s1,s2,m-1,n),recursion(s1,s2,m,n-1));
}

