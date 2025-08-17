class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxi=-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int w=j-i;
            int area=h*w;
            maxi=max(maxi,area);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxi;
    }
};