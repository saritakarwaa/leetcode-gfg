class Solution {
public:
   int BS(vector<int>& arr, int start, int end, int element){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(element == arr[mid]) return mid;
            else if(element < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }

    int minIndex(vector<int>& arr){
        int n = arr.size();
        int start = 0, end = n - 1;
        while(start <= end){
            if(arr[start] <= arr[end]) return start; // already sorted
            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return mid;
            else if(arr[mid] >= arr[start]) start = mid + 1;
            else end = mid - 1;
        }
        return 0;
    }

    int search(vector<int>& nums, int target) {
        int index = minIndex(nums);
        int first = BS(nums, 0, index - 1, target);
        int second = BS(nums, index, nums.size() - 1, target);
        return (first != -1) ? first : second;
    }
};