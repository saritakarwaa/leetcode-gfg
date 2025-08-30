class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;//denotes 0
        int j=0;//denotes 1
        int k=nums.size()-1; //denotes 2
        while(j<=k){
            if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }
            else if(nums[j]==1){
                j++;
            }
            else if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};