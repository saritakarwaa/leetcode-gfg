#include<iostream>
using namespace std;
int reverse(int n){
    int reversed=0,remainder;
    while(n){
        remainder=n%10;
        reversed=reversed*10+remainder;
        n/=10;
    }
    return reversed;
}
int main(){
    int n=123;
    cout<<reverse(n);
    return 0;
}