class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // vector<int>v(nums.size(),0);
        // for(int i=0;i<nums.size();i++){
        //     int count=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[i]>nums[j]) count++;
        //     }
        //     v[i]=count;
        // }
        // return v;
        vector<int>arr=nums;
        sort(arr.begin(),arr.end()); //num,index of first occurence
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])==mp.end()) mp[arr[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=mp[nums[i]];
        }
        return nums;
    }
};