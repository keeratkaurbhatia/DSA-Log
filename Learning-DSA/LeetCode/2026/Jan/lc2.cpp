class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<long long>> rowPS(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> colPS(m + 1, vector<long long>(n, 0));
        vector<vector<long long>> diag1PS(m, vector<long long>(n, 0));  
        vector<vector<long long>> diag2PS(m, vector<long long>(n, 0)); 

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPS[i][j + 1] = rowPS[i][j] + grid[i][j];
            }
        }

        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colPS[i + 1][j] = colPS[i][j] + grid[i][j];
            }
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag1PS[i][j] = grid[i][j];
                if (i > 0 && j > 0)
                    diag1PS[i][j] += diag1PS[i - 1][j - 1];
            }
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                diag2PS[i][j] = grid[i][j];
                if (i > 0 && j + 1 < n)
                    diag2PS[i][j] += diag2PS[i - 1][j + 1];
            }
        }

        
        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    long long target = rowPS[i][j + k] - rowPS[i][j];
                    bool ok = true;

                    
                    for (int r = i; r < i + k && ok; r++) {
                        if (rowPS[r][j + k] - rowPS[r][j] != target)
                            ok = false;
                    }

                    
                    for (int c = j; c < j + k && ok; c++) {
                        if (colPS[i + k][c] - colPS[i][c] != target)
                            ok = false;
                    }

                    
                    long long d1 = diag1PS[i + k - 1][j + k - 1];
                    if (i > 0 && j > 0)
                        d1 -= diag1PS[i - 1][j - 1];

                    
                    long long d2 = diag2PS[i + k - 1][j];
                    if (i > 0 && j + k < n)
                        d2 -= diag2PS[i - 1][j + k];

                    if (d1 != target || d2 != target)
                        ok = false;

                    if (ok)
                        return k;
                }
            }
        }

        return 1;
    }
};
