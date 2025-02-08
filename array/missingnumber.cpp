//1.using hashtable
//2. using currentsum
//3.using xor


//Given an array arr[] of size n-1 with integers in the range of [1, n], the task is to find the missing number from the first n integers.
#include<bits/stdc++.h>
using namespace std;
int missing(vector<int>&arr,int n){
    int x1=0,x2=0;
    for(int i=0;i<n;i++){
        x2^=arr[i];
    }
    for(int i=1;i<=n+1;i++){
        x1^=i;
    }
    return x1^x2;
}
int main(){
    int n;
    cout << "N:" << endl;
    cin >> n;
    
    vector<int> arr(n);  // Initialize the vector with size n
    
    for (int i = 0; i < n; i++) {
        cout << "Enter elements:" << endl;
        cin >> arr[i];
    }
    
    cout << "Missing number: " << missing(arr, n) << endl;
    
    return 0;
}

//the approach is based on the idea that XOR of a number with itself is 0, and XOR of a number with 0 is the number itself. This means that if we find XOR of first N natural numbers and then take XOR of each array elements with this, then the resultant will be the missing number.

