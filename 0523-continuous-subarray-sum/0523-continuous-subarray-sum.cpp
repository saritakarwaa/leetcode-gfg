class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // int i=0;
        // int j=0;
        // int sum=0;
        // while(j<nums.size()){
        //     sum+=nums[j];
        //     if(sum<k) {
        //         i++;
        //     }
        //     if(sum%k==0){
        //         return true;
        //         sum-=nums[i];
        //     }
        //     j++;
        // }
        // return false;
        unordered_map<int,int>m;
        int sum=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainder=sum%k;
            if(m.count(remainder)) {
                if(i-m[remainder]>=2) return true;
            }
            else m[remainder]=i;
        }
        return false;
    }
};