#include<iostream>
#include<vector>
using namespace std;
void print(int i,vector<int>&ds,int arr[],int n){
    if(i==n){
        for(auto it:ds){
            cout<<it<<"  ";
            
        }
        return;
    }
    ds.push_back(arr[i]);
    print(i+1,ds,arr,n);
    ds.pop_back();
    print(i+1,ds,arr,n);
}
int main(){
    int arr[]={3,1,2};
    vector<int>vs;
    print(0,vs,arr,3);
    return 0;
}