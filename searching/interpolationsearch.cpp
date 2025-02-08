//improvement over binary search best used for "uniformly" distributed daa
//"guesses" where a value might be based on calculated probe results 
//if probe is incorrect, search area is narrowed, and a new probe is calculated
//average case: O(log log n)
//worst case: O(n) (values increase exponentially)




#include<bits/stdc++.h>
using namespace std;
int interpolation(vector<int>&arr, int target){
    int high=arr.size()-1;
    int low=0;
    while(target>=arr[low] && target<=arr[high] && low<=high){
        int probe=low+ (high-low)*(target-arr[low])/ 
                            (arr[high]-arr[low]);
        cout<<"Probe:"<<probe<<endl;
        if(arr[probe]==target){
            return probe;
        }
        else if(arr[probe]<target){
            low=probe+1;
        }
        else high=probe-1;
    }
    return -1;
}

int main(){
    vector<int>arr={1,2,4,8,16,32,64,128,256,512,1024};
    int index=interpolation(arr,256);
    if(index!=-1){
        cout<<"Element found at: "<<index;
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}

