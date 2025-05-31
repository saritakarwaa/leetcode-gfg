#include<bits/stdc++.h>
using namespace std; 

class MountainArray {
   public:
        int get(int index);
     int length();
};

int findPeakElement(MountainArray &mountainArr) {
    int start=0;
    int end=mountainArr.length() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            start = mid + 1; // Move right (ascending slope)
        else
            end = mid; // Move left (descending slope or peak found)
    }
    return start; // Peak index
}
int b1(MountainArray &mountainArr,int start,int end,int target){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mountainArr.get(mid)==target) return mid;
        else if(mountainArr.get(mid)>target) end=mid-1;
        else start=mid+1;
    }
    return -1;
}
int b2(MountainArray &mountainArr,int start,int end,int target){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mountainArr.get(mid)==target) return mid;
        else if(mountainArr.get(mid)>target) start=mid+1; //descending order
        else end=mid-1;
    }
    return -1;
}
int findInMountainArray(int target, MountainArray &mountainArr) {
    int peak=findPeakElement(mountainArr);
    int index=b1(mountainArr,0,peak,target);
    if(index!=-1) return index;
    return b2(mountainArr,peak+1,mountainArr.length()-1,target);
}