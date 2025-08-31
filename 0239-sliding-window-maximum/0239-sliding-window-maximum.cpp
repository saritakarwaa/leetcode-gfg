class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxh;
        int i=0,j=0;
        vector<int>v;
        while(j<nums.size()){
            maxh.push({nums[j],j});
            int maxTop=maxh.top().first;
            if(j-i+1>k){
                i++;
                while (maxh.top().second < i) maxh.pop();
                maxTop=maxh.top().first;
            }
            if(j-i+1==k) v.push_back(maxTop);
            j++;
        }
        return v;
    }
};