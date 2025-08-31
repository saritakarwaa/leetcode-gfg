class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0;
        int ans=0;
        priority_queue<pair<int,int>>maxh;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minh;
        while(j<nums.size()){
            maxh.push({nums[j],j});
            minh.push({nums[j],j});
            int maxTop=maxh.top().first;
            int minTop=minh.top().first;
            while(maxTop-minTop>limit){
                i++;
                while (maxh.top().second < i) maxh.pop();
                while (minh.top().second < i) minh.pop();
                maxTop = maxh.top().first;
                minTop = minh.top().first;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};