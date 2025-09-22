class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi=0,count=0;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        for(auto it: m) maxi=max(maxi,it.second);
        for(auto it: m) {
            if(it.second==maxi) count+=maxi;
        }
        return count;
    }
};