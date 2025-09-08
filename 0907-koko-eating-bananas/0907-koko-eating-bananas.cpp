class Solution {
public:
    bool check(int mid,int h,vector<int>&piles){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]+mid-1)/mid;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(mid,h,piles)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};