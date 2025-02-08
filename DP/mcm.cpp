#include<bits/stdc++.h>
using namespace std;
// Matrix Ai has dimension arr[i-1] x arr[i]
int matrixMultiplication(vector<int>&arr,int i,int j){
    if(i>=j) return 0;
    int res=INT_MAX;
    // Place the first bracket at different
    // positions or k and for every placed
    // first bracket, recursively compute
    // minimum cost for remaining brackets
    // (or subproblems)
    for(int k=i;k<=j-1;k++){
        int temp=matrixMultiplication(arr,i,k)+matrixMultiplication(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        res=min(res,temp);
    }
    return res;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 3};
    int n=arr.size();
    cout << matrixMultiplication(arr,1,n-1);
    return 0;
}