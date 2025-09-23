class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0,i=0;
        while(i<n){
            char curr=chars[i];
            int count=0;
            while(i<n && chars[i]==curr){ //find count of duplicates
                count++;
                i++;
            }
            chars[index]=curr;
            index++;
            if(count>1){
                string countStr=to_string(count);
                for(char ch:countStr){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};