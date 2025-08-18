class Solution {
public:
    int first(vector<int>&nums,int target){
        int i=0,j=nums.size()-1;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(target==nums[mid]){
                ans=mid;
                j=mid-1;
            }
            else if(target<nums[mid])  j=mid-1;
            else i=mid+1;
        }
        return ans;
    }
    int second(vector<int>&nums,int target){
        int i=0,j=nums.size()-1;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(target==nums[mid]){
                ans=mid;
                i=mid+1;
            }
            else if(target<nums[mid])  j=mid-1;
            else i=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
    //    int f=-1,l=-1;
    //    for(int i=0;i<nums.size();++i){
    //     if(nums[i]==target){
    //         if(f==-1){
    //             f=i;
    //         }
    //         l=i;
    //     }
    //    }
    //    return {f,l};
        int a=first(nums,target);
        int b=second(nums,target);
        return {a,b};
    }

    
};