class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0,j=n-1;
        int lsum=0,rsum=0,maxsum=0;
        for(int i=0;i<k;i++) lsum+=cardPoints[i];
        maxsum=max(maxsum,lsum);
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[j];
            maxsum=max(maxsum,lsum+rsum);
            j--;
        }
        return maxsum;
    }
};