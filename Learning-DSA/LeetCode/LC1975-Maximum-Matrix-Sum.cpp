class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        //2x2 window any 2 places = max sum is all pos
        // but if only one, then no -1 multiplication results in max
        //in ex 2 if window scanning it should select 2,3 -2,-3 window tp get the answer.
        //any 2 adjacent -1 multipliocation. if any even number, they can be reached to make all pos
        //basically path can exist bw 2 negatives, can be reached any which way by -1 multiplication
        //if odd elements,least (mod)-> let it be negative. rest make it positive.
        //0 causing drainage in the odd case, so helps.
        long long posSum = 0;
        long long negSum = 0;
        int negCount = 0;
        int leastMod = INT_MAX;
        int zeroCount = 0;
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if (matrix[i][j]>0)
                {
                    posSum += matrix[i][j];
                }
                else if (matrix[i][j]==0)
                {
                    zeroCount ++;
                }
                else
                {
                    negSum += matrix[i][j];
                    negCount ++;
                }
                if (abs(matrix[i][j])<leastMod)
                {
                    leastMod = abs(matrix[i][j]);
                }
            }
        }
        if (negCount%2==0 || zeroCount)
        {
            return posSum - negSum;
        }
        return posSum - negSum - 2 * leastMod;
    }
};
