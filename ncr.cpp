#include<iostream>
using namespace std;
int ncr(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int main(){
    int n=5,r=3;
    cout<<ncr(n,r);
    return 0;
}