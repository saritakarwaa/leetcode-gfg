class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v;
        int top = 0, down = m-1, left = 0, right = n-1;

        while(top <= down && left <= right) {
            // left to right
            for(int i = left; i <= right; i++) v.push_back(matrix[top][i]);
            top++;

            // top to down
            for(int i = top; i <= down; i++) v.push_back(matrix[i][right]);
            right--;

            // right to left
            if(top <= down) {
                for(int i = right; i >= left; i--) v.push_back(matrix[down][i]);
                down--;
            }

            // down to top
            if(left <= right) {
                for(int i = down; i >= top; i--) v.push_back(matrix[i][left]);
                left++;
            }
        }

        return v;
    }
};
