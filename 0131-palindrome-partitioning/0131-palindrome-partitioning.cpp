class Solution {
public:
    bool isPalindrome(string pal){
        int i=0,j=pal.size()-1;
        while(i<j){
            if(pal[i]!=pal[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,vector<vector<string>>&ans,vector<string>temp,int idx){
        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }
        string pal;
        for(int i=idx;i<s.size();i++){
            pal+=s[i];
            if(isPalindrome(pal)){
                temp.push_back(pal);
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,ans,temp,0);
        return ans;
    }
};