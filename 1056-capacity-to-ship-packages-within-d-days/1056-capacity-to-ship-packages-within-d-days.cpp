class Solution {
public:
    int solve(vector<int>& weights, int mid){
        int load=0,days=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                days++;
                load=weights[i];
            }
            else load+=weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int low = *max_element(weights.begin(), weights.end());  // must carry at least the heaviest
        int high = accumulate(weights.begin(), weights.end(), 0); // max possible load (all in one day)
        int ans = high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(weights,mid)<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};


