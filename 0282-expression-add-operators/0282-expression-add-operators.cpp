class Solution {
public:
    vector<string> ans;

    void backtrack(string &num, int target, int pos, long calc, long tail, string path) {
        if (pos == num.size()) {
            if (calc == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); i++) {
            // prevent numbers with leading zeros
            if (i != pos && num[pos] == '0') break;

            string curStr = num.substr(pos, i - pos + 1);
            long cur = stol(curStr);

            if (pos == 0) {
                // first number, just set path
                backtrack(num, target, i + 1, cur, cur, curStr);
            } else {
                // plus
                backtrack(num, target, i + 1, calc + cur, cur, path + "+" + curStr);

                // minus
                backtrack(num, target, i + 1, calc - cur, -cur, path + "-" + curStr);

                // multiply (need to adjust previous tail)
                backtrack(num, target, i + 1, calc - tail + tail * cur, tail * cur, path + "*" + curStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return ans;
    }
};
