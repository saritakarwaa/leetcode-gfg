#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr, int n) {
    int currentsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++) {
        currentsum += arr[i];
        maxsum = max(maxsum, currentsum);
        if (currentsum < 0) currentsum = 0;
    }
    return maxsum;
}

int main() {
    int n;
    cout << "N:" << endl;
    cin >> n;
    
    vector<int> arr(n);  // Initialize the vector with size n
    
    for (int i = 0; i < n; i++) {
        cout << "Enter elements:" << endl;
        cin >> arr[i];
    }
    
    cout << "Maximum subarray sum: " << kadane(arr, n) << endl;
    
    return 0;
}
