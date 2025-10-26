class Solution {
public:
    vector<int>arr;
    int n;
    Solution(vector<int>& nums) {
        arr=nums;
        n=arr.size();
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int>shuffle=arr;
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);  // Pick a random index from 0 to i
            swap(shuffle[i], shuffle[j]);  // Swap arr[i] with arr[j]
        }   
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */