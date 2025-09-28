class Solution {
public:
    vector<int>parent;
    bool isSimilar(string a,string b){
        int diff=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff++;
        }
        return diff==0 || diff==2;
    }
    int find(int i){
        if(i==parent[i]) return i;
        return find(parent[i]);
    }
    void Union(int x,int y){
        int xParent=find(x);
        int yParent=find(y);
        if(xParent!=yParent) parent[xParent]=yParent;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int groupCnt=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j]) && find(i)!=find(j)){
                    Union(i,j);
                    groupCnt--;
                }
            }
        }
        return groupCnt;
    }
};