class Solution {
public:
    int window(vector<int>&nums,int k){
        unordered_map<int,int>m;
        int i=0,j=0,count=0;
        while(j<nums.size()){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return window(nums,k)-window(nums,k-1);
    }
};