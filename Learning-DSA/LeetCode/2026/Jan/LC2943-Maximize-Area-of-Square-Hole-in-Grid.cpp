class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 1, maxV = 1;

        
        int cnt = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i-1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxH = max(maxH, cnt);
        }

        
        cnt = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i-1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxV = max(maxV, cnt);
        }

        int side = min(maxH, maxV) + 1;
        return side * side;
    }
};
