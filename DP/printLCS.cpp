#include<bits/stdc++.h>
using namespace std;
string printlcs(string a, string b,int n, int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]==b[j-1]) t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    string s="";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(b[i-1]);
            i--;
            j--;
        }
        else if(t[i][j-1]>t[i-1][j]) j--;
        else i--;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string a="abcdgh";
    string b="abedfhr";
    int n=a.size();
    int m=b.size();
    cout<<printlcs(a,b,n,m);
    return 0;
}