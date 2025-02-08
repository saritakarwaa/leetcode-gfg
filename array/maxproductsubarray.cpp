#include<bits/stdc++.h>
using namespace std;
int product(vector<int>&arr,int n){
    int prefix=1;
    int suffix=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix*=arr[i];
        suffix*=arr[n-i-1];
        maxi=max({maxi,suffix,prefix});
    }
    return maxi;
}
int main(){
    int n;
    cout<<"N:"<<endl;
    cin>>n;
    vector<int>arr(n);
     for (int i = 0; i < n; i++) {
        cout << "Enter elements:" << endl;
        cin >> arr[i];
    }
    cout<<product(arr,n);
    return 0;
}