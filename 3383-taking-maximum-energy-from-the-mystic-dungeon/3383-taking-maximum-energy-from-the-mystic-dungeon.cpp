class Solution {
public:
    int solve(vector<int>&energy,int i,int k,vector<int>&t){
        if(i>=energy.size()) return 0;
        if(t[i]!=INT_MIN) return t[i];
        return t[i]=energy[i]+solve(energy,i+k,k,t);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        // int n=energy.size();
        // vector<int>v(n);
        // for(int i=0;i<n;i++){
        //     if(i+k>=n) v[i]=energy[i];
        //     else v[i]+=energy[i]+energy[i+k];
        // }
        // return *max_element(v.begin(),v.end());
        vector<int>t(energy.size(),INT_MIN);
        int maxi=INT_MIN;
        for(int i=0;i<energy.size();i++){
            maxi=max(maxi,solve(energy,i,k,t));
        }
        return maxi;
    }
};