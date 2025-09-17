class Solution {
public:
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    vector<int> getLPS(string &s){
        int n=s.size();
        vector<int>lps(n);
        lps[0]=0;
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }
        }
        return lps;
    }
    bool isMatching(string &a,string &b,vector<int>&lps){
        int i=0,j=0;
        while(j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(i==0) j++;
                else i=lps[i-1];
            }
            if(i==a.size()) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<string>v;
        int n=words.size();
        for(int i=0;i<n;i++){
            vector<int>lps=getLPS(words[i]);
            for(int j=i+1;j<n;j++){
                if(words[j].size()>words[i].size() && isMatching(words[i],words[j],lps)){
                    v.push_back(words[i]);
                    break;
                }
            }
        }
        return v;
    }
};