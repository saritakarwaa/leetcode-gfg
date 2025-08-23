class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi,abs(nums[i-1]-nums[i]));
        }
        return maxi;
    }
};