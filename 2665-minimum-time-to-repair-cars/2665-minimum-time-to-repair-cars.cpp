class Solution {
public:
    bool check(int cars,long long mid,vector<int>&ranks){
        long long carsFixed=0;
        for(int i=0;i<ranks.size();i++){
            carsFixed+=sqrt(mid/ranks[i]);
            if (carsFixed >= cars) return true;
        }
        return carsFixed>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long start=1;
        long long end=1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans=-1;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(check(cars,mid,ranks)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};