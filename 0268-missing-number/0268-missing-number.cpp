class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0,xorRange=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        for(int i=0;i<=nums.size();i++){
            xorRange^=i;
        }
        return x^xorRange;
    }
};