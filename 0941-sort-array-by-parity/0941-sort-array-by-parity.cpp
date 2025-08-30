class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // vector<int>v;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]%2==0) v.push_back(nums[i]);
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]%2!=0) v.push_back(nums[i]);
        // }
        // return v;
        int i=0,j=nums.size()-1;
        while(i<j){
            while(i<j && nums[i]%2==0) i++;
            while(i<j && nums[j]%2==1) j--;
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};