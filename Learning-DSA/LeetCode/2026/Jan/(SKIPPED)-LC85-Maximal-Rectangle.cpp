class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0); // height of consecutive ones in each column
        vector<int> left(m, 0);    // leftmost boundary for rectangle ending at this row
        vector<int> right(m, m);   // rightmost boundary for rectangle ending at this row
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int curLeft = 0, curRight = m;

            // update heights
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            // update left boundaries
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            // update right boundaries
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') right[j] = min(right[j], curRight);
                else {
                    right[j] = m;
                    curRight = j;
                }
            }

            // compute max area for this row
            for (int j = 0; j < m; j++) {
                maxArea = max(maxArea, heights[j] * (right[j] - left[j]));
            }
        }

        return maxArea;
    }
};
