class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0;
        int sum=0,count=0;
        int cntZeroes=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(i<j && (nums[i]==0 || sum>goal)){
                if(nums[i]==0) cntZeroes++;
                else cntZeroes=0;
                sum-=nums[i];
                i++;
            }
            if(sum==goal) count+=1+cntZeroes;
            j++;
        }
        return count;
    }
};