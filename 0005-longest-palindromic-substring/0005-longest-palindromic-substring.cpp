class Solution {
public:
    vector<vector<int>> t; // DP table

    bool solve(const string &s, int i, int j) {
        if (i >= j) return true;
        if (t[i][j] != -1) return t[i][j];
        if (s[i] == s[j]) return t[i][j] = solve(s, i + 1, j - 1);
        return t[i][j] = 0; // mark as false
    }

    string longestPalindrome(string s) {
        int n = s.size();
        t.assign(n, vector<int>(n, -1)); // DP table sized exactly n x n

        int sp = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};
