class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;
        string res="";
        int cycle=2*numRows-2;
        for(int i=0;i<s.size();i+=cycle){
            res+=s[i];
        }
        for (int row = 1; row < numRows - 1; row++) {      // For each middle row
            for (int i = row; i < s.size(); i += cycle) {  // Start at row position, jump by cycle
                res += s[i];                               // First character in this cycle
                int nextIndex = i + cycle - 2 * row;       // Calculate second character position
                if (nextIndex < s.size()) {
                    res += s[nextIndex];                   // Second character in this cycle
                }
            }
        }
        for(int i=numRows-1;i<s.size();i+=cycle){
            res+=s[i];
        }
        return res;
    }
};