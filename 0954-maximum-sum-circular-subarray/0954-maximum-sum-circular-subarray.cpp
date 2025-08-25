class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
    int minSubArray(vector<int>& nums) {
        int sum=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mini=min(mini,sum);
            if(sum>0) sum=0;
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int minSum=minSubArray(nums);
        int maxSum=maxSubArray(nums);
        int circularSum=sum-minSum;
        if(maxSum>0) return max(maxSum,circularSum);
        return maxSum;
    }
};