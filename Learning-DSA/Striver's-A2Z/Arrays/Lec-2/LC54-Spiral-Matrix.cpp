//O(mxn),O(1):auxi

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        vector<int> ans;

        while (up <= down && left <= right) {
            
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[up][j]);
            }
            up++;

            
            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            
            if (up <= down) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[down][j]);
                }
                down--;
            }

            
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
