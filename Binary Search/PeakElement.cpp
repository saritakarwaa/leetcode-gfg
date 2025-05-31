#include<bits/stdc++.h>
using namespace std;
int PeakElement(vector<int>&arr){
    int i=0,j=arr.size()-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(mid>0 && mid<arr.size()-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        }
        else if(mid==0){
            if(arr[0]>arr[1]) return 0;
            else return 1;
        }
        else if(mid==arr.size()-1){
            if(arr[arr.size()-1]>arr[arr.size()-2]) return arr.size()-1;
            else return arr.size()-2;
        }
        else if(arr[mid-1]>arr[mid]) j=mid-1;
        else i=mid+1;
    }
    return -1;
}