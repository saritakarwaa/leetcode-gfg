class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        long long sum=0;
        long long maximum=0;
        unordered_map<int,int>m;
        while(j<nums.size()){
            sum+=nums[j];
            m[nums[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(m.size()==k)maximum=max(maximum,sum);
                sum-=nums[i];
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                i++;
                j++;
            }
        }
        return maximum;
    }
};

