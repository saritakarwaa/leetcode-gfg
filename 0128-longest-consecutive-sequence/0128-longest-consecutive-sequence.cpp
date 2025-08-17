class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        // unordered_set<int>s;
        // for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        // int maxi=1;
        // for(int num:s){
        //     if(!s.count(num-1)){
        //         int count=1;
        //         int curr=num;
        //         while(s.count(curr+1)){
        //             curr++;
        //             count++;
        //         }
        //         maxi=max(maxi,count);
        //     }
        // }
        // return maxi;

        sort(nums.begin(),nums.end());
        int ans=1,cnt=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev+1) cnt++;
            else if(nums[i]!=prev) cnt=1;
            prev=nums[i];
            ans=max(ans,cnt);
        }
        return ans;
    }
};